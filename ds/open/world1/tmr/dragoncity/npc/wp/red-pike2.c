#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit FORK;

void create()
{
        set_name( "丈二紅槍" ,({"red pike", "pike"}) );
        set("long",@LONG
燎原槍法是厲若海的成名絕技，而丈二紅槍則是他的專屬武器。
LONG
        );
        set_weight(8000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","桿");
                set("value",16000);
                set("volume", 2);
                 set("material", "gold");
                set("limit_level", 30);
        }
        set("replica_ob",__DIR__"red-pike2");
        set("weapon_prop/shield",5);
        set("weapon_prop/armor",5);
        set("weapon_prop/int", 1);
        set("weapon_prop/str", 1);
        init_fork(55);
        setup();        
}

