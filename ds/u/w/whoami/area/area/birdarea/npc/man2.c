#include <ansi.h>
#include <dbase.h>
inherit F_VENDOR;
inherit NPC;
string *file=({"scroll","scroll1","box"});
void create()
{
 set_name("陳寶",({"chen biaw","chen","biaw"}));
 set("long","他是獵狐村的村長，雖然他的臉上已經佈滿歲月的痕跡了，但是\n"
            "他那孔武有力的身軀，卻一點都沒有像是老人的樣子。他看來似\n"
            "乎有點煩惱•\n");
 set("age",60);
 set("gender","男性");
 set("level",20);
 set("title",HIR"獵狐村"NOR"村長");
 set_skill("parry",50);
 set_skill("unarmed",50);
 set_skill("dodge",50);
 set("no_fight",1);
 set("chat_chance",10);
 set("chat_msg", ({ YEL"陳寶低聲的自言自語:怎麼辦...到底該怎麼辦....\n"NOR,
                   (:command("sigh"):),
 }));
 set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
 set("reborn",3600);
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
  add_action("do_list","list");
  add_action("do_change","exchange");
}

void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 if ( me->query("quest/ko_fox") >= 200  ){
    command("tsk "+me->query("id"));
    command("say 這位"+RANK_D->query_respect(ob)+"真是不簡單，居然能砍下那麼多狐狸的頭•");   
    command("say 這樣吧，我可以用點東西來跟你換你砍下的頭•");
    command("say 請用list查詢想換取的東西！"); 
    } else {
    command("hi "+ me->query("id") );   
    command("say 這位"+RANK_D->query_respect(ob)+"來我們村裡有什麼事嗎？");
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
  if(strsrch(str,"煩惱") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1 ){
    command("say 我沒什麼煩惱啊.."); 
    command("hoho");  
    } else {
    command("say 請你幫我找回天狗皮，那是我的傳家寶，請務必要找回來。");
    command("thank "+ this_player()->query("id"));
    }
  }   
  if(strsrch(str,"天狗皮") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1 ){
    command("say 那是我的傳家寶啊..？"); 
    command("say 我可是不會給你看的");
    command("giggle "+ this_player()->query("id")); 
    } else {
    command("say 有一隻大鳥趁我不注意時，把天狗皮給叼走了！！");
    command("say 牠好像是往東北澤林─泥沼區的方向飛去。");
    }
  }
  if(strsrch(str,"獵狐村") != -1)
  { 
    command("hoho");
    command("say 這就是我們的村莊，有什麼問題嗎？");
  } 
  return;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "tengu fur")
        {
           command("flop "+who->query("id"));
           command("say 這不是我要的東西啦..");
          return notify_fail("");
} 
if( query_temp("can_not_give") ){
           command("?");
           command("say 給我這做啥？");
           return notify_fail("");
}        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
           if( present("godwind bag", who) )
           {
             command("?");
             return 0;
           }

             message_vision("$N給了$n一"+ob->query("unit")+ob->query("name")+"。\n",who,obj);
             command("think"); 
             obj->set_temp("can_not_give",1);  
             obj->set_temp("givebag",1);
             destruct(ob); 
             call_out("rb",1500);
             call_out("givebag",1,who);
return 1;
        }
}
void givebag()
{
      int i;
      object me,obj,wind;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givebag");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"陳寶仔細瞧了瞧這張皮。\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 2:
            command("say 太好了，就是這張皮。");
            obj->set_temp("givebag",i+1);
            call_out("givebag",2,me);
            break;
          case 3:
            say(HIY"陳寶親了親這張皮並且說:我有個東西要送你，你等等。\n"NOR);
            command("dance");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 4:
            say(HIY"陳寶在身旁的箱子中東翻西找的，不知道他在找什麼東西。\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 5:
            command("say 這是我親自做的袋子，便送給你當作酬勞吧。");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 6:
            wind=new(__DIR__"obj/bag");
            wind->move(obj);
            command("give bag to "+ me->query("id") );
            obj->delete_temp("givebag"); 
            obj->set("long","他是獵狐村的村長，雖然他的臉上已經佈滿歲月的痕跡了，但是\n"
                            "他那孔武有力的身軀，卻一點都沒有像是老人的樣子。\n");
            obj->set("chat_msg", ({ (:command("say 最後還是找到了.."):),
                                    (:command("sweat"):),
                                  }));
          break;
          }
}

