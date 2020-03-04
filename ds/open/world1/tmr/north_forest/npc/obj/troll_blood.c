inherit ITEM;

void create()
{
    set_name("¥¨Å]¦å²G", ({"troll blood", "blood"}));
    if( !clonep() ) {
        set("long", "¤@²~¥¨Å]ªº·t¬õ¦â¦å²G¡A¤w§e¥b¾®©Tª¬ºA¡C");
        set("unit", "°ï");
        set("value", 100);
        set("unit", "²~");
        set("weight", 20);
        } else
	set_default_object(__FILE__);
    setup();
}

