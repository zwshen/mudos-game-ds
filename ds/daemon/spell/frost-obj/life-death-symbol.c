#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("生死符", ({ "life death symbol", "symbol", "__LIFE_DEATH_SYMBOL_"}) );
          set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一片寒澈道觀獨有的生死符，實質上是一片液體做成的薄冰片。");
                set("unit", "堆");
                set("base_unit", "片");
               set("value", 1);
        }
       set("power",1);
       set_amount(1);
       init_throwing(10);
       setup();
}

void init() {
        set("power", this_player()->query_spell("life-death-symbol") );
}

