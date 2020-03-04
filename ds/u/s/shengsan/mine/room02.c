// room02.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "[1;36m´¼¼z«¬¢Ü¢Þ¢Ñ¬ã¨s«Ç[0m");
	set("long", @LONG
«z«¢«¢......³o¸Ì¦³´¼¼z«¬¥Íª«³á......¤p¤ß§Aªº¤p§¾§¾
³Q¥L­Ì«ç¼Ë³á......¼H¼H¼H...¡C
LONG
	);

	set("exits", ([ /* sizeof() == 7 */
		"west" : __DIR__"room01",
	]));
	set("objects", ([ /* sizeof() == 1 */
		"/u/s/shengsan/npc/liliya" : 1,
	]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}