#include <room.h>
inherit ROOM;
void create()
{
 set("short","花崗迴廊");
 set("long",@LONG
你已經走到了花崗回廊最底了, 腳下的花崗岩漸漸埋進了塵土
之中, 四周壁上也漸漸出現了一些花叢草木, 你往出口望去發現外
面似乎是向雲堂的後山? 不過你現在才發覺出口站了四名壯漢, 要
出去似乎不太容易....
LONG
    );
 set("exits",([
               "south":__DIR__"hall2",
               "north":__DIR__"mount11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
