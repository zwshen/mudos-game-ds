#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"九"HIY"尾"NOR"的皮"NOR,({ "fox fur","fur" }));
        set_weight(1500);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一張從九尾身上脫落的皮，你拿在手上還隱約感到些許\的魔力•\n");
                set("unit","張");
                set("value",1000);
                } 
                set("armor_prop/shield",1);
                set("armor_prop/armor", 5);
                set("wear_msg", "$N穿上一張$n，身體感到湧入無窮的力量！\n");
                set("unequip_msg", "$N脫下了$n，力量頓時全部流失了！\n");
                set("armor_prop/wit",1);
                set("armor_prop/bar",-1);
                set("armor_prop/int",2+random(2));
                setup();
}

