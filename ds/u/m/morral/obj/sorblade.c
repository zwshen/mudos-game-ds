#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
 set_name(MAG"悲之刀"NOR,({"sorrow blade","blade","sorrow"}));
 set_weight(10000);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "把");
  set("long",HIG"這把刀，原擁有者是誰已不可考，但顯然已經相當古老。
你還可以感覺的到，這把刀的主人，曾經做過什麼事情。
情人之死，至交之叛，恩人之仇•．．．。\n"NOR);
  set("value",20000);
  set("material", "steel");
  set("wield_msg","WHT$N慢慢的低下頭，拔出$n，一陣陣悲傷之氣從$N的身上散發出來。\n"NOR);
  set(CYN"unwield_msg", "$N將手中的$n插回刀鞘。\n"NOR);
 }
init_blade(51);
 setup();
}
void attack(object me,object victim)
{
 int damage,hp,maxhp,mp;
 me=this_player();
  hp=me->query("hp");
  maxhp=me->query("max_hp");
  mp=me->query("mp");
 if ( hp < maxhp/10 )
 { 
   damage=2000+random(5) * (hp+mp);
  message_vision(HIY" 悲之刀吸收了所有使用者的力量，揮出悲痛一擊！！！
    造成$N"+damage+"點的傷害！！！！\n"NOR,victim); 
  victim->receive_damage("hp", damage, me );
 me->set("hp",1);
 me->set("mp",0);
 return;    
 }
}
