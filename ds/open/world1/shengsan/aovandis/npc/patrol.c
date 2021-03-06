inherit NPC;

void create()
{
	set_name("巡邏警衛",({"patrol"}) );
	set("long","一個警衛正在這裡巡邏。這個警衛充滿了正義感。\n");		
	set("age",30);
	set("level",24);
	set("race","人類");
	set("evil",-5);
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 嗯？奇怪，我心愛的警犬跑到哪去了呢？"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我，巡邏警衛，要將作亂者就地正法！！"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("staff",70);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	carry_object(__DIR__"wp/patrolbaton")->wield();
	carry_object(__DIR__"eq/patrolarmor")->wear();

	add_money("coin",50);
}