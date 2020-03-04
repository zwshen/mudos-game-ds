#include <ansi.h>
inherit NPC;
void create()
{
	set_name("安老大",({"admin annihilator","annihilator","admin"}) );
	set("long",@LONG
他是泥巴幫的老大，玩泥巴的功夫已經達到神鬼莫測的境界了。
LONG);
	set("age",29);
	set("title",HIY"泥巴教父"NOR);
	set("level",19);
	set("race","human");
	set("evil",10);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","我正在進行Neolith計劃，你可以上網來看看 http://es2.muds.net/。");
	setup();
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10");
	carry_object(__DIR__"../wp/rock_throw_10")->wield();
	carry_object(__DIR__"../eq/cloth_walkshoes_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",1290);
}

void die()
{
	message_vision("$N臨死之前說: 打死我看你們以後還有沒有泥巴可以玩!!\n",this_object());
	::die();
}
