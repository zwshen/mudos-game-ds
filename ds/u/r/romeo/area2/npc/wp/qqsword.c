#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIY"殺"YEL"禪"BLINK"ψ"NOR,({"kill sword","sword";

        set_weight(5000+random(2000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"這把劍是佛教之聖器，可以感受到它的佛氣，但卻也帶有極"
                      "大之殺氣，不知道它到底是正是邪。\n"NOR);
                set("volume",2);
                set("unit", "把");
                set("value",12500);
        set("limit_skill",60);
        set("material","silver");
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",35);
        }
        init_sword(70);
        set("wield_msg","$N從袖口中滑出一把$n，登時佛氣$N的身上散發;
        set("unwield_msg", "$N將手中的$n收回袖中。\n");
        set("replica_ob", __DIR__"dsword.c");
        setup();
}
void attack(object me,object victim)
{
        int damage,str,dex,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("str")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIY"$n暴出一道佛氣，四周開始昏暗了起來\n"NOR
        +HIG"一道天雷擊中劍身∼ ∼ ∼ \n"NOR
        +HIR"倏地間，在$N眼前一片彩光閃過...從劍中發出五道劍芒往$N而去射去。\n"NR
        +HIB"結果造成$N"+damage+"點的傷害！！！！\n"NOR
        ,victim);
        return;
        }
}
