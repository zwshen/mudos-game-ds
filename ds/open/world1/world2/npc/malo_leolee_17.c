inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("李鎮宇",({"leo lee","leo","lee"}) );
	set("long",@LONG
一個博士班學生，興趣是收集盜版軟體和交女朋友，正在引吭高歌。
LONG);
	set("age",26);
	set("level",17);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","喂，我在唱歌請不要說話。");
	setup();

	carry_object(__DIR__"../eq/cloth_clothes_8")->wear();
	carry_object(__DIR__"../eq/cloth_boots_7")->wear();
	carry_object(__DIR__"../eq/cloth_pants_9")->wear();

	add_money("dollar",540);
}

void init()
{
	object ob = this_player();
	::init();
	if(this_object()->is_fighting()) return;
	if(!this_object()->visible(ob)) return;
		call_out("greeting",1,ob);
	return;
}

void greeting(object ppl)
{
	if(!ppl) return;
	if(environment(ppl)==environment(this_object()))
	{
		if(random(2)) command("sing 讓我一次愛個夠");
		else command("sing 不要來∼汙辱我的美");
	}
	return;
}

void die()
{
	message_vision("$N臨死之前叫了一聲: I Will Be Back!!\n",this_object());
	::die();
}
