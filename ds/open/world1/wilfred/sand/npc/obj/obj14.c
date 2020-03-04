// 繼承國人貪多嚼不爛, 一定吃到飽的精神, 東西能吃, 很便宜, 帶不出場
// 價錢約為原設定值的三分之一
// wilfred@DS

inherit ITEM;
inherit F_WATER;
void create()
{
  set_name("青蛇湯", ({ "cheap soup","soup" }) );
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一碗淡白色的清湯，裡頭飄著幾條小青蛇，喝了強身補體。\n");
    set("unit","碗");
    set("value",50);
    set("heal_ap",30);
    set("water_remaining",2);
  }
  setup();
  set("no_auc",1);
}
