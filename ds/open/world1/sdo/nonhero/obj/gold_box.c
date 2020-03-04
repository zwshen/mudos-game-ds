#include <ansi2.h>
#include <path.h>
inherit ITEM;
void create()
{
        set_name("金箱子", ({"gold box","box"}) );
        set("long", 
"一個金光閃閃的箱子，好像可以打開的樣子。\n"
);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("no_get",1);
	set("no_drop",1);
        set("unit", "個");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
	add_action("open_box","open");
}

int open_box(string str)
{
	object me=this_player();
	object b,room;
	room=load_object(SDO_PAST+"nonhero/grav5");
	
	if(!me) return 0;
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="box" || str=="金箱子")
	{

	message_vision(
	HIR"\n$N正準備打開箱子時，箱子忽然炸開了。\n"NOR
	HIR"\n一團煙霧之中，一隻野獸張牙舞爪的衝了出來！\n"NOR,me);

	b=new(__DIR__"npc/gold_beast.c" );
	b->move(environment(this_object()) );

	destruct(this_object());

	room->set_temp("opened",1);
	return 1;
	}
}