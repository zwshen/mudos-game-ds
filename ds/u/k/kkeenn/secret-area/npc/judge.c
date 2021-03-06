#include <ansi.h>
#include <command.h>
inherit NPC;
int do_divorce2(string index);
object ppl2, ppl1;

void create()
{
  set_name(HIW"大法官"NOR, ({ "big judge","judge" }) );
  set("gender", "男性" );
  set("age", 28);
  set("long",@LONG
他是國際法庭的大法官，專司男女之間的情事，他的觀念十分開放
不論是男方或女方，他一律一視同仁，為人正直，所以在他二十八
歲的時候，就當上了國際法庭少數的執法者之一，他最常審理的事
便是男女的婚事，不過普通的結婚並不需要請他，大部分請他都是
為了要離婚.....(divorce 人)
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
  (: command,"say 男女之間...相處不好就該分開..." :),
  (: command,"sigh" :),
  (: command,"say 不要太勉強...想離就離吧.." :),
  (: command,"sob" :),
     }));
  set("level",1);
  set("attitude", "friendly");
  set("no_cast",1);
  set("no_kill",1);
  setup();
}

void init()
{
  seteuid(getuid(environment()));
  if(!userp(this_player())) return;
  add_action("do_divorce","divorce");
  add_action("do_yes",({"y"}));
  add_action("do_yes",({"yes"}));
  add_action("do_no",({"no"}));
}
int do_divorce(string str)
{
  object target, temp, ob = this_object(), me = this_player();

  if(query("divorcing")) return notify_fail("她似乎正在忙.\n");

  message_vision(HIC"$N說：$n，我想煩請您幫我辦理離婚事項吧。\n"NOR,me,ob);
  if(me->query("bank/future") < 15000)
  {
    command("snort");
    command("say 本法官是需要收訴訟費的。");
    write("[您銀行存款至少要有 15000 枚電子幣。]\n");
    return 1;
  }
  if(!str)
  {
    command("say 哦？被告是誰？可有他的名字麼？");
    return 1;
  }
  if(!target = find_player(str))
  {
    command("hmm");
    command("say 好像沒這位朋友喔，您請回吧。");
    return 1;
  }
/*
  if(!target = me->query("marry_id"))
  {
    command("hmm");
    command("say 朋友....這位朋友是你的配偶嗎？");
    return 1;
  }
*/
  if(userp(target) && environment(target) == environment(ob))
  {
    ppl1 = me;
    ppl2 = target; 
    set("divorcing",1);
    command("hmm");
    call_out("do_divorce1",3);
    return 1;
  }

  command("say 你是說 "+str+" 嗎？帶她來這裡，我會為你主持公道的。");
  command("snicker");
  return 1;
}

void do_divorce1()
{
  object ob = this_object();
  string index;

  if(environment(ppl1) != environment(ob))
  {
    command("flop");
    command("say 主告跑了，這件事情就算了。");
    delete("divorcing");
    delete("asking");
    return;
  }
  if(environment(ppl2) != environment(ob))
  {
    command("??");
    command("say 這位被告怎麼一轉眼就不見了？");
    delete("divorcing");
    delete("asking");
    return;
  }
  command("look "+ppl2->query("id"));
  command("say 果然是....待我詢問被告。");
  tell_object(ppl2,HIC+ppl1->name(1)+"提出離婚申請，請問你同意嗎？ [yes/no]\n"NOR);
  set("asking",1);
  return;
}

int do_yes()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("y");
    return 1;
  }
  return 0;
}

int do_no()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("n");
    return 1;
  }
  return 0;
}

int do_divorce2(string index)
{
  object ob = this_object();
 object obj1,obj2;
  if(index == "y")
  {
    message_vision(HIR"\n[$N大方的說: 無所謂！處不來就離婚吧！]\n\n"NOR,ppl2);
    command("say 太好了！被告同意了！真是恭喜你們！");
    if(ppl1->query("bank/future") < 10000)
    {
      command("say 那關於訴訟費的事....");
      command("flop");
      command("ack");
      command("say 原來是窮光蛋?! 本官看走眼了，既然如此這件事情就算了吧。");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    if(environment(ppl1) != environment(ob))
    {
      command("flop");
      command("say 原告跑了，這件事情就當沒提過吧。");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    if(!objectp(obj1 = present("marry ring", ppl1)))
    {
      command("flop");
      command("say "+ppl1->name(1)+"，你的結婚戒指呢？");
      return 1;
    }
        if(!objectp(obj2 = present("marry ring", ppl2)))
    {
      command("flop");
      command("say "+ppl2->name(1)+"，你的結婚戒指呢？");
      return 1;
    }

    message("system",
HIR"\n\t國際法庭之大法官對眾宣佈道：
\n\n\t\t"HIC"『公告"+ppl1->name(1)+"和"+ppl2->name(1)+"因為相處不合，本官正式取消他倆的婚姻關係！』\n\n"NOR,users());

    ppl1->delete("marry_id");
    ppl2->delete("marry_id");
    ppl1->add("bank/future",-10000);
    tell_object(ppl1,HIG"[大法官跟您收了 10000 枚電子幣當訴訟費。] \n"NOR);

    if(objectp(obj1 = present("marry ring", ppl1)))
    {
        message_vision(HIG"[大法官從你身上搜出一只結婚戒指]\n"NOR, ppl1);
        destruct(obj1);
    } 
    if(objectp(obj2 = present("marry ring", ppl2)))
    {
        message_vision(HIG"[大法官從你身上搜出一只結婚戒指]\n"NOR, ppl2);
        destruct(obj2);
    } 

    ppl1->save();
    ppl2->save();
    delete("divorcing");
    delete("asking");
    return 1;
  }
  message_vision(HIC"\n[$N堅決的搖了搖頭]\n\n"NOR,ppl2);
  command("say 被告不同意耶，那就算了，這件事就到此為止吧。");
  delete("divorcing");
  delete("asking");
  return 1;
}

void reset()
{
  delete("divorcing");
  delete("asking");
  command("say 你來的不巧，今天公休日，想離婚明天趁早。");
}

