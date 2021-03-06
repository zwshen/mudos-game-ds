#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIG"荊棘頭冠"NOR ,({ "brambly crown","crown" }) );
  set("long",@LONG
一頂由荊棘纏編的頭冠，頭冠上開著幾朵奇形怪狀的紫色小花，仔細
一看數不盡的尖刺上竟然還長著如鋸齒般的倒勾，真無法想像什麼樣
的人會去戴這頭冠。
LONG
);
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "頂");
    set("value",1000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/shield",1);
  set("armor_prop/dex",-2);
  set("armor_prop/bio",-1);
  set("armor_prop/int",2);
  set("armor_prop/wit",1);
  set("wear_msg",
      "$N忍著疼痛將一頂長滿尖刺$n戴在頭上，雙眼透出堅定而有力的眼神。\n"NOR);
  setup();
  call_out("blooding_by_crown", 30);
}

void blooding_by_crown()
{
  object me = environment(this_object());
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/head")==this_object() )
  {
    me->receive_damage("hp", 5+random(10));
    message_vision(RED"$N上的尖刺插入$n的皮肉，幾滴鮮血從$n的額頭上流了下來....\n"NOR, this_object(), me);
  }
  call_out("blooding_by_crown", 35);
}
