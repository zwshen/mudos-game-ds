inherit ITEM;

void create()
{
        set_name("鑰匙", ({ "key" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把鑰匙。\n");
                set("value", 1);
        }
}
