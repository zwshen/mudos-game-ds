inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("鰻魚肉",({"grig meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一塊經過把鰻魚仔細處理的肉，營養價值高。\n");
    set("unit", "塊");
    set("value",290);
    set("heal_ap",28);
    set("heal_hp",28);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}





