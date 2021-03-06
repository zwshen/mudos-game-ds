// Room: /u/a/acme/area/pathway9.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你正站在小坡之間，此處強風陣陣，不時的捲起黃沙，你發現在身旁
插著小小的告示牌，但上頭卻佈滿了厚厚的黃沙，只若隱若現的瞧見幾行
細細小小的字。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"pathway8",
  "east" : __DIR__"hills",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

     set("item_desc", ([
        "告示牌" : "上頭隱約可看到四個大字『小心流沙』，如遇流沙往上跳(jump up)。\n",
     ]));
	setup();
	replace_program(ROOM);
}
