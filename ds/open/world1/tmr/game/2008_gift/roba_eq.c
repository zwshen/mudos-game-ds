#include <ansi2.h>
#include <armor.h>
inherit PANTS;

void create()
{
   set_name(BBLU HIB"深藍色"HIY"短褲"NOR,({ "mazarine knee breeches", "breeches" }) );
  set("long",@LONG
    經典五分短褲版型，立體口袋剪裁，營造出視覺古著氣息。流行指數滿點
，街頭動感能量展現。雙側口袋機能性佳，設計超實用，任何人都可以穿出自
我風格！
這件裝備為roba在2008年「鼠來寶」活動中獲得的獎品。
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "件");
    set("value", 100);
        set("wear_msg", HIC"穿上這件褲子時，$N感覺到自己成為街頭注目的焦點。"NOR);
        set("unequip_msg", WHT "當$N脫下褲子的同時，週遭人們頻頻用鄙視的眼光向$N指指點點。\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 20);
  set("armor_prop/show_damage",1);
  set("armor_prop/con",4);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}


int query_autoload() { return 1; }

