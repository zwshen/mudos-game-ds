// In room085.c 市立醫院
inherit NPC;

void make_mark();

void create()
{
	set_name("外科醫師",({"doctor"}) );
	set("long","她是一位美麗外科醫師，身懷救人的理想而努力著。\n");		
	set("age",28);
	set("level",20);
    set("con",14);
	set("race","人類");
	set("gender","女性");
	set("evil",-15);	// 邪惡度 -15 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 手術刀在我手上，是沒有不可能的事的！"):),
		(:command("smile"):),
		(:command("hi"):),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: make_mark :)
	}) );
	set_skill("dodge",60);
	set_skill("block",60);
	set_skill("parry",60);
	set_skill("unarmed",60);

	set("talk_reply","嗨，我晚上好寂寞喔。陪陪我吧。我的電話是0204777777。");
	setup();

	add_money("dollar",100);
}

void make_mark()
{

	object *enemy, ob;
	if( random(30)%2 )
		command("say 哇！你這個可惡的壞人，好痛喔！");
	else
		command("peace");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;
	
	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你是個魔鬼。");

	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記

	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
