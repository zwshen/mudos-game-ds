// rice.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¦Ì¶º", ({ "rice" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "¤@­Ó¸J­»¼Q¼Q¦Ì¶º¡C\n");
                set("unit", "¸J");
                set("value", 0);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}
