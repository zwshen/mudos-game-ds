#include <ansi.h>
inherit NPC;
void create()
{
 set_name("苗芃",({"meo pun","pun","meo"}));
 set("long",@LONG
她是這個苗家村最有成就的人，在醫藥方面得心應手，可以說已臻藥王的地步了！
而且人又年輕亮麗，苗家村中追求者不在少數，但是最近卻為了一件事情愁眉不展
，到底是......?
LONG
    );
 set("attitude", "peaceful");
 set("age",21);
 set("nickname",HIY"採藥蝶"NOR);
 set("evil",-10);
 set("gender","女性");
 set("level",20);
set("str",100);
set("con",100);
 set_skill("sword", 100);
 set("chat_chance",40);
 set("chat_msg", ({"苗芃輕輕的嘆了一口氣，搞的你神迷意亂....\n", 
        }) );
 set("inquiry/藥材","要壓制苗族長的病情需要:金砂作藥引，金梠草,清心石綠果作藥函，最後來要用百花釀來作結尾....唉....\n"NOR);

 setup();
}

int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 if(random(2))
 {
         command("sigh");
        command("say 唉，連苗族長的宿疾都無法醫療，我學醫又有什麼用....。");
        command("say 畢竟苗族長所要的『藥材』太特殊，叫我怎麼去找.....");
  }
 return 1;
}

int accept_object(object who,object ob)
{
                object obj,item;
                obj=this_object();
                if(ob->name()=="金梠草")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" 請你等一下。");
                 return 1;
                }
      if (obj->query_temp("find_wine") == 1 && obj->query_temp("find_fruit") == 1 && obj->query_temp("find_sand") == 1 )
      {
       message_vision("苗芃高興的對著$N大喊: 成了!成了!。\n",who);
       message_vision("苗芃轉身進入煉丹室,過了片刻之後,苗芃高興的走了回來.\n",who);
       message_vision("苗芃對著$N說:煩請你將丹藥帶給苗族長啦~!\n",who);
      message_vision(HIC"苗芃給了$N一粒丹藥\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");

      }

      if (obj->query_temp("find_grass") == 0)
    {
        message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say 這樣就只缺其它的藥材了....");
             obj->set_temp("find_grass",1);
             destruct(ob);
             return 1;
   }
      else
     {
  message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say 這樣藥材我已經有了...豬頭喔~");
             return 1;
                }

                }

  if(ob->name()=="金沙")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" 請你等一下。");
                 return 1;
                }
      if (obj->query_temp("find_wine") == 1 && obj->query_temp("find_fruit") == 1 && obj->query_temp("find_grass") == 1 )
      {
       message_vision("苗芃高興的對著$N大喊: 成了!成了!。\n",who);
       message_vision("苗芃轉身進入煉丹室,過了片刻之後,苗芃高興的走了回來.\n",who);
       message_vision("苗芃對著$N說:煩請你將丹藥帶給苗族長啦~!\n",who);
      message_vision(HIC"苗芃給了$N一粒丹藥\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");
      }
      if (obj->query_temp("find_sand") == 0)
    {
        message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say 這樣就只缺其它的藥材了....");
             obj->set_temp("find_sand",1);
             destruct(ob);
             return 1;
      }
            else
     {
  message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say 這樣藥材我已經有了...豬頭喔~");
             return 1;
                }

                }
  if(ob->name()=="清寒石綠果")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" 請你等一下。");
                 return 1;
                }
      if (obj->query_temp("find_sand") == 1 && obj->query_temp("find_wine") == 1 && obj->query_temp("find_grass") == 1 )
      {
       message_vision("苗芃高興的對著$N大喊: 成了!成了!。\n",who);
       message_vision("苗芃轉身進入煉丹室,過了片刻之後,苗芃高興的走了回來.\n",who);
       message_vision("苗芃對著$N說:煩請你將丹藥帶給苗族長啦~!\n",who);
      message_vision(HIC"苗芃給了$N一粒丹藥\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");
      }
      if (obj->query_temp("find_fruit") == 0)
    {
        message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say 這樣就只缺其它的藥材了....");
             obj->set_temp("find_fruit",1);
             destruct(ob);
             return 1;
      }
            else
     {
  message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say 這樣藥材我已經有了...豬頭喔~");
             return 1;
                }

                }
 if(ob->name()=="百花釀")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" 請你等一下。");
                 return 1;
                }
      if (obj->query_temp("find_sand") == 1 && obj->query_temp("find_fruit") == 1 && obj->query_temp("find_grass") == 1 )
      {
       message_vision("苗芃高興的對著$N大喊: 成了!成了!。\n",who);
       message_vision("苗芃轉身進入煉丹室,過了片刻之後,苗芃高興的走了回來.\n",who);
       message_vision("苗芃對著$N說:煩請你將丹藥帶給苗族長啦~!\n",who);
      message_vision(HIC"苗芃給了$N一粒丹藥\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");
      }
      if (obj->query_temp("find_wine") == 0)
    {
        message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say 這樣就只缺其它的藥材了....");
             obj->set_temp("find_wine",1);
             destruct(ob);
             return 1;
      }
      else
     {
  message_vision("$N給了苗芃一個"+ob->query("name")+"。\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say 這樣藥材我已經有了...豬頭喔~");
             return 1;
                }

                }
}
