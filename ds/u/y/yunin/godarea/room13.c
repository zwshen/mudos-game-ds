#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"主臥室"NOR);
        set("long", @LONG
一觸摸奇怪的石頭後，立即來到了一個神秘的地方，這裡的擺設
相當的整齊，右上方的牆壁上掛了數把當今世上的神器，你心裡一想
，這一個人一定是一個在江湖裡相當有地位的人。
LONG
        );
        
                set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room15",
  "west"  : __DIR__"room14",
]));  
        set("no_clean_up", 0);
        setup();
}     

