#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG 
富有礦物質的水遇到洞裡的空氣，便開始蒸發，溶解石灰岩便 
隨蒸發的水一點一滴地沉積成千變萬化的奇峰怪石，增添了洞穴裡
的神秘美感。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room15",  
  "south" : __DIR__"room13",
]));
        set("no_clean_up", 0);

        setup();
}

