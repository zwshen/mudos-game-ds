#include <ansi.h>
inherit NPC;
void create()
{
 set_name("邢獨風",({"shin-do-fon","fon"}));
 set("long",@LONG
此人身長六尺, 顏面莊重, 頭髮至肩, 腿部肌肉結實,
眼睛散發出耀眼的光輝, 就像老鷹一樣, 一看就知道此
人輕功絕佳, 人稱天梟三聖之一, 又稱 [ 行如風 ] 因
為他的輕功可以算是到了神乎其技了, 此人是天梟教裡
專攻輕功的高手，他非常喜歡收集石頭。
LONG);
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","男性");
 set("level",38+random(10));
 set("title",HIC"天梟三聖"NOR);
   set("class1","天梟派");
 set("MKS",60000); 
 set("dex",100+random(50));
 set("ap",50000); set_skill("dagger",70);
    set("ap",50000);
    set_skill("needle",70);

 set_skill("dodge",100);
   set_skill("wing-eight",100);
 set_skill("force",60);
 set_skill("parry",60);
   set_skill("skyowl-needle",70);
   map_skill("needle","skyowl-needle");
   map_skill("dodge","wing-eight");
 set("guild_gifts",({6,4,0,10}));
 set("guild_skills",([
       "wing-eight" : ({ 140,3,80 }),
 ]));
 set("chat_chance",9);
 set("chat_msg", ({  (: command("say 難到我畢生的心願竟然不能如願以償？")  :),
                     (: command("say 就只差那一個了...")                   :),
                     (: command("sigh")                                    :),
 }));
 set("chat_chance_combat",80);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say 小子！！你不要命了！！去死吧！！ ":),
 }));
 set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
 setup();
 carry_object(__DIR__"eq/dagger3")->wield();
 carry_object(__DIR__"eq/cloth2")->wear();
 carry_object(__DIR__"eq/boots2")->wear();
 carry_object(__DIR__"eq/surcoat")->wear();
}

void init()
{
    object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
   add_action("do_no_ask","ask");
   add_action("do_skill_list","list");
   add_action("do_skill_train","train");
}
void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 if ( me->query("class1") == "天梟教" && me->query_skill("bird-eight") >= 100){
   command("tsk " + me->query("id"));
   command("say 又有一個跟我一樣強的人出現了啊！");
   command("bow " + me->query("id"));
   } 
   if ( me->query("class1") == "天梟教" 
        &&  me->query_skill("bird-eight") < 100 &&  me->query_skill("bird-eight") >= 1 ){   command("say 練功\練的如何啊？");
   command("smile");
   } 
   if ( me->query("class1") == "天梟教" &&  me->query_skill("bird-eight") == 0){
command("say 你如果幫我找到我要的石頭，我會給你很好的報酬喔！");

command("grin "+ me->query("id") );   
   } 
}

 int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

void relay_say(object me, string str)
{
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"五彩石") != -1)
  { 
    command("hmm"); 
    command("say 那顆五彩石正是我想找的石頭.."); 
  }  
  if(strsrch(str,"石頭") != -1)
  { 
    command("hmm"); 
    command("say 我要找的是五彩石..它就是我唯一缺少的一顆石頭！"); 
  }  
  if(strsrch(str,"輕功\") != -1)
  {  
    command("say 我就是天梟教裡輕功\最強的人！");  
    command("wahaha"); 
  }  
return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if( ob->query("id") != "five color stone" )
{
           command("pig "+who->query("id"));
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
        object me,obj;
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
            say(HIY"邢獨風用手輕輕的觸摸這塊石頭。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say 就是這個....真是謝謝你了，這位" + RANK_D->query_respect(me) + "。");
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
            if(me->query("class1") == "天梟教" && me->query_skill("bird-eight") == 0)
            {
                 command("say 老夫看你一表人才，便教你幾手輕功\，算是答謝禮好了。");
                 obj->set_temp("givehat",i+1);
                 call_out("givehat",3,me);
            }
            else {
                 command("say 只可惜....");
                 command("sigh");
                 command("say 我會讓大家都知道你曾幫助過我");
                 command("bow");
                 switch( random(3) ){
                 case 0..1:
                 me->add("exp",5000);
                 tell_object(me,HIW"(因為你幫助了刑獨風，所以得到了 5000 點經驗值。)\n"NOR);
                 break;
                 default: 
                 me->add("popularity",2);
                 tell_object(me,HIW"(因為你幫助了邢獨風，所以得到了 2 點聲望。)"NOR);
                 break;
                 }                 obj->delete_temp("givehat");
                 }
            break;
          case 5:
            say(HIG"只見邢獨風一邊在堂中跳躍飛舞，一邊解釋著勁道、招式。\n"NOR);
            message_vision(" ( $N牢牢的記下所有的招式 )\n",me);
            me->set_skill("bird-eight",10);
            obj->set_temp("givehat",i+1);
            call_out("givehat",5,me);
            break;
          case 6:
            command("say 好了好了，你自己去練習吧..");
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
        if( ob ) message("world:world1:vision", 
                HIW"\n\t武林傳出了一則驚人的消息:"
                HIC"\n\n\t\t天梟三聖之一的 邢獨風竟然敗給了"NOR+ob->name(1)+"。\n\n" NOR,
        users());

        ob->add("popularity",2);
        tell_object(ob,HIW"(因為你殺死了邢獨風，所以得到了 2 點聲望。)"NOR);
        ::die();
        return;
}

