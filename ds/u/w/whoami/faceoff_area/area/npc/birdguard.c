// dog.c

inherit NPC;

void create()
{
	set_name("野狗", ({ "dog" }) );
	set("race", "野獸");
	set("age", 3);
     set("level",2);

        set("long", "一隻渾身髒兮兮的野狗，看了令人生憐。\n");
	
   set("str",1);
      set("max_hp",10);
    set("dex",-3);
     set("int",1);
       set("con",1);

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"野狗用鼻子聞了聞你的腳。\n",
		"野狗在你的腳邊挨挨擦擦的﹐想討東西吃。\n",
		"野狗對著你搖了搖尾巴。\n",
		"野狗用後腿抓了抓自己的耳朵。\n" }) );
		

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "高興地汪汪叫了起來。\n", environment());
		return 1;
	}
}
