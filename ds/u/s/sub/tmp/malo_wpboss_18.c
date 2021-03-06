#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("武器店老闆" , ({ "shop boss","boss" }));
	set("long",@LONG
  印入眼簾的是一個滿身大汗的赤膊壯丁，不停的用脖子上的毛巾擦
  著汗，胸口還有一些焦痕。
	==========================
	武器清單	list
	購買武器	buy <武器>
	試用武器	try <武器>
	==========================
LONG);
	set("race","human");
	set("gender","男性");

	set("sell_list",([
  __DIR__"../wp/wood_axe_5" : 5,
  __DIR__"../wp/wood_blade_5" : 5,
  __DIR__"../wp/wood_dagger_5" : 5,
  __DIR__"../wp/wood_fist_5" : 5,
  __DIR__"../wp/wood_fork_5" : 5,
  __DIR__"../wp/wood_hammer_5" : 5,
  __DIR__"../wp/wood_staff_5" : 5,
  __DIR__"../wp/wood_sword_5" : 5,
  __DIR__"../wp/wood_whip_5" : 5,
  __DIR__"../wp/iron_axe_10" : 10,
  __DIR__"../wp/iron_blade_10" : 10,
  __DIR__"../wp/iron_dagger_10" : 10,
  __DIR__"../wp/iron_fist_10" : 10,
  __DIR__"../wp/iron_fork_10" : 10,
  __DIR__"../wp/iron_hammer_10" : 10,
  __DIR__"../wp/iron_staff_10" : 10,
  __DIR__"../wp/iron_sword_10" : 10,
  __DIR__"../wp/skin_whip_10" : 10,
  __DIR__"../wp/rock_throw_10" : 2,
]));
	set("age",37);
	set("level",18);
	set("no_fight",1);
	setup();
	add_money("dollar", 270);		//帶的錢(coin古代,dollar現代,未來沒有)
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/leather_gloves_5")->wear();
//	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_hat_4")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_try","try");
}

