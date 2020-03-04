// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "竹易");
	set("long",@LONG 
房名竹易，青竹欹欹，這裡就是許多文人士子最喜歡的房間。當然也
有許多商人故作風雅囉！這裡真的到處都是竹子，一幅墨竹山水，一襲竹
簾，窗外竹枝探入房內。帶有竹子香氣的風不斷吹送，夏天炎熱時這裡仍
然清爽如昔。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "north" : __DIR__"hotel_two",

              ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}