// 繼承國人貪多嚼不爛, 一定吃到飽的精神, 東西能吃, 很便宜, 帶不出場
// 價錢約為原設定值的三分之一
// wilfred@DS

inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("黃獐腿",({"cheap leg","leg"}));
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一隻香噴噴、熱騰騰的黃獐腿。\n");
    set("unit", "隻");
    set("value",20);
    set("heal_hp",15);
    set("food_remaining",2);
  }
  setup();
  set("no_auc",1);
}
