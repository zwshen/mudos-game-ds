#include <ansi.h>
inherit NPC;
void create()
{
 set_name("王轑",({"wang-lou","wang","lou"}));
 set("long","他是在這村子裡頭赫赫有名的織皮人，據說只要是他織出來的東\n"
            "西，都是有品質保證的•\n");
 set("age",43);
 set("gender","男性");
 set("level",20);
 set("nickname",HIY"織皮高手"NOR);
 set("title",HIR"獵狐村"NOR);
 set("no_fight",1);
 set("chat_chance",20);
 set("chat_msg", ({ YEL"王轑拿起手中的狐皮面罩嘆了一口氣.\n"NOR ,
                   (:command("sigh"):),
 })); 
 set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
 setup();
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
} 

void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 if ( me->query_temp("ko_fox_nine") >= 1  && objectp( ob = present("fox fur" , me) ) ){
    command("say 如果你能把你身上的那張九尾的皮給我，我就織一件裝備給你！");
    command("bow "+ me->query("id") );   
    } else {
    command("say 如果你能幫我拿到九尾的皮，我就織一件裝備給你！");
    command("addoil "+ me->query("id") );   
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
  if(strsrch(str,"狐皮面罩") != -1)
  { 
    command("hmm " + this_player()->query("id")); 
    command("say 只要給我更好的材料，我一定能做出絕佳的面罩！");  
    command("sigh"); 
  }  
return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
    if(ob->query("id") == "fox fur")
    { 
    if( who->query_temp("ko_fox_nine") && obj->query_temp("no_give") < 1 )
    {
             message_vision("$N給了$n一"+ob->query("unit")+ob->query("name")+"。\n",who,obj);
             command("think");
             obj->set_temp("no_give",1);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
             return 1;
    } else {
           command("yawn "+who->query("id"));
           command("say 我不要來路不明的東西！");
   }
  write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
  return notify_fail("");
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
            message_vision(HIY"$N摸了摸這張狐皮。\n"NOR,obj);
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 2:
            command("say 就...就是這張皮...太好了....");
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 3:
            message_vision(HIY"$N拿起狐皮在桌子上縫起來了。\n"NOR,obj);
            command("sweat");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            message_vision(HIY"過了一會$N手上便多了一張面罩。\n"NOR,obj);
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 5:
            command("say 我把那張狐皮的一部分做了一張面罩, 便送給你當酬勞吧");
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 6:
            plate=new(__DIR__"obj/hat");
            plate->move(obj);
            command("give mask to "+ me->query("id") );
            obj->delete_temp("givehat"); 
            break;
          }
          obj->delete_temp("no_give");            
}

