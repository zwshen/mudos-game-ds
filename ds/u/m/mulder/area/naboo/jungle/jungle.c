// Room: /u/m/mulder/area/naboo/jungle/jungle.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"森林小路"NOR);
	set("long", @LONG
這是全Naboo最大的森林，傳說森林盡頭有很多寶藏。但是有很多人進
入那裡，結果走不出來。但是這裡又有另一個說法是，那裡有一些恐怕的怪
物將進入的探險者殺死。之於森林裡藏有什麼東西呢？現在也沒有人可以肯
定答到你。遠處有一個告示(sign)。
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/u/m/mulder/area/naboo/gate3",
  "east" : __DIR__"jungle2",
]));
	set("world", "undefine");
	set("item_desc",([
	"sign":"這裡可以供給玩家SAVE,避免玩家在森林迷路!\n",
	]));
	set("outdoors","forest");
	set("valid_startroom", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
