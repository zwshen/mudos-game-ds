// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================基本設定==========================

        set_name( "李小姐", ({ "miss lee","lee"}));
        set("long", "一個清秀的年輕小姐﹐她在這裡的工作是提供旅客存放款的服務。\n\n"
        	    +"  查詢帳戶請用 <balance> \n"
        	    +"  看存錢請用 <deposit 金額> \n"
                +"  要提款請用 <withdraw 金額> \n\n"
        );
        set("level",20);
        set("title","[1;32m金融人員[m");
        set("gender", "女性");
        set("race", "人類");
        set("age", 42);
        set("exp",1000);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
        set("str",31);			//設定屬性(可免)
        set("dex",21);			//也可以只設定 level
        set("con",33);			//其他沒設定的屬性系統就會自動產生,
        set("int",18);			//即使是相同的level也會有不同屬性.
        
        set("combat_exp",2000);		//戰熟(約在mob level的100倍左右為宜)
        
        //新的修正: 注意!! (wimpy)
        set("wimpy", 20);		//逃跑wimpy (20%)
        
        set("evil",-20);		//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("blade",40);		// 技能(自定)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

   set("attitude", "peaceful");   //溫和的 NPC。
   set("talk_reply","想存錢(deposit)嗎? 常常存款可以避免遺失喔!!");

  set("chat_chance", 3 );  //動作機率
  set("chat_msg", ({       //動作內容
(:command("smile"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做李艷珍.. 請多指教!![m
LONG );

        setup();

      add_money("dollar", 120);		//帶的錢(coin古代,dollar現代,未來沒有)

}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}


