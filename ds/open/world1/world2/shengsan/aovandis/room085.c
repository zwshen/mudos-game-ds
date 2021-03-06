// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"市立醫院"NOR);
	set("long", @LONG
奧凡迪斯內最有名的醫院就屬這裡了，醫院內有最專業的醫師駐診，
還有最新的醫療器材都在醫院裡。你看到很多求診的病患正在掛號等候。
綠化環境是院長所極力推動的，所以你會看到不少的綠色植物有系統的擺
放至醫院各個地方。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room048",
	    "north": __DIR__"room102",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/doctor0" : 1,
		__DIR__"npc/nurse" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","hospital");	//醫院

	setup();
	replace_program(ROOM);
}