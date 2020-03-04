#include <weapon.h>

inherit F_WHIP;

void create()
{
        set_name( "蔓生長鞭" , ({ "creeper whip" , "whip" }) );
        set_weight(6000);
        setup_whip( 2 , 10 , 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"whip"}));
                set("unit", "條");
                set("value" , 5000);
                set("long", 
"這是一條由蔓生植物所編成的長鞭，長達數丈，質地堅硬。"
                );
        }
        setup();
}
