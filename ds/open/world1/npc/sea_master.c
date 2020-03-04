#include <ansi.h>
inherit NPC;
void create()
{
 set_name("辛嚭",({"sin pai","pai","sin"}));
 set("long",@LONG
他是在兩年前才被派任到無砂鎮的行政官, 不過其所信仰的
鐵腕法律卻在短短的兩年間受到全鎮人名的信賴, 就連惡名
昭彰的王霸在他到任後也略收了收霸氣.
LONG
     );
 set("nickname",HIG"海政長官"NOR);
 set("attitude","peaceful"); 
 set("age",54);
 set("gender","男性");
 set("level",20);
 set("chat_chance",10);
 set("chat_msg", ({"辛嚭忙碌的看著公文....\n",
 }));
 set("chat_chance_combat",20);
 setup();
 carry_object(__DIR__"../eq/sea_cloth")->wear();
 carry_object(__DIR__"../wp/big_pan")->wield();
 carry_object(__DIR__"../eq/gold_fur_boots")->wear();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="西副師的官印")
        {
           command("? "+who->query("id"));
           return notify_fail("");
// return 1; --> return notify_fail by alickyuen
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請你等一下。");
             return 0;
          }
	message_vision("$N給了辛嚭一個"+ob->query("name")+"。\n",who);
             obj->start_busy(7);
             obj->set_temp("find_mark",1);
             destruct(ob);
             call_out("find_mark",1,obj);
             return 1;
        }

}

void find_mark()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("find_mark");
      switch( i ) {
          case 1:
            command("say 啊! 這不是西副師的官印嗎?");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此官印的？");
            obj->set_temp("find_mark",i+1);
            call_out("find_mark",1,me);
            break;
          case 2:
            message_vision(YEL"$N將取得官印的過程告訴辛嚭...。\n"NOR,me);
         command("sob");
            obj->set_temp("find_mark",i+1);
            call_out("find_mark",1,me);
            break;
          case 3:
	    command("nod");
            command("say 哪裡料得到西副師竟有如此下場!!。");
            command("sigh");
            obj->set_temp("find_mark",i+1);
            call_out("find_mark",1,me);
            break;
          case 4:
         command("say 感謝"+me->query("name")+"告知他的下落....");
          command("say 請受本官一拜!");
          command("bow");
          command("say 本官自當稟明上司, 給與閣下適當的報酬!");
       tell_object(me,HIY"(你的聲望增加了!!)\n"NOR);
       me->add("popularity",1); //聲望
              obj->delete_temp("find_mark");
            break;
            }
                    
}

