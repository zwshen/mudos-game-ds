// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¥É¸Á¼ß", ({"honey juice", "jucie"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "¤@²~¥Î¥É¸Á±_·o¦¨ªº¼ß¡C\n");
                set("unit", "²~");
                set("value",10);
                set("food_remaining",3);
                set("heal_hp",5);  
        }
}


