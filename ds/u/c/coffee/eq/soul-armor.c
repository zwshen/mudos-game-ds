#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIC"魂"HIY"元"HIR"戰甲"NOR, ({ "soul armor","armor" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","一件行體不定的鎧甲，但是防禦力十足，似乎有神奇的力量。");
                set("unit", "件");
                set("value",10000);
        }
       set("wear_msg","$N把$n穿起來後，看起來更加邪惡了！\n");

   set("unwear_msg","$N從手上把$n脫了下來了，頓時鬆了一口氣。\n"NOR);
                  set("armor_prop/armor", 20);
        set("armor_prop/bar", 1);
        set("armor_prop/tec", -1);
        set("armor_prop/wit", -1);
        set("armor_prop/con", 3);
        set("armor_prop/str", 2);
        set("armor_prop/int", -1);
        setup();
}
