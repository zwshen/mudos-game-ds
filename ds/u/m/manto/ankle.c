#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIC"一立方公尺的眼淚\"NOR,({"litre-tear ankle","ankle"}));
  set("long", @LONG  
《一公升的眼淚》以70年代末期的文化重鎮名古屋為故事背景，
一位15歲的國三少女木藤亞也，正要展開人生中最燦爛的高中
生涯。嘲諷的是，一場她從未預料過的變化改變了她的一生，
使她的生命在短短的十年間加速凋零……
LONG
);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("material","gold");
  }

  set("armor_prop/int",1 );
  set("armor_prop/str",1  );
  set("armor_prop/dex",1  );
  set("armor_prop/con",1  );
  set("armor_prop/armor", 3 );
  set("armor_prop/shield", 3 );
  set("armor_prop/show_damage", 1);
  setup();
}
