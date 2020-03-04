// qianting.c 前廳
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "前廳");
	set("long", @LONG
這里是古墓的前廳，黑黝黝的，你幾乎什么也看不清。全靠大廳
正中間的梁上懸掛著一顆夜明珠，映射出淡淡的黃光。廳柱都是由碩
大的石柱砌成的，上面似乎還寫著一些什麼字(word)，昏暗中似是重
陽手筆。可你不仔細看怎么也看不清楚。
LONG	);
	set("item_desc", ([
		"word": "秋水為神玉為骨 芙蓉如面柳如眉\n"
	]));
	set("exits", ([
		"west"  : __DIR__"mudao02",
//          "east"  : __DIR__"mudao05",
		"south" : __DIR__"mudao04",
		"north" : __DIR__"mudao01",
	]));

	setup();
	replace_program(ROOM);
}

