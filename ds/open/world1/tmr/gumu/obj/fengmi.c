inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("¥É¸Á»e", ({"honey"}));
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "¤@Åø¥É¸ÁÆC¦¨ªº»e¡C");
                set("unit", "Åø");
        }
                set("value", 80);       
                set("heal_hp",10);
                set("water_remaining", 5); 
       setup();
}

