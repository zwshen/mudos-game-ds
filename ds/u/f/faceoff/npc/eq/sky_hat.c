#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(MAG"朱雀戰盔"NOR ,({ "sky hat","hat" }) );
        set("long","這是傳說中上古時代女媧所帶的金屬製盔, 但普天之下卻沒有
一個人可以鑑定它的製造材質, 所以只能說是上天傳下的金屬了....。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("armor_prop/armor",  9);
                set("armor_prop/shield",  20);
                set("value", 2300);
        }
        setup();
}