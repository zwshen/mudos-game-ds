#include <ansi.h>
inherit NPC;
void create()
{
 set_name("邢獨風",({"shin-do-fon","fon"}));
 set("long","此人身長六尺, 顏面莊重, 頭髮至肩, 腿部肌肉結實,
眼睛散發出耀眼的光輝, 就像老鷹一樣, 一看就知道此
人輕功\絕佳, 人稱天梟三聖之一, 又稱 [ 形如風 ] 因
為他的輕功\可\以算是到了神乎其技了, 此人是天梟教裡
專攻輕功\的高手，他非常喜歡收集石頭。\n" );
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","男性");
 set("level",38);
 set("title",HIC"天梟三聖"NOR);
 set_skill("dagger",70);
 set_skill("dodge",100);
 set_skill("bird-eight",100);
 set_skill("force",60);
 set_skill("parry",60);
 set_skill("sky-dagger",70);
 map_skill("dagger","sky-dagger");
 map_skill("dodge","bird-eight");
 set("guild_gifts",({6,4,0,10}));
 set("chat_chance",10);
 set("chat_msg", ({"邢獨風嘆氣說道:難到我畢生的心願竟然不能如願以償?\n",
                   "邢獨風嘆氣說道:就只差那一個了。\n",
                   (:command("sigh"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say 小子!!你不要命了!!去死吧!! ":),
 }));
 set("talk_reply","你能幫我一點忙(help)嗎?\n");
 set("inquiry/help","請你幫我找到五彩石，那是我所沒有的為一一塊石頭。\n");
 setup();
 carry_object(__DIR__"eq/dagger3")->wield();
 carry_object(__DIR__"eq/cloth2")->wear();
 carry_object(__DIR__"eq/boots2")->wear();
 carry_object(__DIR__"eq/surcoat")->wear();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") != "five-color-stone")
        {
           command("slap "+who->query("id"));
           command("say 你給我這個是啥啊....-.-");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了邢獨風一個 "+ob->query("name")+"。\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"邢獨風用手輕清的觸摸這塊石頭。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say 就是這個....太謝謝你了小兄弟。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"邢獨風小心的把五彩石給收起來。\n"NOR);
            command("jump");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            command("say 老夫看你一表人才，便教你幾手\輕\功\，算是答謝禮好了。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            say(HIG"只見邢獨風一邊在堂中跳躍飛舞，一邊解釋著勁道、招式。\n"NOR);
            message_vision(" ( $N牢牢的記下所有的招式 )\n",me);
              if(me->query_skill("bird-eight") == 0 || me->query("class1") == "天梟教")
               {
                me->set_skill("bird-eight",10);
                     }
	      else 
               {
                say(HIG"但也許是你們緣份不夠..你完全無法領悟....。\n"NOR);
		     }
            obj->set_temp("givehat",i+1);
            call_out("givehat",5,me);
            break;
          case 6:
            command("say 好了好了，你自己去練習吧....:D");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            obj->delete_temp("givehat");
            break;
          }
}
void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIW"\n  武林傳出了一則驚人的消息:"HIC"\n\n\t天梟三聖之一的 邢獨風竟然敗給了"+ob->name(1)+"。\n\n"+NOR,users());
        ob->add("popularity",1);
        ::die();
        return;
}


