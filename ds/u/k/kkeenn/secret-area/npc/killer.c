#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIY"黃塵魔"NOR,({"yellow storm robot","robot"}) );
        set("long",@LONG
一百年前，由一群地下成最頂尖的生化科學家以黃沙和一些不知名的
物質合成的怪物，本想由它來開闢新礦坑，可是由於其中一個科學家的設
計中出了瑕疵，變成了禁止通行用的怪物，略通人話 。
LONG
);
        set("title","『失敗作品』");
         set("age",100);
         set("level",60);
         set("gender","中性");
         set("max_hp",10200);
         set("hp",10200);
         set("race","human");
        set("talk_reply","朋友, 你能幫我從城主那老廢物那取得資料碟嗎?\n");
        set("attitude", "peaceful");
       set_spell("summon_wind",100);
  set("chat_chance_combat", 100);       
  set("chat_msg_combat", ({
                (:command("cast summon_wind"):),
                 }) );
        set("chat_chance", 13);
        set("chat_msg",({ 
               (: random_move :),
        "黃塵魔的四周捲起了重重的龍捲風？\n",
        "黃塵魔說: 誰能幫我打城主那死老頭？\n",
        "黃塵魔說: 誰可以給我資料碟, 我以後就幫他作戰。\n",
        "黃塵魔說: 誰能把城主的資料碟拿給我？\n",
        "黃塵魔身上的殺氣慢慢的散發出來。\n",
        }));
          set("addition_armor",100);
          set("Merits/wit",3);
          set("addition_damage",50);
          add("apply/hit",50);

        setup();
}
int accept_object(object who,object ob)
{
        object ic, npc = this_object();
        if(ob->name()!="資料碟")  return 0;
        else {            
        message_vision("$N給了黃塵怪一片$n。\n",who,ob);
        destruct(ob);
        command("say 這可是那難得的資料碟！！這.....這...");
        command("thank "+who->query("id"));
        command("say 這真是太感激你了。");
        command("say 好吧！那這樣我把自己的技巧晶片給你好了。");
        ic=new(__DIR__"obj/ic2");
        ic->move(who);
        set("chat_msg",({
        "黃塵怪高興地說道：終於, 終於得到了..\n",
        (:command("ya"):),            
        }) );
        command("say 掰掰~~朋友~~我們後會有期。");
        command("wave");
        set_temp("control",1);
       destruct(npc);
        return 1;
        }
}
void reset()
{
        set("chat_msg",({
     "黃塵怪說道: 好想要歐....\n",
        }) );
        return;
}


void die()
{
        object ob;
        object control;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
     message("world:world3:vision",
HIG"\n【地城急報】"+HIW"
地下城百年障礙-"HIY"黃塵魔"HIW"敗在"+ob->name(1)+"的手下！！\n\n"+NOR,users());
           ob->add("popularity",1);
  control=new(__DIR__"obj/control.c");
   tell_object(ob,HIW"你從黃塵魔身上取得生化控制器!!(You Get The Control!!)\n"NOR);
   control->move(ob);
        ::die();
        return;
}

