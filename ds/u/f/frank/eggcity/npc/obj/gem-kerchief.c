#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIR"寶石頭巾"NOR ,({ "gem kerchief","kerchief" }) );
        set("long","一條金色的絲綢，上面鑲了幾顆寶石，看起來十分的高檔歐。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","條");
                set("value",4000);
                set("volume",2);
                set("armor_prop/armor", 10);
                set("armor_prop/int", 2);
                        }
        setup();
}

