#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("飛天鞋", ({ "flying shoes","shoes" }) );
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"很輕很輕的鞋子，只要你輕功夠好，輕輕一躍就能摸到月亮•\n");
                set("unit", "雙");
                set("material", "fur"); 
                set("value",1400);                set("armor_prop/shield",9);
                set("armor_prop/armor",9); 
                set("armor_prop/dex",1);
        }
        setup();
}

