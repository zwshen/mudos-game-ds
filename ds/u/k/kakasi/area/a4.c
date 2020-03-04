#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"羅漢戰道"HIG"第一層"NOR);
        set("long", @LONG
這裡就是凌雲寺的禁地「羅漢戰道」，裡面黑茫茫的帶有一點點的恐怖，
在旁還有一些燃燒完的火把，想必是有些人好奇跑近來看看被在裡面的猛禽一
番的的蹂躪後的殘渣，看起來恐怖不堪。
LONG

        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"a5",
]));
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}
