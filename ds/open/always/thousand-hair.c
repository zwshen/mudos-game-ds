#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
  set_name( HIW "三千"HIM"煩惱絲" NOR , ({ "thousand-hair whip","whip", "THOUSAND_HAIR_WHIP"}) );
    set("long", "   眾所皆知，滅神鞭法為情城池的鎮派絕技，其招式本身
威力已獨步武林，因此任何情城池的弟子，只要潛心修練，
都能在武林中達到一定的地位。
    然而，欲達到武林中一流高手的境界，則唯有靠進一步
修鍊由香香祖師所創立的「三千煩惱絲」才有可能達到。「
三千煩惱絲」能讓情城池弟子，在長達七年的時間中蓄留長
髮，以特殊的內功\心法及藥方改善髮質，直至最後留至七尺
而大功\告成時，剪下長髮並混進任何一條長鞭，成為每一個
情城池弟子特有的獨門武器。
\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("material", "iron");
    set("value",0);
    set("no_sell",1);
    set("wield_msg", CYN "當$N將$n"CYN"握在手中時，眼神透露出一股看淡生死、忘卻世間情苦的覺悟。\n"NOR);
  }
  init_whip(5);
  set("weapon_prop/armor",1);
  setup();
}


