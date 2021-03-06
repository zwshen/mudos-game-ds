#include <ansi.h>
#define DRAGON_M "/open/always/dragon_mark"
#define MOON_M "/open/always/moon_mark"
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name( "幫會使者", ({ "club messager","messager"}));
        set("long", "一個黑衣人。\n你如果遺失了幫會信物, 可以打(checkclub)向他申請一個新的信物。\n"
        );
        set("level",1);
        set("title","[1;33m義工[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 1);
        set("exp",10);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
        set("str",1);			//設定屬性(可免)
        set("dex",1);			//也可以只設定 level
        set("con",1);			//其他沒設定的屬性系統就會自動產生,
        set("int",1);			//即使是相同的level也會有不同屬性.
        
        set("combat_exp",1);		//戰熟(約在mob level的100倍左右為宜)
//        set("env/wimpy", 20);		//逃跑wimpy (20%)
        set("evil",-20);			//邪惡度 20 (正的表邪惡, 負表善良)

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
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
你問這個幹什麼?? 無聊!!
LONG );


//=========================戰鬥訊息===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"旅客破口大罵 : 「可惡的傢伙∼﹗我打死你﹗」\n"NOR,
     }) );

        setup();

//==========================裝備道具=============================
//      add_money("coin", 200);		//帶的錢
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk 時會執行此函式.
{
 command("say 你如果掉了幫會信物就來找我申請(checkclub)吧!");
 return 1;
}

void init()
{
	::init();
	add_action("do_checkclub","checkclub");
}

int do_checkclub(string arg)
{
	object me,mark,old_mark;
	string mark_file="";
	me=this_player();
	if(!arg) return notify_fail("checkclub < 幫會名稱 > 例如: checkclub moon 。\n");
	if(CLUB_D->check_member(arg,getuid(me)) == 0 ) return notify_fail("錯誤的幫會名稱或是你不在幫會名單中。\n");
	mark_file=CLUB_D->query_club_mark(arg);
	if(mark_file=="") return notify_fail("幫會信物檔案尚未登錄。\n");
	
	if(!mark=new(mark_file)) return notify_fail("幫會信物檔錯誤。\n");
	
	if(old_mark=present(mark->query("id"),me)) return notify_fail("你已經有幫會信物了。\n");
	
	if(!mark->can_move(me))
	{
	 destruct(mark);
	 return notify_fail("你要先丟掉一些東西才拿的動幫會信物。\n");
	}
	mark->move(me);
	message_vision("$N拿了一"+mark->query("unit")+mark->name()+"給$n。\n",this_object(),me);
	me->save();
	return 1;

}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("他不想收你的東西。\n");
        else if( val > 1000 )
        {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/10000) );
        }
        say( "使者說道﹕多謝這位" + RANK_D->query_respect(who)
                + "﹐神明一定會保佑你的。\n");

        return 1;
}
