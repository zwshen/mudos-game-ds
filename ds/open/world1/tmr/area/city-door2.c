#include <path.h>
inherit ROOM;

void create()
{
        set("short", "滄縣南城門");
        set("long", @LONG
這是滄縣城的南城門，城門口下聚集著各種攤販，叫賣著各式各樣的新
鮮貨品，相當的熱鬧啊！滄縣治安良好，你可以看見一片安和的景象。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"street6",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/garrison" : 4,
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);

        setup();
        replace_program(ROOM);
}

