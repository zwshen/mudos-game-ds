#include <ansi.h>
#include <armor.h>
inherit CLOTH;
 void create()
{
        set_name(HIR"天使羽衣"NOR,({"angel cloth","cloth"}) );
        set("long",@long
這是"HIR"天使"NOR"的衣服。
long
);
         set_weight(2000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "件");
                set("value",1000);
                set("limit_str",100);
                 set("armor_prop/armor",30);
        }
        setup();
 }
