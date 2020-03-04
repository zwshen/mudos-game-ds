#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
  set_name(HIW"紗牙羅號角"NOR, ({ "horn bugle", "bugle" }));
  set("long", "一隻巨大的號角，應該可以吹出驚動天地的聲音(bugle)。\n");
  set_weight(5500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "隻");
    set("value",2000);
    set("volume",5);
    set("wear_msg",
        "$N異想天開將一隻$n套在頭頂，樣子頗為可笑。\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("limit_con",30);
  set("armor_prop/dex", -2);
  setup();
}
