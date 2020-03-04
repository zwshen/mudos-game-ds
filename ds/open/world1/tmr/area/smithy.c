// Room: /u/t/tmr/area/smith.c

inherit ROOM;

void create()
{
        set("short", "打鐵鋪");
        set("long", @LONG
這裡是一間打鐵鋪子﹐牆上掛了許多鐵器的半成品跟工具﹐鋪子中間
一個燒著熊熊火燄的火爐映得你在牆上的影子一晃一晃的﹐旁邊還有一個
沈重的大鐵砧﹐鋪子的出口就在南邊。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
 		 "south" : __DIR__"street3.c",
         "east" : "/open/world1/wilfred/newbie/eq_fixroom",
	]));

        set("objects", ([
                __DIR__"npc/smith" : 1,
        ]));
	set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
