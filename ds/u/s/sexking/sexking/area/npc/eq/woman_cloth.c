#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("孕婦裝",({"woman's cloth","cloth"}) );
        set("long",@long
這是一件正在懷孕的婦女所穿的衣服，。
long
);
        set_weight(800);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
           set("unit", "件"); 
          set("value",1000);
          set("armor_prop/armor",2); 
          set("volume",8); 
         
         }
setup();
}
