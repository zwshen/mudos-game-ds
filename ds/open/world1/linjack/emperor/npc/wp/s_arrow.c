inherit ITEM;

void create()
{

        set_name("精鋼弩箭",({"steel arrow","arrow"}));
        set_weight(500);
        set("long","這是一個中空設計的精鋼弩箭, 輕而且強韌, 尖銳的箭頭可造成極大破壞。\n");
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("unit", "支");
           set("material","steel");
          set("value",75);
        }
   set("arrow/damage",60);
	setup();
}
int hit(object target,object me)
{
    target->apply_condition("blooding", target->query_condition("blooding")+3);
     return 1;
}
