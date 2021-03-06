#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("街頭小販",({ "street seller","seller","street","小販" }));
	set("long",
		"這是專門在街道上販賣物品的小販，他可能有最新的東西。\n"
		"你可以向他詢問尚無存貨(list)或購買(buy)。\n");
	set("level", 5);
	set("age",10);

	set("no_fight",1);

	set("chat_chance", 8);
	set("chat_msg", ({
  "街頭小販大聲的說: 來喔來喔,火把大特價 ∼。\n",
  "街頭小販在向路人介紹所賣的物品。\n",
}));
	set("sell_list",([
  ALWAYS+"torch": 6,
  __DIR__"obj/orange": 20,
]));
	setup();
	add_money("coin",150);
}
void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
}
