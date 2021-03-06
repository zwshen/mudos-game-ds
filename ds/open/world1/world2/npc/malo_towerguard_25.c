inherit NPC;
void gun_handle();
void create()
{
	set_name("瞭望塔隊長",({"tower leader","leader"}) );
	set("long",@LONG
他就是這裡的瞭望隊長，身材壯碩但卻有對長短腿，走起路來一跛一
跛的，但是兩眼炯炯有神，看起來十分幹練。 
LONG);
	set("age",37);
	set("level",25);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","這裡不是你應該來的地方，快出去。");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: gun_handle :)
	}) );
	setup();
	set_skill("gun",80);
	set_skill("perception",80);
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/gun_21")->wield();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_pants_9")->wear();
	carry_object(__DIR__"../eq/iron_armor_21")->wear();
	carry_object(__DIR__"../eq/iron_boots_10")->wear();
	carry_object(__DIR__"../eq/iron_leggings_7")->wear();
	carry_object(__DIR__"../eq/iron_helmet_8")->wear();
	carry_object(__DIR__"../eq/iron_roundshield_7")->wear();
	carry_object(__DIR__"../eq/glasses_night_2")->wear();
	add_money("dollar",3250);
}

void gun_handle()
{
	object gun;
	gun=present("ck rifle",this_object());
	if(!gun) return;
	if(!gun->query_temp("loaded"))
	{
		command("reload clip");
		return;
	}
	command("shoot");
	return;
}