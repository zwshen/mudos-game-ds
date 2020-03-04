#include <ansi.h>

inherit NPC;

void create()
{
  set_name(HIW"無名老人"NOR, ({"unnamed old-man","man","old","unnamed"}) );
  set("long",@LONG
古墓的管理員。
LONG
);
  set("race", "human");
  set("unit","隻");
  set("age",54); 
  set("no_fight",1);  set("level",30); 
  set("chat_chance",4);
  set("chat_msg",({
  "無名老人說:我肚子好餓啊 ~ ~ ! !\n",
  "無名老人說:您可以給我東西吃嗎,我會以禮相贈的。\n",
  "無名老人咳了幾聲，身體好像不怎麼好  . ..\n",
}));
set_skill("unarmed",50);
set_skill("staff",60);
set_skill("dodge",120);
set_skill("parry",70); 
setup();
carry_object(__DIR__"red-staff")->wield(); 
add_money("coin",200);
} 
int accept_object(object who,object ob)
{
object blade;

       if(ob->name()!="饅頭")
  
       return 0; 
       else {
     
       if(this_object()->query_temp("give_blade"))
       {
       command("think 我已把虎魄給人了..該怎麼報答這位呢..?");
       command("think"+who->query("id"));
       command("say 好吧 ! 老夫就再送一樣瑰寶給你 !");
       return 0;
} 
message_vision("$N給了無名老人一顆饅頭\n",who,ob);
  command("無名老人拿起了饅頭，高興的吃了起來\n");
  command("smile"+who->query("id"));
  command("無名老人說:謝謝你，雖然不是很飽，但也不會怎麼餓了\n");
  command("think"+who->query("id"));
  (: command("hmm"):);
  blade=new(__DIR__"blade");
  blade->move(who);
       set_temp("give_blade",1);
       start_busy(5);
//call_out("delay",600,this_object());
       return 1;
       }
}

void reset()
{
           int old;  
           if(!old) return; 
           set("chat_chance",5);
           set("chat_msg",({
           "無名老人的肚子又餓了起來的樣子...?\n",
           "無名老人看著路上的人，手搓揉著肚子，嘴巴微攪，雙眼露出期待的眼神\n",
           }) );
             return 0; 
}

