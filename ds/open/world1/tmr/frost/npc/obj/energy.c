// 舍利子 shelizi.c

#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIG"天妖元精"NOR, ({ "tian-demon energy","energy" }));
        set("long",@LONG
這是一顆「天妖」的數千年妖力所聚成的元精，約有雞蛋般大小，當
你望著元精時，直覺得你的靈魂似乎要被吸進去一樣。
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("eat_msg","$N吃下一顆帶著綠色光芒的光球。");
                set("eff_msg",HIY "元精裡充沛欲出的力量隨時在你體內四處流竄！！"NOR  );
        }
          set("value", 2500);
        set("heal",([
                "hp"    : 500,
                "ap"    : 500,

        ]));
    setup();
}

