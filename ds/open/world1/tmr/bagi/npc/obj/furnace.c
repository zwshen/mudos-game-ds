#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("丹爐",({"furnace"}) );
	set_weight(15000);
	set("long",@long
一個青銅做的丹爐，多是方士用來練丹的器具，多半都按方位插在地
上(setup)，也可拔起(dispose)。
long
);
         set_max_encumbrance(10000);
         set_max_capacity(50);

	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","個");
		set("value",300);
	}
	setup();
}

void init()
{
	add_action("do_setup","setup");
	add_action("do_dispose","dispose");

}

int do_setup(string arg)
{
	object me,ob;
	string what;
	int flag=0;
	me=this_player();
	ob=this_object();

        if( !arg || sscanf(arg, "furnace on %s", what)!=1 )
		return notify_fail("指令型式：setup furnace on [方位] \n");

	if(ob->query("setup_down") ) 
		return notify_fail("此丹爐已按方位安然插在土裡了。\n");
        switch(what)
        {
         case "east":
         ob->set_name("丹爐["HIG +"艮位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "west":
         ob->set_name("丹爐["HIG +"兌位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "south":
         ob->set_name("丹爐["HIG +"離位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "north":
         ob->set_name("丹爐["HIG +"坎位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "southeast":
         ob->set_name("丹爐["HIG +"巽位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "southwest":
         ob->set_name("丹爐["HIG +"坤位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "northeast":
         ob->set_name("丹爐["HIG +"震位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "northwest":
         ob->set_name("丹爐["HIG +"乾位"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

	 default:
	 flag =0;
	 break;
	}
	if(flag==0) return notify_fail("沒有這種方位\n");

	message_vision("$N在地上挖了個洞穴，把丹爐按照方位擺\好。\n",me,ob);
	ob->move(environment(me) );
	ob->set("no_sac",1);
	ob->set("no_get",1);
	ob->set("setup_down",1);

	return 1;
}

int do_dispose(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();

	if(!ob->query("setup_down") ) return notify_fail("此丹爐並沒有被插在土裡。\n");

	message_vision("$N把擺\在地上的$n拔了出來。\n",me,ob);
	ob->move(environment(me) );
	ob->set("no_sac",0);
	ob->set("no_get",0);
	ob->set("setup_down",0);
	ob->set_name("丹爐",({"furnace"}) );
	return 1;
}

void fire_pill(object ob)
{
	object *inv,ash;
	int i,a,b,p;
	p=ob->query("fire_power");

	inv = all_inventory(this_object() );
	if( sizeof(inv) )
	{
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="mixture" )
		{
		inv[i]->add("fire",p+random(p/2) ); 
		a=inv[i]->query("pill");
		b=inv[i]->query("fire");
		inv[i]->set_name("配方["+chinese_number(b*10/a )+"分火候]",({ "mixture" }) );
		inv[i]->set("pill",a);
		if(b > (a+a/10) )  //超過十分火候，轉成焦灰
		{
			ash=new(__DIR__"ash");
			ash->move(environment(inv[i]) );
			destruct(inv[i]);
		}
		}
	}
}

}
