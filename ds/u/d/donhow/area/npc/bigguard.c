// Npc: /u/d/dragonku/npc/2.c

inherit NPC;

void create()
{
	set_name("護衛隊隊長", ({"bigguard"}) );
	set("long", "他是護衛隊隊長看來他是一位很強的人\n");
	set("race", "人類");
   set("age", 35);
    set("level", 20);

	setup();

}
