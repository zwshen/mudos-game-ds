inherit NPC;

void create()
{
        set_name("大魚",({"big-fish","fish"}) );
        set("long","一條極肥美的大魚，正四處游動找尋食物。\n");
        set("race", "野獸");
        set("env/wimpy", 20);
        set("unit","條");
        set("age",4);
        set("level",3);
          set("attitude", "heroism");
      set("str",2);
      set("dex",1);
        set("limbs", ({ "頭部", "身體", "前鯕", "尾巴" }) ); //受攻部位
        set("verbs", ({ "bite" }) );                         //攻擊方式
        set("chat_chance",6);
        set("chat_msg",({
          (: this_object(),"random_move()":),
        }) );

        setup();
	add_money("coin",30);
}
