
inherit NPC;
void make_mark();

void create()
{
	set_name("奧凡迪斯市長",({"mayor"}) );
	set("long",
"這位市長市相當的愛他的市民的，和藹可親的笑容讓你覺得他是位好市長。\n"
	);		
	set("age",45);
	set("level",20);
	set("attitude", "heroism");
	set("race","人類");
	set("evil",-20);
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 歡迎來到奧凡迪斯，這是座美麗的城市，請盡興的玩吧！"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(:command("say 救命啊，有人造反了！！"):),
		(: make_mark :),
	}) );
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("unarmed",50);

	setup();

	carry_object(__DIR__"eq/redglazedring")->wear();
	add_money("dollar",50);
}


void make_mark()
{
	object *enemy, ob;
	command("say 哇！救命阿！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你是奧凡迪斯的敵人。");
	ob->add_temp("quest/aovandis",3);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
