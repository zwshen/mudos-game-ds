#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create() {
        set_name(CYN"魎脊"NOR, ({ "ghost bone", "bone" }) ) ;
        set ("long", @LONG
這是一隻用魎鬼的脊椎所製成的軟鞭.
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_dex",25);
        set("unit", "條");        
        set("value",800);
        set("volume",3);        
        set("material","blacksteel");       
              }        
        init_whip(36);
        setup();

}

