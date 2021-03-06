#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIY"千禧之星•鎧"NOR, ({ "armor of millennium star","armor" }) );
	set_weight(12500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件鎧甲非常高級, 看起來金光閃閃, 這不知道是用何種\n"
                           "特殊的物質所構成, 幾乎無法摧毀的堅固性, 可以給穿戴\n"
			   "者相當強大的防護力, 據說這件鎧甲是七域中某一神秘鐵\n"
                           "匠為了慶祝千禧而特地打造的!\n"
                           "改變英文名: re_eng_name, 改變中文名: rename\n"
                           "ps.重新進入遊戲後 name 就會改變了.\n");
		set("unit","件");
	set("value",1);
		set("material","diamond");
		set("needaward",50);
	}
	set("no_give",1);
	set("no_drop",1);
        set("armor_prop/con",2);
	set("armor_prop/int",1);
	set("armor_prop/str",2);
	set("armor_prop/shield",25);
	set("armor_prop/armor",45);
	setup();
}

int query_autoload() { return 1; }

void init()
{
 add_action("do_re_eng_name","re_eng_name");
 add_action("do_rename","rename");
 if( environment(this_object()) == this_player() )
 {
  if( this_player()->query("millennium_armor/cname") ) 
   this_object()->set("name",this_player()->query("millennium_armor/cname") );
  if( this_player()->query("millennium_armor/id") && this_player()->query("millennium_armor/full_id") )
   this_object()->set_name(HIY"千禧之星•鎧"NOR,({ this_player()->query("millennium_armor/full_id") , 
			                           this_player()->query("millennium_armor/id") }) );
  if( this_player()->query("millennium_armor/cname") && 
      this_player()->query("millennium_armor/id") && 
      this_player()->query("millennium_armor/full_id") )
   this_object()->set_name( this_player()->query("millennium_armor/cname") , ({ 
                            this_player()->query("millennium_armor/full_id") , 
          		    this_player()->query("millennium_armor/id") }) );
 }
}

int do_re_eng_name(string arg)
{
	string n_who,id,name;
	object me;
	me = this_player();
	if(!arg || sscanf(arg,"%s as %s %s",n_who,name,id )!=3 )
		return notify_fail("更名格式: re_eng_name <物品> as <英文全名> <英文簡稱>.\n");
	if( !present(n_who,me) )
		return notify_fail("你身上沒有這個東西. \n");
	if( strlen(id) > 10 || strlen(name) > 20 )
		return notify_fail("請把名字取得短一點, 響亮一點.\n");
	message_vision("$N把$n的英文名字改為【"+name+NOR+"("+id+")】\n",me,this_object());
	me->set("millennium_armor/id",id);
	me->set("millennium_armor/full_id",name);
	return 1;
}

int do_rename(string arg)
{
        string n_who,cname,oldname;
	object me;
	me = this_player();
	oldname = this_object()->query("name");
	if(!arg || sscanf(arg,"%s as %s",n_who,cname)!=2 )
		return notify_fail("更名格式: rename <物品> as <中文名稱>.\n");
	if( !present(n_who,me) )
		return notify_fail("你身上沒有這個東西. \n");
	if( strlen(cname) > 24 )
		return notify_fail("請把名字取得短一點, 響量一點.\n");
	arg = replace_string(arg, "$BLK$", BLK);
	cname = replace_string(cname, "$RED$", RED);
	cname = replace_string(cname, "$GRN$", GRN);
	cname = replace_string(cname, "$YEL$", YEL);
	cname = replace_string(cname, "$BLU$", BLU);
	cname = replace_string(cname, "$MAG$", MAG);
	cname = replace_string(cname, "$CYN$", CYN);
	cname = replace_string(cname, "$WHT$", WHT);
	cname = replace_string(cname, "$HIR$", HIR);
	cname = replace_string(cname, "$HIG$", HIG);
	cname = replace_string(cname, "$HIY$", HIY);
	cname = replace_string(cname, "$HIB$", HIB);
	cname = replace_string(cname, "$HIM$", HIM);
	cname = replace_string(cname, "$HIC$", HIC);
	cname = replace_string(cname, "$HIW$", HIW);
	cname = replace_string(cname, "$NOR$", NOR);
	message_vision(HIC"$N"NOR" 大聲宣佈道: 我就在此將我的 "+oldname+NOR+" 更名為 "+cname+NOR+" 吧！\n",me);
        message_vision("$N把"+oldname+NOR+"的中文名字改為【"+cname+NOR+"】\n",me);
        me->set("millennium_armor/cname",cname);
	return 1;
}
