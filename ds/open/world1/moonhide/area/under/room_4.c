#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
耶∼∼這裡竟然有蝴蝶，而且為數眾多，在飛翱的同時，經由翅
膀的拍打，散下了細細的鱗粉，且帶點香味，讓這間密室不在有陰霾
的氣氛，反而有種春天的感受，只是，這裡是密室耶。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room4",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/hands-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

