#include <ansi.h>
void init()
{
	add_action("do_putin","putin");
	add_action("do_getout","getout");
	add_action("do_list","list");
}

int do_putin(string arg)
{
	string name;
	object me,ob,env;
	me=this_player();
	env=this_object();
	if(!me->query("item"))
                return notify_fail("叫巫師幫你把房屋退了吧。\n");
	if(!arg || arg=="") 
                return notify_fail("你身上沒有這樣東西。\n");
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上沒有這樣東西。\n");
        if( ob->query("equipped") )
                return notify_fail("你現在正裝備著。\n");
        if( ob->query_amount()>1)
                return notify_fail("白爛...不是跟你說只能放\"1\"件的東西嗎。\n");

	name=(string)base_name(ob);
	for(int i=1;i<11;i++)
	{
		if(me->query("item/item"+i)=="")
		{
		me->set("item/item"+i,name);
		write("你把"HIC+ob->query("name")+NOR"收到儲藏室裡了\n");
		destruct(ob);
		me->save();
		return 1;
		}
	}
	return 1;
}
int do_getout(string arg)
{
	string path;
	object me,env;
	me=this_player();
	env=this_object();
	if(!me->query("item"))
                return notify_fail("叫巫師幫你把房屋退了吧。\n");
	if(!arg || arg=="")
                return notify_fail("指令 getout <編號>。\n");
	if(!me->query("item/item"+arg)) 
                return notify_fail("儲藏室裡現在沒有這個東西喔。\n");
	if(me->query("item/item"+arg)=="") 
                return notify_fail("儲藏室裡現在沒有這個東西喔。\n");
	path=me->query("item/item"+arg);
	new(path)->move(env);
	write("你千辛萬苦把"HIC+new(path)->query("name")+NOR"從儲藏室裡找了出來。\n");
	me->set("item/item"+arg,"");
	me->save();
	return 1;
}

int do_list()
{
	string path;
	object env,*ob,me;
	me=this_player();
	env=this_object();
	if(!me->query("item"))
                return notify_fail("叫巫師幫你把房屋退了吧。\n");
	write("目前儲藏室裡儲存有\n");
	for(int i=1;i<11;i++)
	{
	if(me->query("item/item"+i)=="") 
	write(i+". 無\n");	
	else{
	path=me->query("item/item"+i);
	write(i+". "+new(path)->query("name")+"\n");
	}
	}
	return 1;
}

