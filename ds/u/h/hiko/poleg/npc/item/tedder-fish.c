inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("小魚乾",({"tedder fish","fish"}));
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一條被曬的十分乾燥的小魚乾。\n");
    set("unit", "條");
    set("value",420);
    set("heal_hp",70);
    set("food_remaining",4);
  }
  setup();
  set("no_auc",1);
}



