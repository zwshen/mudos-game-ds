inherit NPC;

void create()
{
  set_name("小孩", ({ "child" }) );
  set("gender", "男性" );
  set("long",@long
天真純樸的小孩子，正在一旁玩耍著。
long
);      
  set("age",6);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"小孩叫道： 哇∼∼∼\n",
(: command("say 娘吩咐我不能到南邊的沙漠玩，那裡有吃人的狼唷。") :),
(: command("say 上一次我去找書僮玩，他給我看他的寶物喔，是一片閃閃發亮的鏡子耶，上面還寫了一個『坤』字喔。") :),
(: command("say 我也給他看我的寶物，就是我自己作的面具，你看！嘻嘻嘻！") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
 (: command("say 你打我∼∼嗚∼我要跟娘說去!") :),
}) );
  setup();
  add_money("coin",100);
  carry_object(__DIR__"eq/eq15")->wear();
}
