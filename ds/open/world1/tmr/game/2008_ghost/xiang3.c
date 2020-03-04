#include <ansi.h>
inherit ITEM;

string getLong()
{
        return sprintf("大士爺香燭(dashi pudu xiang) [香火 %d 份]",query("time") );
}

void create()
{
        set_name(HIY "大士爺香燭" NOR,({"dashi pudu xiang", "xiang", "_GHOST_XIANG_"}) );
        set("long",@LONG
相傳舊曆七月，所有在陽世的亡靈，都歸「大士爺」管理。這位神祇的來由有二：
一是祂是觀音大士的化身，故稱「大士爺」。二是祂原為諸鬼的首領，因受觀音
大士教化而皈依其門下，從此被稱作「大士爺」，成為護持中元普渡事項的神明。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","份");
        }
        set("value", 100);
        set("time", 1000 + random(1000) );
    
        setup();
        set("long", query("long") + getLong() );
}

