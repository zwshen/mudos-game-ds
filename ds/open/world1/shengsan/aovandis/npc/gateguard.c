
inherit NPC;

void create()
{
	set_name("城門守衛",({"guard","gate guard"}) );
	set("long","有一個守衛正在這裡監視著進出城門的可疑人物。\n");		
	set("age",25);
	set("level",25);
	set("race","人類");
	set("evil",-5);
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",10);
	set("chat_msg",({
		(:command("say 歡迎來到奧凡迪斯，這是座美麗的城市，請不要做出違法的事情喔！"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我身為城門守衛，要將作亂者就地正法！！"):),
	}) );
	set_skill("dodge",60);
	set_skill("block",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	set_skill("axe",40);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	carry_object(__DIR__"wp/typicalaxe")->wield();
	carry_object(__DIR__"eq/typicalshield")->wear();
	carry_object(__DIR__"eq/typicalboot")->wear();

	add_money("coin",50);
}