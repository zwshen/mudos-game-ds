#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIW"傳天國作"HIR"•"HIC"小烏丸太刀"NOR, ({ "shouugan katana","katana" }) );
  set("long",@long
古時桓武天皇在位時，前往南殿朝拜之時，突然有一隻烏鳥飛來，此
烏鳥說自己是伊勢神宮的使者便又飛去，之後留下的這把太刀便取其
名為”小烏丸”。傳說  此刀作者為古來天國，為天寶年代的刀匠。
小烏丸全長１０４ｃｍ，刃長７２ｃｍ，總重１４５０ｇ。
long);      
  set_weight(1450);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",3);
  }
  set("rigidity",1200);
  set("limit_skill",60);
  set("limit_lv",40);
  set("weapon_prop/str",1);
  set("weapon_prop/con",2);
  set("weapon_prop/dex",2);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(68);
  set("wield_msg",HIC"$N將$n"HIC"從刀鞘中拔出，從刀刃中閃爍浮現鳥形光紋。\n"NOR);
  set("unwield_msg","$N將手中的$n放回刀鞘，發出--鏗--一聲清響。\n");
  setup();
}


void attack(object me, object victim)
{
  int damage,def;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_dex() > 40 && random(10)<3 )
  {
    message_vision(HIC"\n小烏丸太刀"HIW"帶動"HIY"$N"HIW"的身形急舞，"
                  +"刀光人影幻化從四周劈斬到$n"HIW"身上．．．\n"NOR,me,victim);
    damage += me->query_skill("blade")+me->query_str()+random(100);
    def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
    def = def/3;
    if(damage-def>0 && random(10)>4)
    {
      damage=damage+random((damage-def));
      message_vision(HIR"刀光乍停，$N"HIR"只覺全身劇痛，"
                    +"鮮血隨著叫聲濺灑在空中！！("+damage+")\n"NOR,victim);
      victim->receive_damage("hp",damage, me);
    }
    else message_vision(HIG"$N"HIG"見狀左閃右躲，正好逃出了攻勢之外。\n"NOR,victim);
  }
  return;
}
