//updated
inherit ITEM;

void create()
{
          set_name("鑰匙", ({ "key" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                          "一把鑰匙，是拿來開門鎖用的。\n"
                        );
                set("value", 0);
        }
}
