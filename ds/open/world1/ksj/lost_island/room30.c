#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－"HIG"獸原"NOR);
        set("long", @LONG
這裡是一望無際的大草原，長滿及膝的青翠雜草，還有許多不知
名的花草植物，此處的山壁間有個隱密的洞口，洞口旁長滿藤蔓蘚苔
，看起來陰氣森森，應該不是什麼好地方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"room31",
  "southwest" : __DIR__"room29",
  "south" : __DIR__"room28",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("objects",([
             __DIR__"npc/eq/bone":1,
           ]));
        setup();
}
