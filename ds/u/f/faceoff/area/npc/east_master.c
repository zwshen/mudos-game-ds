#include <ansi.h>
inherit NPC;
void create()
{
 set_name("謝基",({"shi gi","shi","gi"}));
 set("long",@LONG
他就是海政部的東戶政官啦! 跟辛嚭一樣, 都是在兩年前才到
無砂鎮的, 很受人民的擁戴, 不過最近似乎有一些事.....
LONG
     );
 set("nickname",HIG"東戶政官"NOR);
 set("attitude","peaceful"); 
 set("age",49);
 set("gender","男性");
 set("level",20);
 set("chat_chance",10);
set("chat_msg", ({" 謝基嘆了一口長氣, 道: 這可怎麼辦啊?......\n",
	          " 謝基嘆了一口長氣, 道: 發也不是, 不發也不是, "+HIG+"韃靼舟"+NOR+"真是令人.....\n",
                            (:command("sigh"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","閣下可以幫在下一個忙嗎?\n"NOR);

	set("inquiry/韃靼舟","就是前日要出海的那艘船, 但王霸那個混球偏偏跟船老大有仇, 發下的簽出條都被他收走.....\n"NOR);

	set("inquiry/簽出條","那是發給要出海的船隻的條子, 唉....\n");

	set("inquiry/王霸","就是站在海政司門口的那個豬頭咩!.\n"NOR);

 set("chat_chance_combat",20);
 setup();
 carry_object(__DIR__"eq/sea_cloth")->wear();
 carry_object(__DIR__"eq/gold_fur_boots")->wear();
}


void init()
{
       add_action("typenod","nod");
}
     int typenod(string arg)
{
        object me;
        me=this_player();
        if(arg != "shi gi" && arg != "shi" && arg !="gi") return 0;
        message_vision("謝基高興的直跟$N握手, 口中說道: 就交給閣下了...!\n\n",me);
        message_vision("請閣下幫在下跟王霸拿回簽出條, 就交給閣下了...!\n\n",me);
        return 1;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="簽出條")
        {
           command("? "+who->query("id"));
           return 1;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請你等一下。");
             return 0;
          }
	message_vision("$N給了謝基一張"+ob->query("name")+"。\n",who);
             obj->start_busy(7);
             obj->set_temp("get_paper",1);
             destruct(ob);
             call_out("get_paper",1,obj);
             return 1;
        }

}

void get_paper()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("get_paper");
      switch( i ) {
          case 1:
            command("jump");
            command("say 感謝這位兄弟!!");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 2:
            message_vision(YEL"謝基說道:在下一定公開表揚閣下的善行!!。\n"NOR,me);
         command("smile");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 3:
       tell_object(me,HIY"(你的聲望增加了!!)\n"NOR);
       me->add("popularity",1); //聲望
              obj->delete_temp("get_paper");
            break;
            }
                    
}


