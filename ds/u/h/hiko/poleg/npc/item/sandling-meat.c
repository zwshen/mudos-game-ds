inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("比目魚肉",({"sandling meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一塊經過簡單處理的比目魚肉。\n");
    set("unit", "塊");
    set("value",145);
    set("heal_ap",16);
    set("heal_hp",16);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}






