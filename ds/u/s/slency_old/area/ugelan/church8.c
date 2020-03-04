// Room: /u/s/slency/area/ugelan/church8.c

inherit ROOM;

void create()
{
	set("short", "此狶瞅");
	set("long", @LONG
硂柑琌綛孽狥畒此狶瞅场キ盽埃致ひ
秈此狶致⊿Τぐ或穦礚珿秈此狶パ硂畒此狶筁
胑⊿Τ睲贰笵此狶よΤぐ或狥﹁
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"church7",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
