inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("飛魚肉",({"flyfish meat","meat"}));
  set_weight(400);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一塊經過精細處理的飛魚肉。\n");
    set("unit", "塊");
    set("value",220);
    set("heal_ap",25);
    set("heal_hp",15);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}







