// Npc: /u/a/alickyuen/npc/1.c

inherit NPC;

void create()
{
	set_name("酒井法子", ({"noriko"}) );
	set("long", "她是世界上最美麗的女歌手.\n");
	set("race", "人類");
	set("age", 24);
	set("level", 60);
  set("gender", "女性" );
set("max_hp",70000);
set("max_mp",70000);
set("max_ap",70000);
set_skill("parry", 100);
set_skill("dodge", 100);
set_skill("sword", 100);
       
	setup();
carry_object( "/u/s/shengsan/npc/wp/lukysword.c")->wield();
}
//void init()     <----備忘錄
//{
 //       object ob;
  //      if( objectp( ob = find_living("bennyng") ) )
 //       {
//ob-> die();
 //       }
 //       ::init();
//}
//'void init()
//{
//        object leader;
//        if( objectp( leader = find_living("alickyuen") ) )
//        {
//                set("creater",leader);
//                set_leader(leader);
//                return;
//        }
//        ::init();
//}


