#include <ansi.h>
inherit GAME_GIFT;

void create()
{
        set_name(HIW"天地任我"NOR, ({ "the world by me","world","me" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("level",3);
                set("unit", "片");
                set("long","天地任我，品質達"+query("level")+"顆星。(help gift)\n");
                }
        setup();
}
int query_autoload() { return 1; }

