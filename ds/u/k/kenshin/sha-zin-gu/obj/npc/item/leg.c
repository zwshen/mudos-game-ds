inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("黃山雞腿",({"chicken leg","leg"}));
        set_weight(90);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "以黃山土雞所製，擁有不失一般雞所製的味道。\n");
                set("unit", "隻");
                set("value",70);
                set("heal_hp",25);
               set("food_remaining",5);
        }
     setup();
}

