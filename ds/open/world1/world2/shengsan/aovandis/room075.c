// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"婚姻介紹所"NOR);
	set("long", @LONG
你未婚嗎？你正在找第二春嗎？這裡是促成良好姻緣的好地方。浪漫
氣氛的裝潢，加上介紹人的專業與執著，受惠的男女可是說也說不完。聽
說在全世界各地都有他們的分公司。牆上有個告示牌(note)。
LONG
	);
	set("item_desc", (["note":@NOTE

佈告牌上寫著:
[1;36m
	婚姻乃終身大事，不可以兒戲視之。
	別在猶豫了，特別為您量身定做的伴侶，一定讓您滿意。
	如果有需要就請本公司的介紹人為你介紹吧。
[m
[1;33m					* 婚姻介紹所 *
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room063",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/introducer.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}