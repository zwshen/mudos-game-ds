// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
一條由青石鋪設而成的街道，街道旁有一座雕像，其所刻劃的應該
是當今的國王--查理斯諾耳，儘管只是一座雕像，卻也使人感受到國王
的威嚴，往西可以出城，東邊不遠處有一座吊橋。
LONG);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood1",
  "east" : __DIR__"road13",
]));
	set("item_desc",([
	"雕像" : "一座雕像上雕刻著當今幽遮蘭帝國國王的肖像。\n" ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
