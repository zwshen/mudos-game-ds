#include <armor.h>
#include <ansi.h>
inherit HEAD;

string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});

void create()
{
  set_name(HIW"逆角"HIR"龍盔"NOR,({ "inverse-horn helmet","helmet" }) );
  set("long",@LONG
    此盔乃血眼逆角惡龍的頭骨，雖是上古之物但仍然散發金鐵般光
澤，一對向前逆長銳利犄角給人有巨大的壓迫感，頭骨眼窩中還不時
有散爍不定的紅光。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(7000);
    set("unit", "頂");
    set("value",15000);
    set("volume",5);
    set("light",1);
  }
  set("armor_prop/armor", 15);
  set("armor_prop/shield",10);
  set("limit_con",50);
  set("limit_str",20);
// 2003.3.30 新增 lv限制 by ksj
  set("limit_level",45);
  set("armor_prop/con", 2);
  set("armor_prop/str", 2);
  set("armor_prop/dex", -1);
  call_out("receive_by_helmet", 30);
  setup();
}

void receive_by_helmet()
{
  object me = environment(this_object());
  int p_ap, i;
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/head")==this_object() )
  {
    p_ap = me->query("max_ap");
    if( me->query("ap") < p_ap*4/5 )
    {
      me->receive_heal("ap", p_ap*1/100);
      for(i=0;i<sizeof(wounds);i++)
      me->receive_curing(wounds[i], 1);
      message_vision(HIR"$N的眼窩中紅光大盛，一陣灼熱的感覺傳到$n的體內....\n"NOR, this_object(), me);
    }
    else
    {
      tell_object(me,HIW"逆角"HIR"龍盔"NOR"發出紅色光芒，但是沒有什麼事發生！\n");
    }
  }
  call_out("receive_by_helmet", 35);
}
