#include <ansi.h>
#include <armor.h>
inherit PANTS;
inherit F_UNIQUE;
void create()
{
set_name(HIR"天使長裙"NOR,({"angel skirt","skirt"}) );
        set("long",
"這是"HIR"天使"NOR"的長裙。\n"
);
set_weight(2000);
 if(clonep() )
        set_default_object(__FILE__);
         else
         {
                 set("unit", "件");
                 set("value",1000000);
set("limit_con",100);
                 set("armor_prop/armor",30);
         }
        setup();
 }
