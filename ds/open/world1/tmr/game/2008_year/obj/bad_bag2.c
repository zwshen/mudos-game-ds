#include <ansi.h>
inherit ITEM;
inherit __DIR__"bag_base";


void create()
{
        set_name(HIY"五鼠哭墓" HBK "兇袋" NOR,({"ominous bag", "bag", "__MOUSE_BAG__"}) );
        set("long",@LONG
這是一個充滿殺氣的兇袋，拿到它的人，一定會倒大霉。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
        }
        set("value", 100);
          set("happiness", 6 );
        setup();
}


