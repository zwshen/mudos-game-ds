#include <armor.h>
inherit SHIELD;
void create()
{
  set_name("牛角藤盾" ,({ "cow shield","shield" }) );
  set("long",@LONG
這是牛博士為紀念他死去的愛牛，而製作的裝飾品，盾面
主體是以老樹藤加工製成，厚實耐用，堅韌的樹藤可吸收
大部份的衝擊。在盾的中間突出一雙黑色牛角，長約一尺
，似乎是[子棋牯牛]這類品種的牛角。其尖端經過打磨而
變得尖銳，增添了實用性質。
LONG
);
  set_weight(3500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "面");
    set("value",2000);
  }
  set("armor_prop/con",1);
  set("armor_prop/armor",14);
  set("armor_prop/damage",6);
  setup();
}
