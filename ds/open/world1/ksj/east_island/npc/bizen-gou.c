#include <ansi.h>
inherit NPC;

void create()
{
  set_name("備前．剛", ({ "Bizen gou","gou"}));
  set("long",@long
一個身材壯碩的年輕刀匠，身上的衣服因為長時間的勞動而充滿汗臭
味及木炭味，據說他的歷代祖先都是有名的刀匠，鑄造了不少名刀，
但是傳到他這一代卻沒有什麼傑出的名作，不過他對於名刀的收集與
鑑賞卻很感興趣。
long);      
  set("gender", "男性" );
  set("age",32);
  set("level",20);
  set("race","human");
  set("no_fight",1);
  set("talk_reply","歡迎光臨，非常抱歉，要買武器的話目前沒貨囉，\n"
                  +"店裡的鐵都被我拿去製作一些零組件了。\n");
  set("chat_chance", 15);
  set("chat_msg", ({
      "備前．剛對著一堆鐵器說道：零件都打造好了，可是設計圖卻不見了\n"
     +"                          ，傷腦筋阿．．\n",
      "備前．剛說道：鐵材都用完了，得再到港都買些，好打造武器提供村\n"
     +"              民防衛。\n",
      "備前．剛坐在桌前發著呆，不知道在想什麼？\n",
      (: command("idle") :),
     }));
  set("inquiry/奇甲之鑄成","那是一些防具的設計圖，前陣子山崽來襲時，不知道\n"
                      +"被誰把內容給撕走了，害得我辛苦打造的組件沒辦法順利組合為成品。\n");
  set("inquiry/名刀鑑","那是我多方搜集資料所編成，裡面記載的可都是罕世\n"
                      +"的名刀呀。\n");
  setup();
  add_money("coin",100+random(100));
}

int accept_object(object who,object ob)
{
  object obj;
  obj=this_object();

  if(ob->query("id") == "armor design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
      return 0;
    }
    message_vision("$N拿給備前．剛一張 "+ob->query("name")+"。\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("givearmor",1);
    destruct(ob);
    call_out("givearmor",1,obj);
    return 1;
  }

  if(ob->query("id") == "hands design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
      return 0;
    }
    message_vision("$N拿給備前．剛一張 "+ob->query("name")+"。\n",who);
    command("spank");
    obj->start_busy(10);
    obj->set_temp("givehands",1);
    destruct(ob);
    call_out("givehands",1,obj);
    return 1;
  }

  if(ob->query("id") == "boots design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
      return 0;
    }
    message_vision("$N拿給備前．剛一張 "+ob->query("name")+"。\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("giveboots",1);
    destruct(ob);
    call_out("giveboots",1,obj);
    return 1;
  }

  if(ob->query("id") == "neck design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
      return 0;
    }
    message_vision("$N拿給備前．剛一張 "+ob->query("name")+"。\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("giveneck",1);
    destruct(ob);
    call_out("giveneck",1,obj);
    return 1;
  }

  if(ob->query("id") == "surcoat design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
      return 0;
    }
    message_vision("$N拿給備前．剛一張 "+ob->query("name")+"。\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("givesurcoat",1);
    destruct(ob);
    call_out("givesurcoat",1,obj);
    return 1;
  }

  if(ob->query("id") == "wrists design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
      return 0;
    }
    message_vision("$N拿給備前．剛一張 "+ob->query("name")+"。\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("givewrists",1);
    destruct(ob);
    call_out("givewrists",1,obj);
    return 1;
  }

}

void givearmor()
{
  int i;
  object me,obj,armor;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givearmor");
  if( !me || environment(me) != environment(obj) )
  {
    command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"備前．剛拿起紙張，高興地說道：好極了！稍等一下喔。\n"NOR);
         obj->set_temp("givearmor",i+1);
         call_out("givearmor",2,me);
         break;
    case 2:
         say(CYN"備前．剛拿起一堆零件，開始組裝．．．。\n"NOR);
         obj->set_temp("givearmor",i+1);
         call_out("givearmor",3,me);
         break;
    case 3:
         say(CYN"備前．剛說道：呼∼好了，你拿去試試性能吧。\n"NOR);
         armor=new_ob(__DIR__"eq/illusive-mirror-corslet");
         armor->move(obj);
         command("give corslet to "+ me->query("id") );
         obj->delete_temp("givearmor");
         break;
  }
}

