#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
 set_name(HIB"巨斧"NOR,({"huge axe","axe"}));
 set_weight(44550); //damage*50就是該武器的重量
 set("value",5000);   //damage*5就是該武器的價格
 set("amount",1);  //當物品在商店賣時有幾個可以賣!
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit","把");
  set("long",YEL
      "    這把斧頭大而沉重，一般人還舉不起來，看著它，你不禁想懷疑\n"
      "這麼重的斧頭，帶著它走都以經有問題了，真的可以拿來殺敵而不會\n"
      "影響自己的戰力嗎?\n"
      NOR);     // ，。！、：
  set("material","steel"); //blacksteel也可以....
  set("axe",50);   //設定skills值
 }
 init_axe(891); //or init_sword(15)指所造成的damage量

 set("wield_msg",HIG"$N慢慢的將斧頭提了起來。\n"NOR);
 set("unwield_msg",HIG"$N鬆了一口氣，把斧頭放下，甩了甩酸痛的手臂。\n"NOR);

 setup();
}

int fail_eq(object me)
{
 if(me->query("str") <45)
 {
  message_vision(HIY"$N很努力的想提起這把斧頭，但還是提不起來。\n"NOR,me);
  return 1;
 }
 return 0;
}

void attack(object me,object victim)
{
 int damage;
 if(random(100)<60)
 {
  damage=891+random(2000);
  victim->receive_damage("hp",damage,me);
  message_vision(HIY"$N高舉巨斧，朝著$n奮力當頭劈下。\n"NOR,me,victim);
  message_vision(HIR"可憐的$N傷可見骨，"+HIW+"受到了:"+damage+"點傷害。\n",victim);
         return;
 }
 return;
}

