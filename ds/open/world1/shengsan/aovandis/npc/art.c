inherit NPC;

void create()
{
	set_name("亞特",({"art"}) );
	set("long","亞特是奧凡迪斯的守衛隊總司令，他的領導風格被其他守衛隊的成員所肯定。\n");		
	set("age",40);
	set("level",30);
	set("attitude", "heroism");
	set("race","人類");
	set("evil",-20);	// 邪惡度 -20 (正的表邪惡, 負表善良)
	set("exp_point",3);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 守護這座美麗的城市是我的責任！"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 17);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我，守衛隊總司令，要將作亂者就地正法！！"):),
	}) );
	set_skill("dodge",60);
	set_skill("block",60);
	set_skill("parry",50);
	set_skill("unarmed",50);
	set_skill("sword",80);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	set("inquiry/name","你好，我是奧凡迪斯的守衛隊總司令，名叫亞特");
	setup();

	carry_object(__DIR__"wp/artsword")->wield();
	carry_object(__DIR__"eq/drangonshield")->wear();
	add_money("coin",50);
}