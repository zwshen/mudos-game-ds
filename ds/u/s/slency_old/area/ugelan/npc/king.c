// Npc: /u/d/dragonku/npc/2.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY"國王"NOR, ({"Ugelan Lord","lord"}) );
	set("long", "他是幽遮蘭城的國王，也是幽遮蘭城的最高領導人。\n");
	set("title",HIW"【幽遮蘭帝國】"NOR);
 set("race", "人類");
	set("age", 50);
	set("level", 40);

	setup();
carry_object(__DIR__"wq/goldsword")->wield();
}