string item_desc(object ob)
{
        if(ob->query("skill_type")) return HIG+"武器"+NOR;
        else if(ob->query("armor_type")) return HIY+"防具"+NOR;
        else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"回復"+NOR;
        else return "道具";
}
int do_list(string arg)
{
  string dir,list;
  object awardeq;
  int i,a,awardcost;
  dir = "/open/world1/whoami/birdarea/npc/change/";
  i = sizeof(file);
  list = "\n\n┌───────────────────────────┐\n";
  list +="│ 所需狐狸頭        種類   目前可以兌換的物品          │\n";   
  list +="└───────────────────────────┘\n";
  for(a=0;a<i;a++) {
    if(load_object(dir+file[a])) {
      awardeq = load_object(dir+file[a]);
      awardcost = awardeq->query("needaward");
list += sprintf("%6d ------------- %4s  %-30s",awardcost,item_desc(awardeq),awardeq->short()); }
    else break; 
    list += "\n";
  } 
    list += "\n\t你目前有 "+this_player()->query("quest/ko_fox")+" 顆狐狸頭•\n";    list += "\t請用exchange <物品全名>來交換想換的東西•\n";
    list += "\t獎品持續增加中•\n"; 
    list += "\n";
  this_player()->start_more(list);
  return 1;
}
int do_change(string arg)
{
  int a,b,c,awardcost,i,j=1;
  object awardeq,me,ob;
  string name,dir;
  dir = "/open/world1/whoami/birdarea/npc/change/";
  me=this_player();
  if(!arg) return notify_fail("你要兌換什麼東西？\n");
  name = arg;
  i = sizeof(file);
  for(a=0;a<i;a++) {
    awardeq = load_object(dir+file[a]);
    if(awardeq->query("id") == name) { 
      j=0; break; }
  }
  if(j!=0)
  return notify_fail("陳寶說道： 本人並不兌換這種東西(請注意您是否有告訴我該物品的全名).\n");
  else {
  awardcost = awardeq->query("needaward");
  if( me->query("quest/ko_fox") < awardcost )
    return notify_fail("陳寶說道： 抱歉！您砍下的狐狸頭不夠兌換這個東西！\n");
  if( awardeq->query_weight() + me->query_encumbrance() > me->query_max_encumbrance() )
    return notify_fail("陳寶說道： 您拿不動這東西了吧？ \n");
  if( awardeq->query("volume") + me->query_capacity() > me->query_max_capacity() )
    return notify_fail("陳寶說道： 您身上放不下這東西囉! \n");
  me->add("quest/ko_fox", -awardcost);
  message_vision("$N用 "+awardcost+" 顆狐狸頭換得了： "+awardeq->query("name")+" ！\n",me);
  ob = new(dir+file[a]);
  if(ob->is_character()) ob->move(environment(me));
  else ob->move(me);
  me->save();
  return 1;
  }
}
int rb()
{ 
    delete_temp("can_not_give");
    set("long","他是獵狐村的村長，雖然他的臉上已經佈滿歲月的痕跡了，但是\n"
               "他那孔武有力的身軀，卻一點都沒有像是老人的樣子。他看來似\n"
               "乎有點煩惱•\n");
    set("chat_msg", ({ YEL"陳寶低聲的自言自語:怎麼辦...到底該怎麼辦....\n"NOR,
                     (:command("sigh"):),
                     }));
    message_vision(YEL"$N咳了兩聲。\n"NOR,this_object());
    return 1;
}

