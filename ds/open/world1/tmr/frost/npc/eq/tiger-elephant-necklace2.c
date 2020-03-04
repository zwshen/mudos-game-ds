#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name( CYN "虎象項鏈" NOR,({ "tiger-elephant necklace","necklace" }) );
        set("long",@LONG
虎象為道教四靈之一，二十八星宿中的西方七宿，而這
是一條從虎象身上取得的項鏈，色做白光，光彩奪目，隱隱
然有威武之意。
LONG
);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("volume",1);
                set("unit", "條" );
                set("value", 5000);
        }
         set("armor_prop/armor", 5);
         set("armor_prop/shield", 5);
           set("armor_prop/con", 2);

        setup();
}

