#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIG"狡獪"HIW"之"HIM"裳"NOR, ({ "crafty cloth","cloth" }) );
        set_weight(1200);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long",HIC"\n此衣防禦力其佳，是古時代神魔大戰留下來的產物。\n"NOR);
                set("unit", "雙");
                set("value",5555);
                set("material","fur");
                set("armor_prop/str",2);
                set("armor_prop/int",1);
                set("armor_prop/dex",1);
                set("armor_prop/con",2);
                set("armor_prop/wit",-1);
                set("armor_prop/sou",1);
                set("armor_prop/tec",1);
                set("armor_prop/bar",-1);
                set("armor_prop/armor", 22);
                set("limit_lv",40);
                set("limit_str",50);
                set("limit_con",50); 
                set("limit_int",30);
                set("limit_dex",35);
        }
        setup();
}

