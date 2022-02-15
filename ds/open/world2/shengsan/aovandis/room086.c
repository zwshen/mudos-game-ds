// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"投資顧問公司"NOR);
	set("long", @LONG
這間公司是間商業公司，專門做投資事業。兩旁的牆壁旁有幾個盆栽
，裝潢為亮白色的色系。公司內每個人都忙著工作，裡面還有間會議室，
似乎有人在裡面開會。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room098",
	    "south": __DIR__"room019",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss0.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}