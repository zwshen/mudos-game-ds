#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIC"流光"NOR, ({ "flow light","light" }) );
        set_weight(6801);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","流光具有一些無法說明的法力,質地很輕防禦力卻很高。");
                set("unit", "件");
                set("value",10);
        }
        set("armor_prop/shield", 500);
        set("armor_prop/str", 50);
        set("armor_prop/con", 50);
        set("armor_prop/armor",500);
        set("armor_prop/int", 50);
        set("armor_prop/dex", 50);
        set("armor_prop/bar", 30);
        set("armor_prop/wit", 30);
        set("armor_prop/tec", 30);
        set("armor_prop/bio", 30);
setup();
}
int query_autoload() { return 1; }

