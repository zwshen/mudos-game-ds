inherit NPC;
void create()
{
        set_name("胖強盜",({ "fat bandit","bandit" }));
        set("long",
                "這傢伙看起來一副凶巴巴的樣子, 一看就知道不是好貨,\n"
                "不過他現在不知道在找什麼, 似乎無視於你的存在。\n"
        );
        set("age",35+random(6));
	set("attitude", "peaceful");
        set("level",20+random(6));
	set("battlepoint",2);
        set("guild_gifts",({ 7,6,3,4 }));
	set("evil",5+random(6));
        set("chat_chance",5);
        set("chat_msg",({
  "胖強盜正在地上找些什麼, 不過什麼都沒找到。\n",
  "胖強盜說: 咦! 鑰匙(key)怎麼不見了..?\n",
  "胖強盜正在四處張望著, 不知道在看些什麼。\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "胖強盜說: 兄弟們! 上!\n",
  (: command("say 納命來 ~~~ ! \n") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/cutless")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
        add_money("silver",4);
}

int talk_action(object me)     
{
  object room;
  int a;
  a = random(6) + 1;
  if( !this_object()->query("talked") && !find_object("/open/world1/linjack/emperor/npc/obj/greenkey") ) {
     room = load_object("/open/world1/linjack/emperor/forest"+a+".c");
     command("emote 好像無視你的存在, 只說句: 快幫我找鑰匙(key)! 它一定掉在密林的某處了..!");
room -> set("item_desc",(["看起來怪怪的草堆":"這草堆中竟有一把鑰匙(key)!快把它撿(pick)起來吧!
\n"]));
     room -> set("active_action",1);
     this_object()->set("talked",1);
     return 1;
  }
  else command("emote 似乎沒理你..");
  return 0;
}

int accept_object(object me, object ob)
{
        object tob, herb,a;

        if( ob->query("id")!="grass green key" ) return 0;
        else {
                command("say 啊..鑰匙! 咦? 你是誰! 你這傢伙! 看刀!"); 
                command("kill "+me->query("id"));
        }
        return 1;
}
