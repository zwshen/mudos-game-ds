#include <ansi.h>
#include <armor.h>
inherit CLOTH;
inherit F_UNIQUE;
void create()
{
set_name(HIW"天使羽衣"NOR,({"angel cloth","cloth"}) );
set("long",
"這是"HIR"天使"NOR"的衣服。\n"
);
        set_weight(2000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "件");
                set("value",1000000);
                set("limit_str",100);
                set("armor_prop/str",10);
                set("armor_prop/armor",50);
                set("armor_prop/show_damage",1);
        }
 set("replica_ob","/u/s/sonicct/test/Angel/angelcloth2.c");
        setup();
}
