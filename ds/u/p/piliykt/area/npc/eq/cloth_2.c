#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIR"鳳凰"HIW"羽衣"NOR ,({ "phoenix cloth","cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
鳳凰羽衣是用火鳳凰全身的羽毛穿串而成,且非常輕.
LONG
     );
        set("unit", "件");
        set("value",0);
        set("material", "steel");
        set("limit_con",30);
        set("limit_lv",20);
}
        set("armor_prop/armor",16);
        set("armor_prop/con",1);
        set("armor_prop/str",1);      
        set("armor_prop/dex",1);         
        
        setup();
}

