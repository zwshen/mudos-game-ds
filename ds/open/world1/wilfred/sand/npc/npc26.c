#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("窮書生", ({ "student" }) );
  set("gender", "男性" );
  set("long",@LONG
十年窗寒無人問，一舉成名天下知。他正努力的讀書，日後以求取好功名。
LONG
);      
  set("age",22);
  set("level",8);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"空氣中突然傳來窮書生肚子的咕嚕聲。\n",
(: command("say 我要好好努力讀書，將來考取官位後便不愁吃穿了... 家鄉的老父老母也會以我為榮..") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  set("mirror_number",2);
  carry_object(__DIR__"eq/eq8")->wear();
  call_out("re_quest",900);
}

void init()
{
  add_action("do_no_ask","ask");
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N拿起易經，搖頭晃腦的讀了起來。\n",ob);
  else command("say 好餓啊... 快餓死啦.. 想吃飯...");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"飯") != -1)
  {
    command("drool");
    command("say 陽婆婆作的飯團最好吃了∼∼好想吃喔∼∼");
  }
  if(strsrch(str,"易經") !=-1)
    command("say 易經是自古以來最偉大的鉅著啊.. 易經所言均為天地至理，萬物相生相剋，四時節氣，都脫不了易經所闡述之範疇。");
  if(strsrch(str,"給") !=-1 && strsrch(str,"易經") !=-1)
  {
    if(ob->query_temp("item_give"))
      command("say 我本來是有多一本易經的，不過己經給"+ob->query_temp("item_give_who")+"了，你有興趣可以找他要。");
    else
    {
      command("say 好吧，既然你對易經這麼有興趣，我就給你一本吧。");
      new(__DIR__"obj/obj3")->move(ob);
      command("give "+me->query("id")+" easy book");
      ob->set_temp("item_give",1);
      ob->set_temp("item_give_who",me->query("name"));
    }
  }
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 我雖然窮，但我有志氣！"+ob->name(1)+"我不能收。");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") != "rice ball" )
  {
    command("?");
    write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say 你送吃的來啊？可是我己經飽了耶，我要看書了，請回吧。");
    write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
    return notify_fail("");
  }
  command("flip " +who->query("id"));
  call_out("eat_temp",2);
  command("say 嗚嗚.... 你真是救命恩人.. 我也沒啥好報答你的，這送你吧，請你務必收下...。");
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  return 1;
}

void eat_temp()
{
  set("hp",270);
  command("eat ball");
  command("eat ball");
  command("eat ball");
  command("eat ball");
  command("eat ball");
  command("eat ball");
  return;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest",900);
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
