#include <ansi.h>
inherit NPC;

void flee();

void create()
{
  set_name("時空旅行者", ({ "time space traveler","traveler" }) );
  set("gender", "男性" );
  set("long",@long
一位奇裝異服打扮的怪人，四處張望著，不知在作什麼。
long
);      
  set("age",25);
  set("level",20);
  set("race","human");
  set("title",HIC"穿越時空的旅行"NOR);

  set_skill("dodge",80);

  set("chat_chance", 30);
  set("chat_msg", ({
"時空旅行不停的四處張望，好像對眼前的東西有莫大興趣的樣子。\n",
"時空旅行者拿起手腕上的東西，在空中比劃著。\n",
(: command("say 古代的建築物真是古拙雄奇，有一種超然之美....") :),
(: command("hmm") :),
(: command("tsk") :),
}));

  set("chat_chance_combat", 80 );        
  set("chat_msg_combat", ({
(: command("help!") :),
(: command("say 難道古代的人都這麼野蠻嗎 !!") :),
(: flee :),
}) );

  setup();
  carry_object(__DIR__"eq/eq6")->wear();
}

void flee()
{
  if(random(2) && this_player()->query("level") < 25) return;
  message_vision(HIW"\n$N突然拿出一個金色圓球，只見$N身後出現一道裂縫，$N跳進這裂縫之後不見了。\n\n"NOR,this_object());
  message_vision("你看得目瞪口呆，待在原地半晌作聲不得。\n",this_object());
  destruct(this_object());
}