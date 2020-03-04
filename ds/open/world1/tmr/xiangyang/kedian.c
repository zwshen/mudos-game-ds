// Room: /d/xiangyang/kedian.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "襄陽客棧");
	set("long", @LONG
這是一家對江湖人士來說很有名氣的客棧。人們到襄陽來
一般都住在這裡，一是便宜，二能聽到江湖上的許多事情。近
年來，襄陽退敵數十次，南來北往的人們經過襄陽更是打尖在
這兒，順便拜訪一下郭靖等俠義之士。
LONG );
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wudunru" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
//	"/clone/board/kedian6_b"->foo();
}
