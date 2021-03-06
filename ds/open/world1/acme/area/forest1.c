// Room: /u/a/acme/area/forest1.c
#include <path.h>

inherit MOBROOM;

void create()
{
	set("short", "森林");
	set("long", @LONG
你正站在樹海之間，四周的古木，高聳入雲，隱天蔽空，陽光照射不
進來，環顧一切，只覺昏昏暗暗的，令人覺得有股莫名的壓力。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pass8",
  "south" : TMR_PAST+"ghost-forest/forest16",
  "east" : __DIR__"forest",
]));
	set("no_clean_up", 0);
       set("objects",([
          __DIR__"npc/hap" : 1,
       ]) );
     set("outdoors","land");

        set("chance",10);
       set("mob_amount",1);
        set("mob_object",({     //設定怪物檔名.
            __DIR__"npc/bear",
        }) );
	setup();
}
