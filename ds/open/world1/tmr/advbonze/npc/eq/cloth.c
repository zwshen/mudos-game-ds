#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("阿羅漢袍" ,({ "a-luo-han cloth","cloth" }) );
        set("long",@LONG
這是一件齊膝的長袍，上頭用梵文字寫滿了金剛經文，似乎有避
邪去魔的功能。穿在身上的感覺似乎也不滿輕便。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(850);
                set("unit", "件");
                set("value",800);
                set("volume",3);
        }
        setup();
                set("armor_prop/armor", 10);
}

