#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("碎石片", ({"broken stone","stone"}));
  set("long",@LONG
一塊破碎的石板，石板上畫了一些圖案，圖上畫著一隻三隻眼看起來
巨大兇猛的龍，龍追逐攻擊一群人，下個圖案是龍與人都沉入一個大
泥沼中，看來是遠古一場驚心動魄的戰事。
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "個");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
