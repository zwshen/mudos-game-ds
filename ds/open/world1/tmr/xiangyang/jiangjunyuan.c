// Room: /d/xiangyang/jiangjunyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "將軍府大院");
	set("long", @LONG
這裡是將軍府的大院，只見大理石鋪就的地面一塵不染，
兩個衣著光鮮的小丫鬟認真的在擦洗兩邊的欄杆和柱子，不時
有值班的衛士走過來。向裡望去，可以看到將軍府的大堂。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"jiangjungate",
		"north" : __DIR__"jiangjuntang",
	]));
	set("coor/x", -490);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}