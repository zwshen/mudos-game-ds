//u/c/chiaa/world2/blackly_forest/fen3.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "沼澤");
        set("long", @LONG
在你面前有處極大的綠色沼澤,看來相當噁心,
在沼澤周圍赫然可見不少骨骸,沼面上也長有奇相怪狀的植物,
也可看到一些不知名的生物,整個沼面散發出極惡臭的屍氣味,
令人聞之欲吐!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */     
     "north"      : __DIR__"fen2",           //沼澤2
     "northwest"  : __DIR__"fen_road2",      //沼澤小路2
]));
       
        setup();
replace_program(ROOM);
}
