#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name( "流ブ︾"  ,({ "frost-troll cloth","cloth" }) );
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
    set("armor_prop/int",1);
    set("armor_prop/dex",1);
    set("armor_prop/shield", 5);
    set("armor_prop/armor", 10);

  setup();
}


