#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
set_name( HIG"十"HIW"方"HIY"靈"HIW"動"NOR ,({"ten sword","sword"}));
        set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"
一把散發出靈光的劍,上面附著著無數顆的寶石,
鋒利無比,連石頭都能輕鬆切開。\n"NOR);
                set("volume",2);
                set("unit", "把");
                set("value",12500);
        set("limit_skill",60);
        set("material","silver");
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",35);
        }
        init_sword(80); 
        set("wield_msg","$N從腰際拉出了一把$n握在手中,綠色的光芒讓$N的眼睛充滿
                           著光芒,散發出迫人不及的靈氣 。\n");
        set("unequip_msg", "$N放下手中的$n, 將$n插入腰際的劍鞘中,光茫漸漸不見。\n");
        set("combat_msg", ({
   "$N使出第一式「綠」,劍尖發出綠色的氣體,直沖$n雙眼 "  ,
   "$N使出第二式「刃」,$N把十方靈動上轉下滑,劍刃斬往$n的腰際",
   "$N使出地三式「隱」,十方靈動若隱若現的出現在$n的面前,$N提聲運氣,昇華旁邊的氣體,把$n周圍變戌辛u空狀態,$n的動作慢了半拍,你順勢把劍上提,劃向$n的腿部",
   "$N使出第四式「撩」,十方靈動由上旋劈至下,往$n的手部而去",
   "$N使出第五式「爆」,十方靈動有如炸藥的爆破聲,往$n的背部去,像萬斤的劍",
   "$N使出第六式「冰」,十方靈動急轉而下,速度驚人,十方靈動漸漸結冰,滑向$n",
   "$N使出第七式「針」,$N把十方靈動快速移動,從空氣劃過一到劍氣射往$n,像千萬枝銀針",
   "$N使出第八式「封」,只見你嘴裡唸唸有詞,忽然一句:「封」,$n的身體忽然不能動了,\n
    你把十方靈動往$n那邊一拋,正好插進了結界,$n嚇的把自身武器刺向腹部",
   "$N使出第九式「心」,$N闔上雙眼,手趨十字,十方靈動迴旋一週,擲出數道劍氣,\n
     全部射往$n的方向,只見$n東躲西閃", 
}) ); 
      setup();
}
void attack(object me,object victim)
{
        int damage,str,dex,random1;
        if( random(200)>150)
        {
        str = me->query("str")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIY"$N使出第十式「靈」,$N稟氣凝神,一聲「喝 ~ ~ ~」的一聲\n�       ,十方靈動奔向空中,$N施展無上輕功,跳到十方靈動的旁邊\n"NOR
        +HIC"隱見十方靈動被雷亟中,散發出前所未有的光芒 + + + + +\n"NOR          +HIR"你把手指指向$N,十方靈動疾速飛行,尤如音速射往$N的胸部\n"NOR
        +HIB"結果造成$N"+damage+"點的傷害！！！！\n"NOR
        ,victim);
        return;
        }
}


