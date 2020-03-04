#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name(HIR"熾炎"NOR""RED"血麟披"HIR"(S)"NOR,({ "blood-scale surcoat","surcoat" }) );
        set("long", @LONG
一件血紅的披風，披風以火蠶絲織成，上面交嵌火麒麟的鱗片，整件
披風燃燒著淡淡的火燄。
LONG
        );
        if ( clonep() )
                set_default_object(__FILE__);
        else {
         set_weight(1500);
         set("material", "leather");
         set("unit", "件" );
         set("value",20000);
         set("volume",3);
        }
        set("armor_prop/armor", 17);
        set("armor_prop/shield", 2);
        setup();
}

int query_autoload() { return 1; }
