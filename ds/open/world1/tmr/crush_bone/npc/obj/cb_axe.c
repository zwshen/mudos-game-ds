#include <weapon.h>
#include <ansi.h>

inherit AXE;
inherit F_UNIQUE; // only one

void create()
{
        set_name( HIW "碎骨" NOR, ({ "crush bone axe","axe" }) );
        set_weight(12000);
        init_axe(77);

        if( !clonep() ) {
                set("unit", "把");
                  set("value" ,10000);
                set("long",@long
碎骨是一把十分巨大的斧頭，相傳在數百年前，由天空落下塊非常奇
特的礦石，質地堅硬勝過這世界上存在的任何礦物，而且非常地重。最後
是由碎骨寨中數百個強壯的半獸人們，歷經數年的時間才將此礦石打造成
一把巨斧，最後也就變成碎骨寨中流傳數代的寶物。
long
        );
        set("replica_ob",__DIR__"huge-axe");
        set("material","iron");
        set("weapon_prop/str", 6);
        set("weapon_prop/damage", 10);
        set("limit_str", 40);
        set("limit_level",40);

        } else 
                     set_default_object(__FILE__);

        setup();
}

