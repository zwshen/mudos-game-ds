inherit ROOM;

void create()
{
	set("short", "山旁森林");
	set("long", @LONG
你站在這兒看到周圍樹的樹上刻有些記號，大概是江湖中的人士前
來山上去尋找有關武功密技之事時所遺留下來的記號，在記號中已長出
長長的一串小草至外。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"psin4.c",
  "south" : __DIR__"psin3.c",
  "east" : __DIR__"psin.c",
    "north" : __DIR__"psin_forest2.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("item_desc", ([
  "記號" : "一個大大的記號。\n\n"
"            ●\n"
"          ◎◎◎\n"
"         ◎ ◎ ◎\n"
"            ◎\n"
"       ●●●●●●\n"
"       ●        ●\n"
"       ●   ○   ●\n"
"       ●        ●\n"
"       ● ○  ○ ●\n"
"       ●        ●\n"
"       ●●●●●●\n"
" 不知道代表著什麼意思 ！\n",
]));

	setup();
	replace_program(ROOM);
}
