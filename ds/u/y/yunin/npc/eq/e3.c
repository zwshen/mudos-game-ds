#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()

{

        set_name(HIC"Ｄ級神衣"NOR ,({ "level D cloth","cloth" }) );

        set_weight(900);

        if( clonep() )

                set_default_object(__FILE__);

        else {

 set("long",@LONG

天界神兵們所穿的衣服﹗

LONG

     );

        set("unit", "件");

        set("value",2000);

        set("material", "cold");

        set("armor_prop/shield",1);

        

        set("armor_prop/armor", 15);

        }

        setup();

}
