inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("Âû»L",({"chicken leg","leg"}));
        set_weight(90);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "¤@°¦­»¼Q¼Q¡B¼öÄËÄËªºÂû»L¡C\n");
                set("unit", "°¦");
                  set("value",90);
                set("heal_hp",15);
               set("food_remaining",2);
        }
     setup();
}

