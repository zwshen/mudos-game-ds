// Npc: /u/a/alickyuen/npc/2.c

inherit NPC;

void create()
{
	set_name("小孩子", ({"child"}) );
	set("long", "一個受了傷的小孩，他正在病床上休息。\n");
	set("race", "人類");
	set("age", 12);
	set("level", 10);

	setup();

}
