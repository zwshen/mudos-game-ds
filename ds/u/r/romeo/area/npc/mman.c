#include <ansi.h>
inherit NPC;
void create()
{
set_name("骷髏人", ({"man"}) );
set("age",30);
set("long","一具全身灰白的骷髏，看起來毫不起眼，這應該不是秦始皇所
招喚的才對，但是看它陰陰的笑，背後好像藏有玄機。\n");
set("attitude", "aggressive");
set("level",15);
setup();
}

