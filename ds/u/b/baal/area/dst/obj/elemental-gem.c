#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"元素法珠"NOR,({ "element gem","gem" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
這是一顆不怎麼起眼的法珠, 但是當你將它拿近眼睛細看時, 可
以看見不時有閃電在其中跳動, 以及火燄的奔騰, 但最令你感到
奇怪的是, 它的外部竟然結了一層薄薄的霜, 當你將它握手中時
似乎可以感到大自然內元素的力量正在你手中跳耀...
LONG
);
                set("unit","顆");
        }
        setup();
}


