#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟盡頭");
        set("long",@LONG
你走到了洞窟的盡頭，你睜大眼睛,揉揉眼睛，你據然不敢相信你自己所
看到的畫面，個人不像人，鬼不像鬼的生物，他看起來似乎很凶猛，你心想：難
到剛才的叫聲是它叫的？？你一想到這個，就全身起雞皮疙瘩，只想敢快離開這
裡....！！
LONG
      );
        set("exits", ([ /* sizeof() == 1 */
  "out" :"/u/t/tako/area/room~4.c",
]));
    set("light",1);
set("objects", ([ 
"/u/t/tako/area/chi***yo.c" : 1,
]));
    set("no_clean_up", 0);
                set("outdoors","land");

        setup();
 replace_program(ROOM);
}



