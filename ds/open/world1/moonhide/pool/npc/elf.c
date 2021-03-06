#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("掘寶地精", ({ "dig-treasure earth_elf","elf" }) );
  set("race", "beast" );
  set("gender", "雄性" );
  set("limbs", ({ "身體","手部","腳部","頭部" }) );
  set("verbs", ({ "bite","claw" }) );
  set("age", "???");
  set("long","身長大概一尺半的綠色矮人，臉上滿是坑疤及大大小小的疣，身上的衣衫破破爛爛的\n"                   "但是身後卻背了一個黃色的大布包，不知道裝了些什麼東西？\n");
  set("level",1); 
  set("no_kill",1);     
  set("attitude", "friendly");
  set("sell_list",([
       __DIR__"obj/shield" : 50, 
       __DIR__"obj/ten-sword": 50,
       __DIR__"obj/scroll":50,       
       __DIR__"obj/lbg":50,
     ]) );
  // all supply_point changed from 10->50 by alickyuen@ds 2003-02-18
  setup();
}
  
void init()
{        
  object ob,el;
  el = this_object();  
  ::init();   
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 10+random(30), ob); //1->10+random(30)  by ksj
  }   
  add_action("do_buy","buy");
  add_action("do_list","list");  
}
 
void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  switch( random(7) )
  {
    case 0:
         say( "掘寶地精說：你是人類是吧？咯咯咯咯......來買個上好貨吧...\n");
         break;
    case 1:
         say( "掘寶地精說：咯咯咯咯.....老子現在不想賣東西.....後會無期啦 !!。\n"); 
         destruct(this_object());
         break;
    case 2:
         say( "掘寶地精說：你看後面！(正當你看後面的時候)。\n"); 
         say( "掘寶地精說：咯咯咯咯....想不到人類這麼笨！！再見啦 ~ ~\n");
         destruct(this_object());
         break; 
    case 3:
         say( "掘寶地精說：多謝你的果子ㄚ ~ ~ ~ 再會啦 ~ ~ ! !咯咯咯....\n");
         destruct(this_object());
         break;  
    case 4:
         say( "掘寶地精說：唉呀呀~~~我忘了瓦斯還沒關啊~~~~咯咯咯咯~~~閃嚕~~~\n");
         destruct(this_object());
         break; 
    case 5:
         say( "掘寶地精說：瑪麗亞在叫摳我了∼∼∼∼∼再會啦∼∼！！\n");
         destruct(this_object());
         break;
    case 6:
         say( "掘寶地精說：我家垃圾還沒倒∼∼∼∼∼∼我先走啦∼∼∼∼咯咯咯咯\n");
         destruct(this_object());
         break;     
  }
}
