#include <ansi.h>
inherit NPC;
void create()
{
set_name(RED "紅眼"CYN"蝙蝠"NOR, ({"blush-eye-bat"}) );
set("age",30);
set("long","這是一隻從天山飛下來覓食的蝙蝠，最喜歡的食物就是人肉了
，也是一種極少數的動物。\n");
set("attitude", "aggressive");
set("level",15);
setup();
}
