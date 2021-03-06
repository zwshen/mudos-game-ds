#include <ansi.h>
inherit NPC;

void create()
{
  set_name("北條", ({ "houjou"}));
  set("long",@long
一位長像老實的農人，正在田裡工作。
long);      
  set("gender", "男性" );
  set("age",35);
  set("level",16);
  set("race","human");
  set("talk_reply","田裡路滑，小心點走，南邊的草地有時會有蛇出沒，最好\n"
                  +"別去亂翻草叢。\n");
  set("chat_chance", 10);
  set("chat_msg", ({
      "北條從懷中拿出一張破紙擦去臉上的汗。\n",
      "北條辛苦地將田溝中的汙泥挖到一旁。\n",
      "北條看了你一眼，鞠躬說道：您好。\n",
      "北條自語道：母親長年臥病在床，據說"HIW"人魚肉"NOR"可以治百病，可到哪尋呢？。\n",
      (:command("sigh"):),
     }));
  set("inquiry/人魚肉","就是人魚身上的肉，聽說有人在河堤看見過人魚。\n");
  setup();
  add_money("coin",50+random(50));
}

int accept_object(object who,object ob)
{
  object obj,page,env;
  obj=this_object();
  env=environment(obj);

  if(ob->query("id") == "ningyo meat")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" 我沒空，別來煩我。\n");
      return 0;
    }
    message_vision("$N拿給北條一塊 "+ob->query("name")+"。\n",who);
    command("really");
    message_vision("北條說道：太好了，母親有救了。\n\n",who);
    page=new_ob(__DIR__"eq/surcoat-design-page");
    page->move(env);
    tell_room(env,"（北條拿著人魚肉匆匆地走了，匆忙中從口袋掉落一張紙。）\n");
    destruct(obj);
    return 1;
  }
  return 0;
}
