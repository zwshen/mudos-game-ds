// Modify with AreaMaker1.0
// Room42.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在一大片的樹林裡。東邊有一條不知道是誰開的小步道，
步道十分的蜿蜒曲折。這裡有一棵很大的老榕樹，似乎已經有千年的
樹齡了。你隱約聽到一陣嗡嗡的聲音，大概是因為最近太勞累而有點
耳鳴吧。
LONG
	);
	set("exits", ([
		"north": __DIR__"room32",
		"east": __DIR__"room43",
		"south": __DIR__"room52",
		"northwest": __DIR__"room31",
	]));

	set("hide_exits", ([
 	]));
	
	set("item_desc",([
        "tree":"你發現榕樹邊有些新剝落的痕跡，似乎是有人爬(climb)上去造成的。\n",
        "老榕樹":"你發現榕樹邊有些新剝落的痕跡，似乎是有人爬(climb)上去造成的。\n",
         ]));
	
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	return notify_fail("當你正要爬樹的時候發現樹幹上留了一張紙條。\n[區域開發中，請見諒!!]\n");
}