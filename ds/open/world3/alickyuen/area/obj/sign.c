//updated
inherit ITEM;

void create()
{
        set_name("電子告示牌", ({ "sign" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long",
                        "一個告示牌，上頭有動物園的標示。\n"
                        "上面寫了一些字：「新張開幕,免費入場！！」\n");
                set("value", 1);
                set("no_get",1);
                  set("no_sac",1);
        }
}