#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
 set_name( "黑鷹", ({ "black eagle","eagle"}));
        set("long", "他是惡靈駭客的下屬，職業是位軍火商，且擁有眾多的管道，
在他這裡，無論是什麼樣的稀世刀劍，都是應有盡有，沒有
買不到的東西，與黑熊、黑貓並列《惡靈三俠》。\n\n"
        	             +"  看存貨請用 <list> \n"
        	             +"  要買東西用 <buy 物品> <buy 數量 物品> \n\n"
        );
        set("level",50);
        set("title",HIR"惡靈三俠"NOR);
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("combat_exp",5000);
        set("evil",60);
set("sell_list",([	
           "/u/h/hack/wp/sevenstar.c"  :10,
        "/u/h/hack/wp/shangsword.c"  :10,    
        "/u/h/hack/wp/oldsword.c"    : 10, 
           "/u/h/hack/wp/sunsword.c"   : 10,  
         "/u/h/hack/wp/dab-aqua-claw.c"   : 10,  
         "/u/h/hack/wp/dragon-fist.c"   : 10,  
         "/u/h/hack/wp/lance.c"   : 10,  
         "/u/h/hack/wp/staff.c"   : 10,  
         "/u/h/hack/wp/sword2.c"   : 10,  
         "/u/h/hack/wp/blade.c"   : 10,  
        "/u/h/hack/wp/blade2.c"   : 10,  
        "/u/h/hack/wp/coldpike.c"   : 10,  
        "/u/h/hack/wp/darksword.c"   : 10,  
        "/u/h/hack/wp/evilsword.c"   : 10,  
        "/u/h/hack/wp/masterfork.c"   : 10, 
       "/u/h/hack/wp/s_blade.c"   : 10, 
     "/u/h/hack/wp/moon_tooth.c"   : 10,
     "/u/h/hack/wp/staff.c"   : 10,
     "/u/h/hack/wp/seven-staff.c"   : 10,
 ]) );		


        set("attitude", "peaceful");   //溫和的 NPC。
        set("talk_reply","在我這裡沒有買不到的武器..嘿嘿嘿..");
     
 setup();

      add_money("coin", 120);		//帶的錢
      
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}

	