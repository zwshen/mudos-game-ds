#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(MAG"獨家特極長蛇鞭"NOR , ({ "snake whip","whip" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一把揚家的家傳鞭子，鞭身特長還有一粒粒的刺，令不但攻擊範圍加\n"
        "長，還具有額外的殺傷力。\n");
    set("material", "silver");
    set("value",4700);
    set("weapon_prop/str",1);
  }
  init_whip(35);
  setup();
}

