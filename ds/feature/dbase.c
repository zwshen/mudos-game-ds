/*
  Name: /feature/dbase.c
  Copyright: DS2
  Last modified by: Alickyuen
  Date: 14/06/05 01:48
  Description: Editing set(), add(), delete() to avoid cheating
*/


//#include <dbase.h>
// #pragma save_binary
#include <ansi.h>

inherit F_TREEMAP;

mapping dbase;
nosave mapping tmp_dbase;

//	The default_ob provides the default values of the dbase. It is set to
//	be master copy of an object.
nosave mixed default_ob;

mixed query_default_object() { return default_ob; }

//void create()
//{
//	seteuid(getuid());
//}

void set_default_object(mixed ob)
{
//	if( geteuid(previous_object()) != ROOT_UID )
//		error("dbase: Only this_object() or object with root euid can set default_ob.\n");
	if( !geteuid() ) seteuid(getuid());
	default_ob = ob;
	ob->add("no_clean_up", 1);
}

mixed set(string prop, mixed data)
{
	// 以下限制等級wizard以上之巫師修改玩家或公開資料 
	if( previous_object() 
		&& file_owner(file_name(previous_object()))
		&& !file_owner(file_name(this_object()))
		&& wiz_level(geteuid(previous_object())) <= 3 
		&& getuid(previous_object()) != ROOT_UID )
	{
		write(BEEP HIR"[Set Error]: 請用 report 指令回報或與Game Master聯絡！\n"NOR);
		log_file("nosave/DBASE","[dbase.c error] "
			+previous_object()->name(1)+"("+geteuid(previous_object())
			+") 試圖修改 "+this_object()->name(1)+"("+geteuid(this_object())+") 的資料:"
            +prop+" !!\n");
		return 0;
	}
      
	if( !mapp(dbase) ) dbase = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( dbase, explode(prop, "/"), data );

	return dbase[prop] = data;
}

varargs mixed query(string prop, int raw)
{
	mixed data;

	if( !mapp(dbase) ) return 0;

	if( undefinedp(dbase[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(dbase, explode(prop, "/"));
	else
		data = dbase[prop];

	if( undefinedp(data) && default_ob )
		data = default_ob->query(prop, 1);

	if( raw ) return data;

	return evaluate( data, this_object() );
}

int delete(string prop)
{
	// 以下限制等級wizard以上之巫師修改玩家或公開資料 
	if( previous_object() 
		&& file_owner(file_name(previous_object()))
		&& !file_owner(file_name(this_object()))
		&& wiz_level(geteuid(previous_object())) <= 3 
		&& getuid(previous_object()) != ROOT_UID )
	{
		write(BEEP HIR"[Set Error]: 請用 report 指令回報或與Game Master聯絡！\n"NOR);
		log_file("nosave/DBASE","[dbase.c error] "
			+previous_object()->name(1)+"("+geteuid(previous_object())
			+") 試圖修改 "+this_object()->name(1)+"("+geteuid(this_object())+") 的資料:"
            +prop+" !!\n");
		return 0;
	}
	
	if( !mapp(dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		return _delete(dbase, explode(prop, "/"));
	else {
		map_delete(dbase, prop);
		return 1;
	}
}

mixed add(string prop, mixed data)
{
	mixed old;

	// 以下限制等級wizard以上之巫師修改玩家或公開資料 
	if( previous_object() 
		&& file_owner(file_name(previous_object()))
		&& !file_owner(file_name(this_object()))
		&& wiz_level(geteuid(previous_object())) <= 3 
		&& getuid(previous_object()) != ROOT_UID )
	{
		write(BEEP HIR"[Set Error]: 請用 report 指令回報或與Game Master聯絡！\n"NOR);
		log_file("nosave/DBASE","[dbase.c error] "
			+previous_object()->name(1)+"("+geteuid(previous_object())
			+") 試圖修改 "+this_object()->name(1)+"("+geteuid(this_object())+") 的資料:"
            +prop+" !!\n");
		return 0;
	}

	if( !mapp(dbase) || !(old = query(prop, 1)) )
		return set(prop, data);

	if( functionp(old) )
		error("dbase: add() - 無法設定函數型態屬性.\n");

	return set(prop, old + data);
}

mapping query_entire_dbase()
{
//	if( (previous_object() != this_object())
//	&&	(geteuid(previous_object()) != ROOT_UID) )
//		error("dbase: query_entire_dbase() - must has root euid or be this_object().\n");

	return dbase;
}

mixed set_temp(string prop, mixed data)
{
	if( !mapp(tmp_dbase) ) tmp_dbase = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( tmp_dbase, explode(prop, "/"), data );

	return tmp_dbase[prop] = data;
}

varargs mixed query_temp(string prop, int raw)
{
	mixed data;

	if( !mapp(tmp_dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		data = _query(tmp_dbase, explode(prop, "/"));
	else
		data = tmp_dbase[prop];

	if( functionp(data) && !raw )
		return (*data)( this_object() );
	else 
		return data;
}

int delete_temp(string prop)
{
	if( !mapp(tmp_dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		return _delete(tmp_dbase, explode(prop, "/"));
	else {
		map_delete(tmp_dbase, prop);
		return 1;
	}
}

mixed add_temp(string prop, mixed data)
{
	mixed old;

	if( !mapp(tmp_dbase) || !(old = query_temp(prop, 1)) )
		return set_temp(prop, data);

	if( functionp(old) )
		error("dbase: add_temp() - 無法設定函數型態屬性.\n");

	return set_temp(prop, old + data);
}

mapping query_entire_temp_dbase()
{
//	if( (previous_object() != this_object())
//	&&	(geteuid(previous_object()) != ROOT_UID) )
//		error("dbase: query_entire_temp_dbase() - must has root euid or be this_object().\n");

	return tmp_dbase;
}

