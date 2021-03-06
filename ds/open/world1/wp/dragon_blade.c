#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIY"龍"+NOR+""+MAG+"門"+NOR+""+HIY+"嘯"+NOR+""+MAG+"月"NOR, ({ "dragon blade","blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是余滄的配刀, 是在一次偶然機會中得到的絕世寶刀!\n");
                set("material", "blacksteel");
        set("value",10000);
        }
        init_blade(40);
        set("wield_msg",MAG"$N將龍門嘯月抽出, 剎時隱隱傳來龍嘯之聲...。\n"NOR);

        set("unwield_msg",CYN"$N將手中的$n放回刀鞘。\n"NOR);

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
      message_vision(HIW "\n忽聞$N手中龍門嘯月大震, 一股龍氣竟從龍門嘯月中射出, 擊向敵人！！\n" NOR,me,victim);
      damage += me->query_skill("blade")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N不知如何反應, 將龍氣照單全收！！\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else message_vision(HIG "$N大喝一聲, 將龍氣徹底潰散, 有如神威。\n"NOR,victim);
    }
    return;
}
