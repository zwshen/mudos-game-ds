// 2006/12/14

#include <ansi.h>
inherit __DIR__"cannon_base.c";

int do_wehre();

void create()
{
        set_name("頂級沖天炮",({"top cannon","cannon"}) );
        set("long",@long
夢幻七域２００６聖誕節活動－獵殺聖誕老人之頂級沖天炮。
你可以使用ignite的指令來點燃發射沖天炮。
long
);
        set_weight(10);
        set("unit","根");
        set("value",3000);
        set("min", 20);
        set("max", 40);
        setup();
}

