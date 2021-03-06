#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("陽婆婆", ({ "grandmother yan","yan" }) );
  set("gender", "女性" );
  set("long",@LONG
別看她老了，她作的菜可是一流水準，可惜近來聽力大退
什麼事都記不清了。
LONG
);      
  set("age",95);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"陽婆婆突然回頭瞪了你一眼。\n",
(: command("say 嗯..嗯... 啊..啊...") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  set("mirror_number",3);
  call_out("re_quest",900);
}

void init()
{
  add_action("do_no_ask","ask");
  add_action("do_shout","shout");
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

int do_shout(string str)
{
  if(!str) str = "...";
  if(strsrch(str,"杖") !=-1)
    command("say 一把竹製的綠色柺杖呀，快去幫我找來。");
  if(strsrch(str,"呷飯") !=-1)
  {
    message_vision(HIR"$N在$n的耳邊大吼: "+str+"\n"NOR,this_player(),this_object());
    command("say 啊，對啊，呷飯的時間到啦。");
    if(query("item_give")) return 0;
    new(__DIR__"obj/obj20")->move(this_object());
    command("give " +this_player()->query("id")+ " rice ball");
    this_object()->set("item_give",1);
    return 1;
  }
  return 0;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N突然回頭又瞪了你一眼。\n",ob);
  else command("say 誰拿了我的柺杖啊？呵唷，老骨頭不中用了，沒柺杖不行囉。");
  return 1;
}

void relay_say(object me, string str)
{
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  switch(random(3))
  {
    case 0 : command("say 啊∼∼？什麼？");
             break;
    case 1 : command("say 啊？你說啥呀？");
             break;
    case 2 : command("say 什麼∼∼？呷飯？");
             break;
  }
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 什麼∼？"+ob->name(1)+"？這係啥碗糕∼∼？");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") != "bamboo stick" )
  {
    command("?");
    write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say 好好好，年輕人，我老人家就收下了。");
    return 1;
  }
  call_out("wield_temp",2,ob,0);
  command("say 唉呀，你找到我的柺杖了嗎？好好，這個東西給你吧。");
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  return 1;
}

void wield_temp(object ob, int index)
{
  if(!this_object()) return;
  switch(index)
  {
    case 0 : command("wield stick");
             break;
    case 1 : command("hmm");
             break;
    case 2 : command("unwield stick");
             break;
    case 3 : tell_room(environment(this_object()),"陽婆婆把柺杖收到裡面去了。\n");
             destruct(ob);
             break;
  }
  if(is_fighting())
  {
    remove_call_out("wield_temp");
    ob->set_temp("broken",9);
    return;
  }
  else
  {
    index++;
    if(index<4) call_out("wield_temp",2,ob,index);
  }
  return;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  call_out("re_quest",900);
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
