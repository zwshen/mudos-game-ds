#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
  set_name(HIW"大哥寶劍"NOR, ({ "boss sword","sword"}) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是把大哥專用的武器。\n");
                set("value", 400);
                set("material", "platminum");
        }
    init_sword(5000);
        setup();
}

