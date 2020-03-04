#include <armor.h>
inherit HANDS;

void create()
{
        set_name("瓁刮臔得", ({ "army wristlet" , "wristlet" }) );
        set_weight(2000);       // 会臔得
        if( !clonep() ) {
                set("unit", "");
                set("value", 300);
                set("long",@long
硂琌彩簧ゴ硑臔得会ㄣ秖玱Τ讽ň縨
long
                );
                set("armor_prop/armor", 5);
        } else
		   set_default_object(__FILE__);
        setup();
}

