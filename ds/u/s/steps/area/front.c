#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",HIG"ST¡DFront¢IGovernmentBuilding"NOR);
          set("long","¡D¡D¡D¡D¡D\n");
          set("exits", ([ /* sizeof() == 4 */
          "enter":"/u/s/steps/area/start.c",
          "south":"/u/a/alickyuen/area/dst18.c",
]));
setup();
}
