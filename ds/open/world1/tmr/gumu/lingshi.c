// Room: /d/gumu/lingshi.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"靈室"NOR);
        set("long", @LONG
只見空空曠曠的一座大廳上并列放著五具石棺。凝神細看，見兩具
石棺棺蓋已密密蓋著，原來是古墓派祖師林朝英和小龍女師傅的安身之
處。另外二具的棺蓋(coffin)卻只推上一半，也不知其中有無尸體。
LONG    );

        set("exits", ([ 
                "out" : __DIR__"shishi5",
        ]));
        
                set("item_desc", ([
                           "coffin" : "厚重的棺蓋\，但似乎可以推的動(push)。\n",
         ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_tui", "push");      
        add_action("do_tang","lie");
}

int do_tui(string arg)
{
        object me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");
        if ( arg =="coffin")
        {
                        message_vision(YEL"$N使勁推開了棺蓋\，石棺內好像可以躺人(lie)。\n"NOR,me);
                me->set_temp("marks/石棺", 1);
                return 1;
        }
        return notify_fail("你要推什麼？\n");
}

int do_tang(string arg)
{
        object me=this_player();       

        if (!me->query_temp("marks/石棺")) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");
        
        if ( arg =="coffin")
        {
                me->delete_temp("marks/石棺");
                me->move(__DIR__"shiguan");
                message_vision(HIY"$N躺進了石棺，棺內已無轉側餘地。\n"NOR,me);
                return 1;
        }
        return notify_fail("你想躺在哪里？\n");
}

