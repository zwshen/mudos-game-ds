// Room: /open/world1/acme/bonze/b15.c

inherit ROOM;

void create()
{
	set("short", "戒律院");
	set("long", @LONG
這裡是讓犯戒的僧人在此閉門深思，懺悔過錯的地方，這兒空空
蕩蕩的，眼前只有一張小木桌及一個大圓蒲，木桌上放著一個大木魚
，似乎是給犯戒僧人使用的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"b14",
]));
set("objects",([
   __DIR__"npc/b_bonze" : 1,
]) );
        set("light",1);

	setup();
	replace_program(ROOM);
}
