// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void call_help();
void create()
{
//=========================基本設定==========================

        set_name( "錢莊老板", ({ "bank boss","boss"}));
        
        set("long", "一個身穿華麗服飾的中年人, 是磐龍錢莊的老板。\n\n"
                    +"  查詢帳戶請用 <balance> \n"
                +"  要存錢請用 <deposit 基本金額> \n"
                    +"  要提錢請用 <withdraw 基本金額> \n\n"
        );
        
        set("level",17);
        set("gender", "男性");
        set("race", "人類");
        set("age", 30);
        set("evil",20);                 //邪惡度 20 (正的表邪惡, 負表善良)
           set("attitude", "peaceful");   //溫和的 NPC。
           set("talk_reply","想存錢(deposit)嗎? 常常存款可以避免遺失喔!!");
        
          set("chat_chance", 3 );  //動作機率
  set("chat_msg", ({       //動作內容
        (: command("stare") :),
        }) );

        setup();

}

void init()
{
  ::init();
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}


