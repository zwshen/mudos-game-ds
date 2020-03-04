#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("藥鋪掌櫃" , ({ "herbalist" }) );
        set("level",5);
        set("race","人類");
         set("gender","男性");
        set("age", 23);
        set("no_fight",1);
        set("long","他是清心藥鋪的掌櫃。\n");
        set("sell_list",([
         __DIR__"obj/god_pill" : 15,
         __DIR__"obj/head_pill" : 20,
         __DIR__"obj/hand_pill" : 20,
         __DIR__"obj/body_pill" : 20,
         __DIR__"obj/foot_pill" : 20,
        ]) );
        setup();
}
void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}
int accept_object(object who,object ob)
{
        object me,obj;
        me=this_player();
        obj=this_object();
        if(ob->name()!="五葉紅心草" && ob->name()!="七星紫金葉" && ob->name() != "龍鬚碧藍花" &&ob->name() != "清寒石綠果" && ob->name() != "黯淡沙灰根" )
        {
           command("eh");
           command("say 我不需要這種東西。");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+me->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
message_vision("$N給了藥舖掌櫃一個"+ob->query("name")+"。\n",me);
             command("hmm");
             obj->set_temp("makepill/pill",1);
             obj->set_temp("makepill/name",ob->query("name"));
             obj->start_busy(7);
             destruct(ob);
             call_out("makepill",1,me);
             return 1;
        }
} 
void makepill()
{
   int i;
   object me,obj,pill;
   me=this_player();
   obj=this_object();
   i=obj->query_temp("makepill/pill");
     switch( i ) {
           case 1:
               say(HIY"藥舖掌櫃仔細的看了看"+obj->query_temp("makepill/name")+"。\n"NOR);
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",2,obj);
               break;
           case 2:
               command("say 這個"+obj->query_temp("makepill/name")+"可燒成不錯的丹藥。");
               command("say 我這就幫你燒。");
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",2,obj);
               break;
           case 3:
               say(HIY"藥舖掌櫃把"+obj->query_temp("makepill/name")+"放進丹鼎裡頭。\n"NOR);
               say(HIY"藥舖掌櫃接著把丹鼎放進青銅丹爐裡，並點燃了幾根木材丟進青銅丹爐。\n"NOR);
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",4,obj);
               break;
           case 4:
               say(HIY"沒多久時間，只見丹鼎冒出一絲絲輕煙。\n"NOR);
               command("say 成了！成了！");
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",2,obj);
               break;
           case 5:
               if(obj->query_temp("makepill/name")=="五葉紅心草")
               {
                 pill=new(__DIR__"obj/pill.c");
               }
               if(obj->query_temp("makepill/name")=="七星紫金葉")
               {
                 pill=new(__DIR__"obj/pill2.c");
               }
               if(obj->query_temp("makepill/name")=="龍鬚碧藍花")
               {
                 pill=new(__DIR__"obj/pill3.c");
               }
               if(obj->query_temp("makepill/name")=="清寒石綠果")
               {
                 pill=new(__DIR__"obj/pill4.c");
               }
               if(obj->query_temp("makepill/name")=="黯淡沙灰根")
               {
                 pill=new(__DIR__"obj/pill5.c");
               }
               pill->move(obj);
               say(HIY"藥舖掌櫃從丹鼎取出了一個丹藥。\n"NOR);
               command("give pill to "+me->query("id"));
               obj->delete_temp("makepill");
               break;
        }
 }
