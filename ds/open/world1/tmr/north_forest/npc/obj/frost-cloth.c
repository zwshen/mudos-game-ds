#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIW"流ブ︾"NOR ,({ "frost-troll cloth","cloth" }) );
  set("long",@LONG
硂琌パよ此狶流エ臸眔ブ︾蝗フを︹ぷ痷タ
流妓簘獹
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "ン");
    set("value", 20000);
    set("material", "fur");
  }
    set("limit_lv",40);
    set("armor_prop/str",1);
    set("armor_prop/int",2);
    set("armor_prop/dex",2);
    set("armor_prop/shield",10);
    set("armor_prop/armor", 20);

  setup();
}

