inherit ITEM;

void create()
{
    set_name("夜禍石", ({"nightbane stone", "stone"}));
    if( !clonep() ) {
        set("long", "這是一顆黑漆漆的石頭，拿著手上就有股不詳之感。");
        set("value", 10);
        set("unit", "粒");
        set("weight", 10);
        set("value",10);
        } else
		   set_default_object(__FILE__);
    setup();
}
