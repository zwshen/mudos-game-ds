#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(MAG"紫檀方桌"NOR, ({ "table" }));
        set("long", @long
檀木加工製成的紫色小方桌，適合數人圍坐品茗。
long
);       
        set_weight(190000);
        set("value", 15000);
        set("no_sac",1);
        setup();
}