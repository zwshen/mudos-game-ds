#include <armor.h>
#include <ansi.h> 
inherit FINGER;

void create()
{
        set_name(HIY"守護者"NOR"之戒"NOR,({"ring of guard","ring"}) );
        set("long","這個指環被五彩光點覆蓋\著，上面顯現出金黃色的細密線條。線\n"
                   "條彎曲著、環環重疊，如同梵文。\n");
        set_weight(500);
        if ( clonep() )
        set_default_object(__FILE__);
else
{
                set("volume",3);
                set("unit","只");
                set("value",4500);
}
               set("armor_prop/armor",4);
               set("armor_prop/bio",1);
               set("armor_prop/wit",-1);
               setup();
}

