#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIC"海神耳環"NOR ,({ "leviathan earring","earring" }) );
  set("long",@LONG
深海寶石製成的一對耳環，從大海怪  利貝亞森的腹中所取得，此
對耳環琢磨細緻，手工精巧，寶石藍光流轉，呈現海水般湛藍的光
澤，在陸地上是前所未見，不知為何出現在利貝亞森的肚中。
LONG);
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("unit", "對");
    set("value",100000);
  }
  set("limit_lv",30);
  set("armor_prop/armor",1);
  set("armor_prop/con", 3);
  setup();
}

int query_autoload() { return 1; }

