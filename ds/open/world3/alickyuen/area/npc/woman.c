// Npc: /u/a/alickyuen/npc/2.c

inherit NPC;

void create()
{
	set_name("婦人", ({"woman"}) );
	set("long", "一個生病中的婦人，看起來很有錢的。\n");
	set("race", "人類");
	set("age", 36);
	set("level", 12);

	setup();

}
