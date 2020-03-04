#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(WHT"銀鱗皮甲"NOR ,({ "dragon armor","armor" }) );
  set("long",@LONG
這是一件泛著銀色光芒的龍皮鎧甲，拿在手上極輕，卻甚為堅實。
相傳前古時代天地遭劫，群龍無首，青眼龍以大智慧化解此劫，並
帶領群龍至(現)磐龍山隱居，數百年相安無事。青眼龍長期在磐龍
山巔吸收日月精華，體色漸漸轉為銀白色，故稱其為青眼白龍，此
皮甲本身散發出微弱的光芒，溫暖且明亮。
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
    set("value",12000);
  }
  set("limit_level",25);
  set("armor_prop/armor",41);
  set("armor_prop/con",3);
  set("armor_prop/dex",-1);
  set("armor_prop/bar",1);
  set("armor_prop/sou",-1);
    set("armor_prop/wit",-1);
  set("armor_prop/dodge",-5);

  set("beast_armor_type","armor");
  set("beast_armor_prop/armor",44);
  set("beast_armor_prop/shield",30);
  set("beast_armor_prop/con",3);
  set("beast_armor_prop/dex",-1);
  set("beast_armor_prop/bar",1);
  set("beast_armor_prop/dodge",-5);
  setup();
  this_object()->start_light(1);
}
