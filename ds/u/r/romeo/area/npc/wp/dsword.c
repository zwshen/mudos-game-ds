#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIM"天"+NOR+""+MAG+"舞寶"+NOR+""+HIM+"輪"NOR, ({;
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是把舞劍塵的愛劍...!\);
                set("material", "blacksteel");
        set("value",10000);
        }
        init_blade(40);
        set("wield_msg",MAG"$N一轉﹐$P馬上出現於手中...。\n"NOR);

        set("unwield_msg",CYN"$N將手中的$n放回背間。\n"NOR);

        setup();
}

void attack(object me, object victim)
{
    int damage,def;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("blade") > 50 && me->query_dex() > 20 && random(10)<3 )
    {
      message_vision(HIW "\n忽聞$N手中天舞寶輪不斷斗動, 一股佛氣竟從天舞寶輪中射出,;
      damage += me->query_skill("sword")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->;
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N閃躲不及．．．佛氣灌身！！\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else message_vision(HIG "$N大喝一聲, 將佛氣徹底潰散, 四周陰風陣陣。\n"NOR,vic;
    }
    return;
}
