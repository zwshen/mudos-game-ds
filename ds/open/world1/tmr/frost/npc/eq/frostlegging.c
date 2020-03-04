#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(HBK"´Hº«Å@»L"NOR ,({ "frost legging","legging" }) );
        set("long","´Hº«¬£Æ[¥D©Ò¬ïÀ¹ªºÅ@»L¡C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "skin");
                set("unit","Âù");
                set("value",2000);
                set("volume",1);
                set("armor_prop/armor", 5);
        }
        setup();
}
