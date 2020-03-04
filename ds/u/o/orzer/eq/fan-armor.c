#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(HIM"幻"HIY"琉璃"HIR"鎧"NOR ,({ "fan-light armor","armor" }) );
  set("long",@LONG
這是一件泛著琉璃色的盔甲，拿在手上極輕，可是卻能抵禦強大衝
大衝擊，而且自然發出柔光，給人一股寧靜的力量，擁有著讓人安
心的氣息，並擁有一波波的氣息湧出。
LONG
);
  set_weight(8500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "件");
    set("value",50);
  }
  set("limit_level",25);
  set("armor_prop/armor",150);
  set("armor_prop/con",20);
  set("armor_prop/dex",20);
  set("armor_prop/bar",2);
  set("armor_prop/sou",2);
  set("armor_prop/dodge",30);
  set("armor_prop/int",20); 
  set("armor_prop/hit",50);
  set("armor_prop/str",20);
  set("armor_prop/show_damage",1);
  set("armor_prop/bio",3);  
  setup();
  this_object()->start_light(1);
}
int query_autoload() { return 1; }


