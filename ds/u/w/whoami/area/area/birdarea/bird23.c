#include <ansi.h>
inherit MOBROOM;
void create()
{
 set("short",HIC"天梟教"NOR"練武場");

 set("long",@LONG 
你來到了天梟教的練武場, 你看見這裡有許多的小徒弟在這
裡練功, 你看看這些小徒弟, 你發現他們不過是剛學成靈翼八步
訣的小新手, 而且武功很差, 還不會天嘯匕法, 所以在這練習。 
LONG
    );
 
 set("exits",(["north":__DIR__"bird25",
               "west":__DIR__"bird20",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",4);    
        set("mob_max",12);
        set("mob_object",({     
            __DIR__"npc/fighter",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}

