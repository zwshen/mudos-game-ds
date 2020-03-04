// Room: /u/s/sevil/workroom.c

inherit ROOM;

void create()
{
	set("short", "邪仔的工作室");
	set("long", @LONG
    當你踏進這裡，你不禁有一種被滿屋的文件和資料掩沒的感覺，你不禁
感嘆起邪仔的努力，忽然從一堆文件中冒出一個人影，你定神一看，原來是
邪仔的小寵物--「蟾蜍」跑了出來•••你不禁懷疑怎有人在養這種寵物的
，真是怪人•••
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "thief" : "/open/world2/shengsan/aovandis/room100",
  "shop" : __DIR__"1f/11.c",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"box/box.c" : 1,
  __DIR__"npc/guard.c" : 3,
  __DIR__"npc/toad.c" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

        setup();
     call_other("/obj/board/sevil_b.c", "???");
	replace_program(ROOM);
}
