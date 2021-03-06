// Room: /u/t/tmr/area/ms1.c

inherit ROOM;

void create()
{
        set("short", "田間小路");
        set("long", @LONG
你正走在一條位於田間的小路，由於正值播種時期，所有的農夫早已
赤足荷鋤地在田裡插秧，一片又一片綠油油的秧苗在微風中盪漾，充滿無
限的生機。從田間小路往東走可通到孟村的東村口。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"ms2",
                "east" : __DIR__"mstart.c",
        "south" : "/open/world1/wilfred/marry/marry_house",
        ]));
        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/farmer.c" : 2,
        ]) );
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

