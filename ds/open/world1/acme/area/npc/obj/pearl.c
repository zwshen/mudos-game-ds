inherit ITEM;
void create()
{
        set_name("夜明珠", ({ "pearl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一顆天藍色的小珠子，在晚上時會發出閃光。\n");
                set("unit", "顆");
                set("value",100);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}
