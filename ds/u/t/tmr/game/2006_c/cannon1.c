// 2006/12/14

#include <ansi.h>
inherit __DIR__"cannon_base.c";

int do_wehre();

void create()
{
        set_name("甲級沖天炮",({"first cannon","cannon"}) );
        set("long",@long
夢幻七域２００６聖誕節活動－獵殺聖誕老人之丙級沖天炮。
你可以使用ignite的指令來點燃發射沖天炮。
long
);
        set_weight(10);
        set("unit","根");
         set("value",1000);
        set("min",10);
        set("max",20);
        setup();
}

