//解四魂之玉的mob
#include <ansi.h>
inherit NPC;
void fongquest();
void create()
{
  set_name("山中老者",({"mountain old man","man"}));
  set("long",@LONG
他是一名居住在山中的老者，似乎是遠古以來擔任守護遺跡一
族的後裔，對於外界毫無聯繫，唯一的兒子多年前意外死去，
只剩下孫子和其相依為命，所以對其十分寵愛，身上也許有關
於遺跡的情報。
LONG
    );
  set("attitude", "peaceful");
  set("age",62);
  set("gender","男性");
  set("level",25);
  set("chat_chance",20);
  set("chat_msg", ({"山中老者說道: 那孩子..真是愛玩...老是不聽話\n",
                    "山中老者憂心重重的不斷嘆氣\n",
                    "山中老者說道: 遺跡似乎又出現動靜了...莫非邪物又要出現了\n",
                  }));
  set("inquiry/遺跡","那是我們一族世代守護的使命，傳說裡面有邪物\n"NOR);
  set("inquiry/孫子","他叫小悠，自從他的爹娘死去後變何我相依為命了，\n"NOR);
  set("inquiry/邪物","聽說是個恐怖的妖魅，有著可怕的能力..\n"NOR);
     setup();   
  add_money("coin",1200);
}
 
void init(){
        object ob;
        ::init();
        add_action("do_say","say");
        if(this_player()->query_temp("pass_mission")==1) call_out("fongquest",1);
}
int do_say(string arg)
{
          object me,npc;          
          npc=this_object();
          me=this_player();
           if(!arg && !npc->query_temp("home_right") && me->query_temp("know_boy") )          
           {
            write(HIW"[你想幫他嗎? say 可 / 不可] "NOR);
            return 1;
           }
   if(arg == "可" && !npc->query_temp("home_right") && !me->query_temp("get_mission")
&& me->query_temp("know_boy"))
     { 
      message_vision(YEL"$N說："+ arg +"\n"
                    "山中老者對著$N說道：真的嗎!太感謝你了，一切就拜託你了。\n"
                    "山中老者說道:太好了，終於有人肯幫我了。\n"    
                    "山中老者說道:幫我把這個交給他..他便會了解了\n"NOR,me);
       new(__DIR__"re-letter")->move(this_object());
       command("give " +me->query("id")+ " letter");
            me->set_temp("get_mission",1); 
            return 1;
     }
   else
     { 
      if(arg == "可" && me->query_temp("get_mission"))
      command("say 你不是答應我過了嗎?");
      return 1;
     }
  if(arg == "不可" && !npc->query_temp("home_right") && me->query_temp("know_boy")  )      
      { 
       message_vision(YEL"$N說：在下無法幫你\n"   
                         "山中老者失望的說:唉...那也不勉強...\n"
                         "山中老者獨自喃喃自語著:悠兒..你快回來呀。\n",me);   
      }
      return 1; 
    
} 

int talk_action(object me)      //talk 時會執行此函式.
{
 if(this_object()->query_temp("home_right")) command("say 目前一切安好，多謝關心。");
 else
 {
        switch(random(3))
        {
                case 0: command("say 請問你可有見到過我的孫子?");
                        break;
                case 1: command("say 唉..真是難以啟齒，可否幫我尋找我的孫子回來。(say)");
                        me->set_temp("know_boy",1);
                        break;
                case 2:
                default:
                        command("say 請問你可有見過我的孫子?");
                        break;
        }
 }
 return 1;
}

void fongquest()
{
    object me,npc;  
       me=this_player();
       npc=this_object();
message_vision("山中老者十分的高興的說:真是太感激你了...老朽無以回報，就把這給你吧。\n"
               "山中老者說道:這是我們一族傳說能集天地陰氣的玉，便就給你當酬謝。\n"
               ,this_player());
       new(__DIR__"jade")->move(this_object());  //四魂之玉
       command("give " +me->query("id")+ " jade");       
       me->delete_temp("pass_mission");       
       me->delete_temp("know_boy");
       npc->set_temp("home_right",1);      
       call_out("delay",600);
}

int accept_object(object who, object ob)
{

  object npc=this_object();
  if(npc->is_busy() || npc->is_fight())
    return notify_fail("山中老者似乎正在忙。\n");
 if(ob->query("id") == "alien-beast stone")
  {
    command("say 疑?..上面的文字好熟悉...是我們祖先的文字呀");
    command("say 上面好像是說，龍虎歸位、入路即現");
    command("say 而且這顆石頭好像要在陽氣重的地方才能分開..");
    command("say 老朽就只知道這樣，希望對你有幫助...石頭還給你吧...");    
    call_out("return_stone",1,who);
    return 1;
  }
  else
  {
       command("?");
       command("say 這是做什麼?..快收回去..");
  }
}
 


void delay()
{   
     object ob,boy;
     ob=this_object();
     if(!ob) return;
     boy=present("boy yu",environment(ob));
     ob->delete_temp("home_right");    
     if(!boy) return;
     boy->go_way();
}

void return_stone(object who)
{
  command("give " +who->query("id")+ "stone");
}

