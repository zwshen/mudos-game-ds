#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("葬衣",({"death cloth","cloth"}) );
        set("long",@long
  就是死人下葬時穿的衣服，看來十分詭異。
long
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",3);
                set("unit", "件");
                set("value",3500);
                set("limit_lv",8);
                set("armor_prop/str",2);
                set("armor_prop/armor",10);
        }
        setup();
}


