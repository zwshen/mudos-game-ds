#include <ansi.h>
inherit NPC; 
void combat_ai();  
void identify(); 
string *show_msg = ({
HIC"你發覺四周的人看你的眼神似乎有些不對……\n"NOR,
WHT"大家都對你發出詭異的笑容……看來是該開溜了……\n"NOR,
HIC"當你發現事態不對，準備開溜的同時，從背後被人賞了一記悶棍，接著就昏了過去……\n"NOR,
WHT"你在半昏半醒中，隱約聽到她們在討論些什麼……\n"NOR,
HIY"小嘍囉甲：嘿嘿…今天這個貨色好像不錯…\n"NOR,
HIG"小嘍囉乙：把他抓去給寨主，讓他當個壓寨少爺吧！"BLK"\n"NOR,
HIY"小嘍囉甲：好主意，就這麼辦吧∼\n"NOR,
HIG"小嘍囉乙：這樣我們的職位應該會三級跳吧，嘿嘿…\n"NOR, 
HIW+BLK"你一睜開眼睛，你發覺你已經到了一個你完全不認識的地方了……\n"NOR,});
void create()
{
 set_name("小嘍囉",({"bandit's lackey","lackey","bandit"}));
 set("long",@LONG  
在你眼前的就是隨處打劫十萬山山道中旅人錢財的土匪, 傳
聞道十萬山中的土匪各各兇悍無比, 但卻都是女人. 看來這
個傳聞絕非空穴來風. 
LONG);

 set("title",YEL"十萬山山寨"NOR);
 set("age",23+random(15));
 set("gender","女性");
 set("level",25);  
 set("max_hp",8000+random(3000)); 
 set("max_ap",8000); 
 set("str",75+random(18)); 
 set("dex",75);  
 set("Merits/bar",5+random(3));  
 set("Merits/wit",5+random(3)); 
 set_temp("apply/damage",85+random(30)); 
 set_temp("apply/hit",15+random(30));
 set_skill("sword",80+random(15)); 
 set_skill("blade",80+random(15));
 set_skill("whip",80+random(15));
 set_skill("dagger",80+random(15));
 set_skill("hammer",80+random(15));
 set_skill("fork",80+random(15));
 set_skill("throwing",80+random(15));
 set_skill("dodge",70+random(15)); 
 set_skill("parry",70+random(15)); 
 set_skill("block",70+random(15));  
 set("can_speak", 1); 
 set_temp("Notwarnpc",1);
 setup(); 
/* 
 carry_object(__DIR__"silk_cloth")->wear();
 carry_object(__DIR__"eq/large_blade")->wield();
 carry_object("/open/world1/eq/moon_skirt")->wear();
*/
}

void init()
{
  object me=this_player(),ob=this_object();
 
  ::init(); 
  if ( !me->query("class1") ) return;
  if ( me->query_temp("invis") ) return;
  ob->kill_ob(me);
  me->kill_ob(ob);

} 
 
int talk_action()
{
        object me=this_player(),ob=this_object();

  if( me->query("gender") == "女性" || me->is_fighting() || me->query("class1") ){
  command("say 妳還是先解決妳自己的問題吧..");
  } else if( me->query("gender") == "男性" && !me->query("class1") ){
  command("hehe "+me->query("id"));
  ob->set_temp("kidnap",1);
  me->set_temp("block_msg/all",1);
  me->move(__DIR__"../bandit13");
  me->start_busy(20);
  me->add_temp("block",1);
  call_out("kidnap", 2, this_object());
  }

  return 1;
}

void kidnap()
{
  object me=this_player(),ob=this_object();
  int i=ob->query_temp("kidnap");
  string msg = show_msg[i-1];
  me->delete_temp("block_msg/all");
  write(msg);
  me->set_temp("block_msg/all",1);
  ob->add_temp("kidnap",1);
  if( i > 8 ) {
  delete_temp("kidnap"); 
  me->delete_temp("block_msg/all");
  return 0;
  }
  call_out("kidnap", 2);
  return 0;
}


