#include <ansi.h>
inherit NPC;
void create()
{
set_name(RED "吸血"NOR"小孩", ({"bloodsucker-child"}) );
set("age",30);
set("long","這是秦始皇從地獄招喚上來的怪物，不但喜歡吸人血
，還喜歡吃人肉，看形體好像只是一個小孩子。\n");
set("attitude", "aggressive");
set("level",15);
setup();
}

