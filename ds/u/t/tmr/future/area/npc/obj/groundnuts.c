inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("鹽脆花生", ({ "groundnuts" }) );
        set_weight(100);
        if( clonep() )
             set_default_object(__FILE__);
        else {
             set("long", "一盤上等的花生,是美酒的良伴。\n");
             set("unit", "盤");
             set("value", 50);  
             set("food_remaining",10);
             set("heal_mp",5);  
        }
}
