#include <ansi.h>
inherit NPC;
void create()
{
set_name("余滄",({"yu chen","yu","chen"}));
set("long",@LONG
這是一個在無砂名聲響噹噹的鹽梟, 但他到底是黑道白道
到今天還是眾說紛紜, 不過可信的是, 在無砂尚未有海政司之
前, 余滄倒是相當公平的處理貧富之間的糾紛, 也因此得罪了
不少富人, 因此相當不滿於今日站在富人群中, 壓榨窮民的王
霸, 幸虧余滄早年曾得一高人指點刀法, 才能在無砂中不受王
霸的鏟除.
LONG
    );
 set("attitude","peaceful"); 
 set("title",HIY"鹽俠"NOR);
 set("age",51);
 set("gender","男性");
 set("level",39);
 set_skill("blade",100);
 set_skill("sea-blade",100);
 map_skill("blade","sea-blade");
 set_skill("force",60);
 set_skill("combat",70);
set("chat_msg_combat", ({
                  (:command("exert sea-blade"):),
        }) );

set("inquiry/王霸","就是站在海政司前面的那個豬頭ㄚ! 不過他不會輕易與人動手, 一定要先激怒他...!\n"NOR);

set("talk_reply","不瞞閣下..王霸那混帳昨日帶了數十個官兵將我兄弟十多人殺了個乾淨, 偏偏我又負傷, 這混帳定有報應....\n"NOR);
 setup();
 carry_object(__DIR__"eq/dragon_blade")->wield();
 carry_object(__DIR__"eq/viper_cloth")->wear();
 carry_object(__DIR__"eq/water_boots")->wear();
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
CYN"\n  [無砂小報] :\n\n\t鹽俠 余滄 被"+ob->name(1)+"給做掉了。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
       tell_object(ob,HIW"(因為你殺死了余滄，所以得到了 1 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="王霸的官印")
        {
           command("? "+who->query("id"));
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請你等一下。");
             return 0;
          }
	message_vision("$N給了余滄一個"+ob->query("name")+"。\n",who);
             obj->start_busy(10);
             obj->set_temp("kill_wang",1);
             destruct(ob);
             call_out("kill_wang",1,obj);
             return 1;
        }

}

void kill_wang()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("kill_wang");
      switch( i ) {
          case 1:
            command("say 啊! 這不是那個狗賊的官印嗎?");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此官印的？");
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 2:
            message_vision(YEL"$N將取得官印的過程告訴余滄...。\n"NOR,me);
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 3:
	    command("nod");
            command("say 不錯不錯....那狗賊也算有了報應....。");
            command("smile");
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 4:
	    if(me->query_skill("blade") > 30 && me->query_skill("sea-blade") == 0) 
            {
            command("say 看來兄弟根基不錯....。");
            command("say 在下一套滄海刀訣實是不願沒落, 如今授與閣下, 江湖上也沒話好說了罷?");
	    obj->set_temp("kill_wang",i+1);
	    call_out("kill_wang",3,me);
	    }

	     else {
        command("say 只可惜兄弟不適合再練滄海刀訣...");
          command("say 請受某家一拜!");
          command("bow");
          command("say 在下早年在江湖上闖蕩, 偶然得到一個小玩意兒, 這下就送給了閣下吧!");
          item=new(__DIR__"eq/sea-blade");
            item->move(obj);
            command("give blade to "+ me->query("id") );
              obj->delete_temp("kill_wang");
            }
            break;
          case 5:
            message_vision(YEL"余滄將滄海刀訣的四套變化細細講給$N聽.\n"NOR,me);
            message_vision(YEL"$N在余滄的說明下操刀演練....\n"NOR,me);      
          message_vision(YEL"余滄說道:差不多了...差不多了.....\n"NOR,me);
         message_vision(YEL"(經過一番苦練, $N練成了滄海刀訣) .\n"NOR,me);
         command("smile");
            me->set_skill("sea-blade",4);
            obj->delete_temp("kill_wang");
            break;
            }
}

