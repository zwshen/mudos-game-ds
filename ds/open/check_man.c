/* 
 * 提供線上玩家角色屬性總和列表
 *
 *
 */
#include <ansi.h>
inherit NPC;
int sort_atts(int at1, int at2);
void create()
{
//=========================基本設定==========================

        set_name( "龍一", ({ "ryu ichi","ryu","ichi"}));
        set("long", @LONG
映入眼簾的是一位微胖的中年男子，親切的眼神中透著一股幹練
的成熟感。年輕時的他是一位勇敢的冒險商人，在一次幾乎喪命的事
件中被正巧經過的冒險者所搭救，此後便駐守在此地幫助冒險者們解
決一些疑難雜症。

     checkclub	< 幫會名稱 >	補發幫會信物 [免費]
     checkuser	< 玩家的id >	調查線上某位玩家屬性強度 [200元/次]
          (PS. 巫師可使用userdata指令取得線上玩家屬性總和列表)

LONG
        );
        set("level",50);
        set("title","[1;33m社工[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("exp",10);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
        set("str",73);			//設定屬性(可免)
        set("dex",54);			//也可以只設定 level
        set("con",67);			//其他沒設定的屬性系統就會自動產生,
        set("int",58);			//即使是相同的level也會有不同屬性.
        
        set("evil",-20);			//邪惡度 20 (正的表邪惡, 負表善良)

//========================態度類別=================================
//   set("attitude", "friendly");   //友善的 NPC。
   set("attitude", "peaceful");   //溫和的 NPC。
//   set("attitude", "heroism");    //英雄主義的 NPC。
//   set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。
//   set("attitude", "killer");     //嗜殺成性的 NPC。


//===========================問題回答==================================
set("inquiry", ([
"name":"在下龍一，請多多指教。\n",
"club":"據我所知，目前有四大幫會，分別是『神族』『狂龍』『月族』還有『天地』。\n",

// add by alickyuen
"marry" : "你最近的婚姻生活如何喔？\n",
]));
       setup();

//==========================裝備道具=============================
//      add_money("coin", 200);		//帶的錢
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}
/*
int talk_action(object me)	//talk 時會執行此函式.
{
 command("say 你如果掉了幫會信物就來找我申請(checkclub)吧!");
 return 1;
}
*/
void init()
{
	::init();
	add_action("do_checkclub","checkclub");
	add_action("do_checkuser","checkuser");
	add_action("do_checkmarry","checkmarry");
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
int do_checkuser(string arg)
{
	object me,target;
	string msg="",target_name="";
	int *atts;
	me=this_player();
// if(!arg || arg=="") return notify_fail("checkclub < ^@^P^W|^FW^Z^Y > ^H^R^Fp: checkclub moon ^AC\n");
 if(!arg || arg=="") return notify_fail("checkuser < 玩家id > 例如: checkuser luky \n");
	
	if(!target=find_player(arg)) return notify_fail("目前線上找不到這位玩家。\n");
	if(wizardp(target) && !me->visible(target)) return notify_fail("目前線上找不到這位玩家。\n");
	if(!me->can_afford(200))
		return notify_fail("這項服務需要200元，而你身上的錢不夠。\n");
	 me->receive_money(-200);
	atts = ({ target->query("con"), target->query("int"), target->query("str"), target->query("dex") });
	atts = sort_array(atts, -1);
	target_name=target->query("name")+"(" + capitalize(target->query("id")) + ")";
        
    msg = sprintf("龍一拿出一本黃皮小冊子翻了一下，然後說:\n\n"+
    	"\t%s 目前的等級是 %d 級，年齡是 %d 歲，\n\t屬性總和有 %d 點，其中最高的屬性是 %d 點。\n",
	target_name,target->query("level"),target->query("age"),target->query_total_gift(),atts[0]);
//    msg+=sprintf("%d,%d,%d,%d\n",atts[0],atts[1],atts[2],atts[3]);
    me->start_more(msg);
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
        say( "龍一說﹕多謝囉﹐祝您的冒險一切順利。\n");

        return 1;
}
/*	add by alickyuen	*/
int do_checkmarry()
{
}
