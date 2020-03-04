#include <armor.h>
#include <ansi.h>

inherit MASK;

void create()
{
        set_name("寒日面具",({"freeze-sun mask" ,"mask" }));
        set_weight(3000);
        set("long", @long
這是一副用寒日獸皮製成的面具，雖然毛茸茸的不好看，但是該獸皮
堪稱第一堅固耐磨，一般的刀劍想要在上頭劃個洞都不行。
long
);
        set("unit", "副");
        set("value", 3500);
        set("armor_prop/armor", 5);
        set("armor_prop/con", 1);
        set("armor_type", "mask");
        set("wear_msg",HIY"$N臉露微笑，緩緩的將寒日面具戴了上去。"NOR);
        setup();
}

