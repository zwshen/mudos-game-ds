#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIR "火"NOR"妖", ({"fire"}) );
set("long","這是一隻火之妖怪，看上去只是全身著火，但是火的熱度是上千度的，虛
幻的軀體加上千度的火燄，實在不是容易打的倒它。
\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
}

