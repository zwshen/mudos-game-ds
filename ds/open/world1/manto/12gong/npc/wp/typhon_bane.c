#include <weapon.h>
#include <ansi.h>
inherit GUN; 
void create()
{
set_name(HIG"³öÂ×¤§·´·Àªø¤}"NOR,({"typhon's bane","bow","bane"}));
set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",15000);
                set("unit", "§â");
                set("material","gold");
                set("limit_int",30);
                set("limit_dex",40);
                set("limit_level",35);
        }
        set("bullet_type","small");     
        set("max_load",10);     
        init_gun(55);   
        setup();

}

