// Npc: /u/s/slency/area/ugelan/npc/queen.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("皇后", ({"Ugelan Queen","queen"}) );
	set("long", "他是幽遮蘭城的王后，是國王的妻子, 看起來端莊溫雅, 很受人民的喜愛。\n");
	set("title",HIW"【幽遮蘭帝國】"NOR);
 set("race", "人類");
	set("age", 40);
	set("level", 20);

	setup();
carry_object(__DIR__"wq/silversword")->wield();
}