void givehands()
{
  int i;
  object me,obj,hands;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givehands");
  if( !me || environment(me) != environment(obj) )
  {
    command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"備前．剛拿起紙張，高興地說道：好極了！稍等一下喔。\n"NOR);
         obj->set_temp("givehands",i+1);
         call_out("givehands",2,me);
         break;
    case 2:
         say(CYN"備前．剛坐在桌前，開始組裝零件．．．。\n"NOR);
         obj->set_temp("givehands",i+1);
         call_out("givehands",3,me);
         break;
    case 3:
         say(CYN"備前．剛說道：嗯∼不錯，你拿去試試性能吧。\n"NOR);
         hands=new_ob(__DIR__"eq/ya-sha-hands");
         hands->move(obj);
         command("give hands to "+ me->query("id") );
         obj->delete_temp("givehands");
         break;
  }
}

void giveboots()
{
  int i;
  object me,obj,boots;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("giveboots");
  if( !me || environment(me) != environment(obj) )
  {
    command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"備前．剛拿起紙張，高興地說道：好極了！稍等一下喔。\n"NOR);
         obj->set_temp("giveboots",i+1);
         call_out("giveboots",2,me);
         break;
    case 2:
         say(CYN"備前．剛坐在桌前，開始組裝零件．．．。\n"NOR);
         obj->set_temp("giveboots",i+1);
         call_out("giveboots",3,me);
         break;
    case 3:
         say(CYN"備前．剛說道：嗯∼不錯，你拿去試試性能吧。\n"NOR);
         boots=new_ob(__DIR__"eq/mu-in-boots");
         boots->move(obj);
         command("give boots to "+ me->query("id") );
         obj->delete_temp("giveboots");
         break;
  }
}

void giveneck()
{
  int i;
  object me,obj,neck;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("giveneck");
  if( !me || environment(me) != environment(obj) )
  {
    command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"備前．剛拿起紙張，高興地說道：好極了！稍等一下喔。\n"NOR);
         obj->set_temp("giveneck",i+1);
         call_out("giveneck",2,me);
         break;
    case 2:
         say(CYN"備前．剛坐在桌前，開始組裝零件．．．。\n"NOR);
         obj->set_temp("giveneck",i+1);
         call_out("giveneck",3,me);
         break;
    case 3:
         say(CYN"備前．剛說道：嗯∼不錯，你拿去試試性能吧。\n"NOR);
         neck=new_ob(__DIR__"eq/iron-cloth-neck");
         neck->move(obj);
         command("give neck to "+ me->query("id") );
         obj->delete_temp("giveneck");
         break;
  }
}

void givesurcoat()
{
  int i;
  object me,obj,surcoat;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givesurcoat");
  if( !me || environment(me) != environment(obj) )
  {
    command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"備前．剛拿起紙張，高興地說道：好極了！稍等一下喔。\n"NOR);
         obj->set_temp("givesurcoat",i+1);
         call_out("givesurcoat",2,me);
         break;
    case 2:
         say(CYN"備前．剛坐在桌前，開始組裝零件．．．。\n"NOR);
         obj->set_temp("givesurcoat",i+1);
         call_out("givesurcoat",3,me);
         break;
    case 3:
         say(CYN"備前．剛說道：嗯∼不錯，你拿去試試性能吧。\n"NOR);
         surcoat=new_ob(__DIR__"eq/chain-surcoat");
         surcoat->move(obj);
         command("give surcoat to "+ me->query("id") );
         obj->delete_temp("givesurcoat");
         break;
  }
}

void givewrists()
{
  int i;
  object me,obj,wrists;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givewrists");
  if( !me || environment(me) != environment(obj) )
  {
    command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"備前．剛拿起紙張，高興地說道：好極了！稍等一下喔。\n"NOR);
         obj->set_temp("givewrists",i+1);
         call_out("givewrists",2,me);
         break;
    case 2:
         say(CYN"備前．剛坐在桌前，開始組裝零件．．．。\n"NOR);
         obj->set_temp("givewrists",i+1);
         call_out("givewrists",3,me);
         break;
    case 3:
         say(CYN"備前．剛說道：嗯∼不錯，你拿去試試性能吧。\n"NOR);
         wrists=new_ob(__DIR__"eq/blade-wrists");
         wrists->move(obj);
         command("give wrists to "+ me->query("id") );
         obj->delete_temp("givewrists");
         break;
  }
}
