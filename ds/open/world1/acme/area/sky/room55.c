// Room55.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","天地會牌坊");
	set("long", @LONG
你來到一牌坊之下，往上望去，更覺得這座牌坊的雄偉。它是由
堅硬的花崗石建成，而在石上更隱約見到一些文字。在牌坊正中央，
懸掛了一塊匾額，寫著「天地會」三個大字，能有如此氣勢，正是天
下聞名的幫會【天地會】。往北可以到達天地會中庭。

LONG
	);
	set("exits", ([
		"north": __DIR__"room45",
		"south": ACME_PAST+"area/pool",
	]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1);
}

