#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("兩桃殺三士畫像石", ({ "xiang stone", "stone"})); 
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "塊");
                set("weight", 1000);
                set("long", "這是東漢石雕像中其中一個，出自陝西，山東，河南一帶，\n是非有常價值的古物。\n");
                set("material", "stone");
                }
                set("value", 100);
}
