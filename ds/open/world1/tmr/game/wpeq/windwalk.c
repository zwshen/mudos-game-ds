//掌上遊戲第一屆比賽 第五名 windwalk 獎品 -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
          set_name(HIC "冰月靈兜" NOR ,({ "ice-moon skirt","skirt"}) );
          set("long",@long
掌上遊戲第一屆比賽 第五名 windwalk 獎品。
    這是取千年冰蠶所吐之絲在吸取日月精華之後所編織而成，
因此除了十分強韌、水火不侵之外還帶有極高的靈氣。
long
);
          set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "件" );
                set("value",1000);
                set("valme",3);
                set("no_sac",1);
		set("wear_msg","$N穿上了冰月靈兜，感到真氣在下半身的運行更加順暢了。\n");
		set("remove_msg","$N脫下了冰月靈兜，真氣的運行又恢復到平常的感覺。\n");
                set("armor_prop/armor", 5);
        }
        setup();
}

int query_autoload() { return 1; }
