#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(HIW+BLK"闇"NOR+YEL"鱷"NOR"牙鍊",({"crocodile teeth-necklace","necklace"}));
  set("long", @LONG
一條用闇夜鱷魚的牙齒串成的項鍊，每顆牙齒嵌合的都剛剛好，
這種巧奪天工的手法真不是一般人能辦到的•它還隱約透露出
那隻鱷魚的力量•
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",3);
    set("value",30000);
    set("material","gold");
  }
  set("limit_lv",45);
  set("armor_prop/armor",15);
  set("armor_prop/shield",8); 
  set("armor_prop/dex",-2);
  set("armor_prop/con",2); 
  set("armor_prop/str",-2); 
  set("armor_prop/bar",1); 
  set("armor_prop/sou",-1); 
  setup();
}

