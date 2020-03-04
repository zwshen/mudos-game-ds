inherit NPC;
inherit SHOPMAN;

void create()
{
        set_name("波斯生意人", ({ "persian seller", "seller" }));
        set("gender", "男性");
        set("age", 40 + random(10));
        set("long", "一個精明的波斯生意人。高鼻藍眼的, 看著你臉上露出狡詐的笑容。\n");
        set("attitude", "friendly");
        setup();
        set("no_kill", 1);
        set("chat_chance", 5);
        set("chat_msg", ({
"波斯生意人對你狡詐地擠了一下眼睛。\n",
        }));
        set("storeroom",__DIR__"shop_room");
        carry_object(__DIR__"obj/wandao")->wield();
        setup();
}


void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}

