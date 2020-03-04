inherit ROOM;

void create()
{
	set("short", "戶房");
	set("long", @LONG
這裡是戶政官的官位，在這裡你可以跟戶政官申請更名或這一些有
關於戶政方面的東西，戶政官手持一本小簿子，上面寫著一堆名字，拿
著筆，似乎在打量什麼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"path8",
]));
	set("objects",([
  __DIR__"npc/censuser.c" :1,
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
