#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIW"水晶胸鎧"NOR,({"crystal corslet","corslet"}));
  set("long", @LONG
潔淨無暇的水晶製成的胸鎧，非常貴重，對魔法有超群的防護力，是
古代高階魔法師所製作的珍貴防具。
LONG
);
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "副");
    set("volume",5);
    set("value",100000);
    set("material","stone");
  }
  set("armor_prop/armor",30);
  set("armor_prop/shield",40);
  set("armor_prop/int",2);
  set("armor_prop/con",3);
  setup();
}
