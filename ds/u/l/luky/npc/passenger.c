#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name( "旅客", ({ "passenger","旅客","passenger",}));
        set("long", "一個滿臉橫肉的旅客﹐正在被安全警衛盤問著。\n"
        );
        set("level",20);
        set("title","[1;33m外地人[m");
        set("gender", "男性");
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
//        set("env/wimpy", 20);		//逃跑wimpy (20%)
        set("evil",20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("blade",40);		// 技能(自定)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================態度類別=================================
//   set("attitude", "friendly");   //友善的 NPC。
   set("attitude", "peaceful");   //溫和的 NPC。
//   set("attitude", "heroism");    //英雄主義的 NPC。
//   set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。
//   set("attitude", "killer");     //嗜殺成性的 NPC。


//=============================自動動作=================================
  set("chat_chance", 0 );  //動作機率
  set("chat_msg", ({       //動作內容
"旅客用力的踢了牆壁一腳!! 似乎非常生氣..\n",
(:command("say 哇靠!! 這是什麼服務態度嘛!!!"):),
(:command("say 到底要我說幾次啊~~ 這把開山刀是我剛剛撿到的.."):),
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m我叫做牛過...你問這個幹什麼?? 無聊!![m
LONG );


//=========================戰鬥訊息===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"旅客破口大罵 : 「可惡的傢伙∼﹗我打死你﹗」\n"NOR,
     }) );

        setup();

//==========================裝備道具=============================
      add_money("coin", 200);		//帶的錢
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk 時會執行此函式.
{
 command("smile "+me->query("id") );
 return 1;
}

void init()
{
	::init();
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m安全警衛馬上站出來對$N[1;37m說: 請不要動手, 交給我們處理就好了。[m\n",this_player());
 return 1;
 }
return 0;
}

//======================動作反應======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"旅客(passenger)想謀殺我!! 旅客(passenger)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在氣頭上居然敢踢我!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"旅客(passenger)想謀殺我!! 旅客(passenger)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在氣頭上居然敢偷打我!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say 滾遠一點!!別煩我!!");
                break;
        }
}

//======================接受反應======================================
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("他不想收你的東西。\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "旅客說道﹕多謝這位" + RANK_D->query_respect(who)
                + "﹐神明一定會保佑你的。\n");

        return 1;
}

void reset()
{
        // delete("memory");
}
