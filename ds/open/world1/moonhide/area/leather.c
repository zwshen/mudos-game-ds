#include <armor.h>
#include <ansi.h>
inherit CLOTH; 

void create()
{
        set_name(CYN"羽翼之衫"NOR,({ "leather cloth","cloth" }) );
        set("long","神鵰身上的毛皮，在神鵰死後，會自動脫落。\n");
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "件" );
        set("value",20000);
        }  
        set("armor_prop/armor", 10); 
        set("armor_prop/dodge",5); 
        set("armor_prop/bar",1);
        set("armor_prop/tec",1);
        set("armor_prop/bio",-1); // by ksj
        set("armor_prop/wit",-1); 
        set("armor_prop/str",-2);
        setup();
}
