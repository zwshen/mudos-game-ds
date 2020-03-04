inherit NPC;

void create()
{
        set_name("旅客",({"traveler"}));
        set("long","一個從外地來的旅客，正站著湖邊，看著朝天湖的景色。\n");
        set("gender","男");
        set("attitude", "peaceful");
	set("age",20);
       set("level",2);
	set("race","人類");
        set("chat_chance",5);
        set("chat_msg",({
          "旅客喃喃說道：朝天湖百花齊開，真乃人間難得一見的美景啊。\n",
          "旅客拿起了酒壺喝了口「百花釀」，一臉滿足的樣子。\n",
         }) );
	setup();
	carry_object(__DIR__"eq/jade")->wear();
      add_money("silver",5);
}
int accept_fight(object who)
{
        if(!is_fighting())
        {
                say("旅客說道：「"+ RANK_D->query_respect(who) + "，今日難得風和日麗，正是遊玩的好日子，誰要和你打架啊！！」\n");
        }
        return 0;
}


