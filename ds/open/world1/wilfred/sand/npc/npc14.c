inherit NPC;

void create()
{
  set_name("鎮民", ({ "villager" }) );
  set("gender", "男性" );
  set("long",@long
黃沙鎮的居民，平時喜歡跟鄰居們聚在一起聊天。
long
);      
  set("age",30);
  set("level",7);
  set("con",8);
  set("race","human");

  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say 你好！歡迎來到黃沙鎮。") :),
(: command("say 聽說天機老人最近要回到磐龍山耶，可是好像要有八卦鏡才成，至於其中細節，我就不清楚了。") :),
(: command("say 天機老人的八卦鏡上次在黃沙道上弄丟了，碎成了好幾片，現下不知流落到何方。") :),
(: command("say 唉！陽婆婆他老人家的聽力真是越老越不行了，每次跟他說話總得大喊大叫一番，真令人擔心。") :),
(: command("say 聽說那個異國來的本因坊秀策在教人下圍棋耶，我也要讓我的孩子學，學圍棋的小孩不會變壞。") :),
(: command("say 黃沙幫那群匪類最近真是猖狂無比，除了攔路打劫外，還到滄縣搶錢莊，真是可惡至極。") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
(: command("say 難道你就是黃沙幫的人嗎？適才言語多有不敬，大爺饒命哪...") :),
}) );
  setup();
  add_money("coin",200);
}
