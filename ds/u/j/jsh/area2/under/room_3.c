#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
呼∼不知哪來的一陣冷風，引起四周一些詭異的怪響，疑 . . .
隱約聽到寒冰客棧的店小二叫聲，原來上面就是寒冰客棧。左邊的石
縫吹出緩緩的涼風。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room3",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/armor-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

