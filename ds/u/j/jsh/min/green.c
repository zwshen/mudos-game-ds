#include <ansi.h>
inherit ITEM;
void create()
{
            set_name(HIG"綠寶"NOR,({"green stone","green","stone"}) ); 
            set_weight(1000);
            set("unit","顆"); 
            set("value",10000);
            set("long","閃閃發亮的寶石，有股神秘感，不知道是做什麼用的？\n"); 

       setup();
}

