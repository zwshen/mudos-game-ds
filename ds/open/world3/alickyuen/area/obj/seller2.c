#include <ansi.h>
inherit ITEM;
inherit SELLMAN;

void create()
{
        set_name(HIY"武器售賣機"NOR, ({ "selling machine","machine"}));
        set("long","這是一部售賣機,可以打list去看看有什麼東東賣。\n");
        set("sell_list",([
// __DIR__"wp/nopsword.c" : 10,
// __DIR__"wp/fist.c" : 10,
__DIR__"wp/gun.c" : 10,
// __DIR__"wp/dagger.c" : 10,
__DIR__"wp/clip.c" : 10,
        ]) );
set_weight(99999);
                set("no_get",1);
                set("no_sac",1);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
