inherit ITEM;

void create()
{
    set_name("¥¨Å]¯á´Õ°©", ({"troll spinal bone", "bone"}));
    if( !clonep() ) {
        set("long", "¤@±ø¥¨Å]ªº¯á´Õ°©¡A¦ü¥G´N¹³±øÅKÃ@¡C");
        set("value", 10);
        set("unit", "±ø");
        set("weight", 20);
         } else
		   set_default_object(__FILE__);
    setup();
}
