#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
洞穴裡黑壓壓的一片，可是你感覺到不時的有物品呼嘯而過，
定睛一看，原來這黑色景象不是洞穴造成的，而是洞穴上方站滿了
數以萬計的大蝙。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room5",
  "south" : __DIR__"room9",
]));
        set("no_clean_up", 0);

        setup();
}

