#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIY "冰"NOR"妖", ({"mine"}) );
set("long","這是五幻妖第三隻冰之妖怪，全身怖滿了一隻隻的冰刀，而且極度的低溫
，也是他的武器之一，也是一隻狠角色。\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
}
