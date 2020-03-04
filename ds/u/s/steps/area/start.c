#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIG"ST¡DStart¢IGovernmentBuilding"NOR);
set("long","¡D¡D¡D¡D¡D¡D\n");
set("exits", ([ /* sizeof() == 4 */
"out":"/u/s/steps/area/front.c",
]));
setup();
}
