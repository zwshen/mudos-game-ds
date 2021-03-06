// Room: /d/xiangyang/xinluofang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "新羅坊");
	set("long", @LONG
新羅坊，顧名思義是給新羅人住的地方，不過其實現在新
羅已經被高麗所滅掉，這裡應該叫做高麗坊的。可是大家已經
習慣了，於是便還這麼叫。這裡住著許多高麗商人，也有些高
麗的使臣進東京城路過襄陽，便也住在這裡。這裡的高麗商人
總有很多很好的貨物，大家都喜歡來買，於是這裡就非常的熱
鬧了。
LONG );
	set("exits", ([
		"south" : __DIR__"northroad1",
	]));
	set("objects", ([
		__DIR__"npc/gaoli" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

