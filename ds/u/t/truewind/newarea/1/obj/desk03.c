#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIW"白玉朝陽桌"NOR, ({ "table" }));
        set("long", @long
使用白玉與雞血石製成的桌子，上頭血紅的紋路豐富多變。
long
);       
        set_weight(190000);
        set("value", 20000);
        set("no_sac",1);
        setup();
}