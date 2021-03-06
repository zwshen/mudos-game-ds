
inherit NPC;

void create()
{
	set_name("巡官",({"sergeant"}) );
	set("long","他是奧凡迪斯裡的巡官。\n");		
	set("age",30);
	set("level",40);
	set("race","人類");
	set("guild_gifts",({3,4,8,5}));
	set("evil",-10);
	set("exp_point",4);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 這是座美麗的城市，請不要做出違法的事情喔！"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我身為巡官，一定要將作亂者就地正法！！"):),
		(:command("cast mindkill"):),
		(:command("cast mindkill"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_spell("mindkill",70);
	set_skill("staff",70);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	carry_object(__DIR__"eq/aihun_robe")->wear();

	add_money("coin",50);
}