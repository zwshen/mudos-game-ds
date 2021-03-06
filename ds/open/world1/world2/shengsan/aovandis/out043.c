// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
由於樹木的繁茂，這裡並沒有樹林外面那樣的明亮，有時候可愛的松
鼠會在你眼前飛過。枯黃的樹葉掉落至地上成為這片樹林最好的養分，巨
大的樹根在地上互相纏繞在一起。這裡是奧凡迪斯的郊區。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out044",
	    "west" : __DIR__"out042",
	    "south": __DIR__"out051",
            ]));

	set("outdoors","forest");	// 樹林
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}