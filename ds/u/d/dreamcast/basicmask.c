#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIG"神"HIY"帝"BLU"鬼"HIW"面"NOR,({"Dreamcast mask","mask","gold mask"}) );
        set("long",@LONG
這是神帝戰鬥時臉上必戴的面具，有震懾敵人的效果•
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "個");       
                set("value",2000);          
                set("volume", 2);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/int",2);
        setup();
}

