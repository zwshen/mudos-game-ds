#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIR"奇倪骨鐲"NOR ,({ "chini wrists","wrists"}) );
        set("long",@LONG
奇倪的外骨骼形成的護腕,看起來不怎麼好用的樣子.
LONG);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 1);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", -1);
                set("armor_prop/bar", 0);
                set("armor_prop/wit", 0);
	set("armor_type", "wrists");
        setup();
}

void init()
{
/*
        if( userp(environment(this_object()) ) )
        {
                add_action("do_wear", "wear");
                add_action("do_remove", "remove");
        }
*/
}

int do_wear(string arg)
{
        object me;

        me = this_player();

	if( !this_object()->query("equipped") ) {
        if( arg == "wrists" || arg == "chini wrists" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N套上了奇倪骨鐲,剎時間天搖地動,眾神獸的元靈進入$N的體內!\n"NOR);
                me->add_temp("god_armor", 1);
                me->add_temp("wear_wrist",1);
                set("armor_prop/bar", 2);
                set("armor_prop/wit", 2);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                }
                else {
                   if(me->query_temp("wear_wrist") == 0)
                {
                        me->add_temp("god_armor", 1);
                        me->add_temp("wear_wrist",1);
                }
                }
        }
	}
}

int do_remove(string arg)
{
        object me;

        me = this_player();

        if( this_object()->query("equipped") ) {
        if( arg == "wrists" || arg == "chini wrists" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
			this_object()->create();
			present("wo waist", environment(this_object()))->create();
			present("wo cloak", environment(this_object()))->create();
			present("maigu leggings", environment(this_object()))->create();
			present("maigu gloves", environment(this_object()))->create();
			present("chini boots", environment(this_object()))->create();
			delete("wear_msg");
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_wrist",-1);
			me->add_temp("apply/bar", -2);
			me->add_temp("apply/wit", -2);

                }
                else
                {
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_wrist",-1);
                }
	}
        }
}

