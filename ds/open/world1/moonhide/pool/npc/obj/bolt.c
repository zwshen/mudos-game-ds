#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIR"爆烈之箭"NOR,({"bomb-bolt","bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "隻");
        set("long",HIR"竭達羅所製之箭，殺傷力強大。\n"NOR);
        }
set("value", 8000);
set_weight(2000);
set("amount",30);                
set("bullet/damage",200+random(111));        
set("bullet/unit","隻");        
set("bullet/name",HIR"爆烈之箭"NOR);      
set("type","small");            
setup();
}

