#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIW"魔術師手套"NOR,({"mage gloves","gloves"}) );
        set("long",@long
魔術師所戴的手套，蠻好看的。
long
);
        set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
else
{
                set("volume",3);
set("unit","雙");
                set("value",10000);
                set("limit_lv",50);
                set("armor_prop/str",5);
                set("armor_prop/armor",10);
                set("armor_prop/show_damage",1);
}
setup();
}
int query_autoload() { return 1; }
