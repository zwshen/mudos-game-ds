#include <ansi.h>
#include <armor.h>
inherit HANDS;
void create()
{
        set_name(HIW+BLK"闇"NOR+YEL"鱷"HIR"手甲"NOR ,({ "crocodile hands","hands" }) );
        set("long","一雙由闇夜巨鱷的皮所製成的手甲，穿在手上還隱約感到那條兇\n"
                   "猛的鱷魚傳來的力量。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(7000);
        set("material", "fur");
        set("unit", "雙" );
        set("value",20000);
        }
        set("limit_str",50); 
        set("limit_level",40);
        set("armor_prop/armor", 8);
        set("armor_type", "hands");
        set("armor_prop/bar",1); 
        set("armor_prop/wit",-1); 
        set("armor_prop/bio",-1); 
        set("armor_prop/tec",1); 
        set("armor_prop/dodge",-5); 
        set("armor_prop/con",1);
        set("armor_prop/str",4);
        setup();
}
