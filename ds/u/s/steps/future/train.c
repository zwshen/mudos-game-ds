#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "鐵路車廂內");
        set("long", @LONG
這是一列來往礦場和地球的鐵路，這條鐵路設計非常獨特，會由異空
間將人送到目的地，非常有效率。縱然這條鐵路已經建多年，但是依然經
常受人使用，可見它耐用非常。
LONG
        );
	set("no_clean_up", 0);
	set("no_kill",1);
	set("no_magic",1);
	set("no_recall",1);
	setup();
}