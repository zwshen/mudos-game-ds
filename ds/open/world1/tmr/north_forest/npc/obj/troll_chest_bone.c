inherit ITEM;

void create()
{
    set_name("巨魔胸骨", ({"troll chest bone", "bone"}));
    if( !clonep() ) {
        set("long", "一副巨魔的胸骨，是常人的三倍大。");
        set("value", 10);
        set("unit", "副");
        set("weight", 20);
         } else
		   set_default_object(__FILE__);
    setup();
}
