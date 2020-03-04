inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("瞭望塔警衛",({"tower guard","guard"}) );
	set("long",@LONG
一個年輕的瞭望隊員，正在這裡巡邏。
LONG);
	set("age",26);
	set("level",19);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","這裡不是你應該來的地方，快出去。");
	setup();

	carry_object(__DIR__"../wp/iron_blade_16")->wield();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_pants_7")->wear();
	carry_object(__DIR__"../eq/iron_armor_16")->wear();
	carry_object(__DIR__"../eq/iron_boots_9")->wear();
	carry_object(__DIR__"../eq/iron_leggings_7")->wear();
	carry_object(__DIR__"../eq/iron_helmet_8")->wear();
	add_money("dollar",840);
}
