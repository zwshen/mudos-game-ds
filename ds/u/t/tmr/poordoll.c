#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("替死娃娃",({"death doll","doll"}));
        set_weight(100);
                  set("value",100);
                set("unit","隻");
                set("long",@LONG
  一個詭異的洋娃娃。粉紅色的裙子上有著許多白色的小圓點，
充滿的神秘的靈氣...你似乎看到她在眨眼睛!? 這.....格老子的，
這隻根本就是騙人的假娃娃，一點也不值錢。
LONG
                );
        setup();
}

