#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIM"µµÃ¹³P¸Æ"NOR, ({ "purple kasaya","kasaya" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","¬Y°ª¹¬ÃØ°eµ¹«n®cµLÂùªº³P¸Æ!\n");
                set("unit", "¥ó");
        set("value",5000);
        set("material","fur");
        set("armor_prop/dex",1);
        set("armor_prop/int",1);
        set("armor_prop/dodge",4); 
        set("armor_prop/armor", 27); 
        set("limit_lv",25);
        set("limit_int",40);        }
        setup();
}


