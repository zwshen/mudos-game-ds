#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIY"黃"HIC"鋼"HIW"之"HIR"箭"NOR,({"yellow blue-bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "隻");
        set("long","由造箭名匠, 黃鋼所製, 此箭殺傷力大, 堅硬無比.\n");
        }
set("value", 10000);
set_weight(3000);
set("amount",30);                
set("bullet/damage",80);        
set("bullet/unit","隻");        
set("bullet/name",HIY"黃"HIC"鋼"HIW"之"HIR"箭"NOR);      
set("type","small");            
setup();
}

