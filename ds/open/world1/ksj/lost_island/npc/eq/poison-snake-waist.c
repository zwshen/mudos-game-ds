#include <ansi.h>
#include <armor.h>
inherit WAIST;
void create()
{
  set_name(MAG"腐毒束帶"NOR ,({ "poison-snake waist","waist" }) );
  set("long","一條紫色發著惡臭的蛇皮，光聞味道就叫人頭昏眼花。");
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "條");
    set("value",1000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/shield",1);
  set("armor_prop/dex",-1);
  set("armor_prop/con",-2);
  set("armor_prop/str",-1);
  set("armor_prop/int",-3); 
  set("armor_prop/bar",1);
  set("wear_msg",
      "$N將一件惡臭的$n繫在腰間，頓時臉泛紫紅，全身力量暴增。\n"
       NOR);  setup();
  call_out("poison_by_waist", 30);
}

void poison_by_waist()
{
  object me = environment(this_object());
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/waist")==this_object() ) {
  me->apply_condition("poison", me->query_condition("poison")+(random(1)+1));
	me->receive_damage("hp", 35+random(50));
	// by alick
  message_vision(MAG"$N發出一陣紫色毒氣，$n吸入後立刻臉色泛紫....\n"NOR, this_object(), me);
	}
  call_out("poison_by_waist", 35);
}
