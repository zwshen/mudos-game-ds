// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
//=========================基本設定==========================

        set_name( "王大發", ({ "dar far wang","wang"}));
        set("long", "一個打工的年輕人﹐正在這裡擺\攤位賺取學費。\n\n"
        	    +"  看存貨請用 <list> \n"
        	    +"  要買東西用 <buy 物品> <buy 數量 物品> \n\n"
        );
        set("level",20);
        set("title","[1;32m小販[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("combat_exp",2000);		//戰熟(約在mob level的100倍左右為宜)
//        set("env/wimpy", 20);		//逃跑wimpy (20%)
        set("evil",-20);		//邪惡度 20 (正的表邪惡, 負表善良)

   set("attitude", "peaceful");   //溫和的 NPC。
   set("talk_reply","多買點東西就算幫了大忙囉..呵呵..");

//注意. 要設定貨品清單

   set("sell_list",([	
           "/u/l/luky/npc/item/bag"    : 25, //表示每買一個袋子會扣15點補給點數
           "/u/l/luky/npc/item/dump"   : 10, //除非有特殊理由否則不可設為0 (無限量供應)
       ]) );				     //玩家基本有40點, 每一等級再加20點. Lv25=540點

  set("chat_chance", 3 );  //動作機率
  set("chat_msg", ({       //動作內容
"王大發笑笑的說: 大老闆, 要不要買點東西<take>啊? 我賣的東西<show>是附近最便宜的喔!\n",
(:command("dance master"):),
(:command("coffee wang"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做王大發.. 請多指教!![m
LONG );

        setup();

      add_money("coin", 120);		//帶的錢
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}


