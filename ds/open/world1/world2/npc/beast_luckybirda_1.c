inherit NPC;
void do_flee();
void create()
{
	set_name("[1;31m¬õ«a©¯¹B³¾[0m", ({"red lucky bird","bird"}) );
	set("long",@LONG
¶Ç»¡¤¤ªº¬õ«a©¯¹B³¾¡A¬õ¦âªºÀY¤W©ñ®gª¬ªºªø¤F¤@¨Ç¯S§Oªº¬õ¦âªø¦Ð
¡A§Îª¬¦ü«a¡A³oºØ³¾¤Q¤À¤Ö¨£¡A¶Ç»¡¥i¥H±aµ¹¤H©¯¹B¡C
LONG);
	set("unit","°¦");
	set("race", "beast");
	set("limbs", ({ "ÀY³¡", "¨­Åé", "Âù¨¬", "¯Í»H" })); //¨ü§ð³¡¦ì
	set("verbs", ({ "bite","poke" })); //§ðÀ»«¬ºAÃÞhoof¼²crash«rbite§ìclaw°Öpoke
	set("age", 1);
	set("int",50);
	set("str",5);
	set("con",5);
	set("max_hp",10);
	set("level",1);
	set("dex",50);
	set_temp("fly",1);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: do_flee :),
	}) );
	setup();
    	set("exp",200+random(4000));
	add_money("dollar",1000);
}
void do_flee()
{
	if(this_object()->query("hp")<1) return;
	message_vision("[1;31m$N[37m¬ðµM¤@­ÓÂà¨­¡A®¶¯Í°k¨«¤F¡C[0m\n",this_object());
	environment(this_object())->bird_fly();
	destruct(this_object());
}
