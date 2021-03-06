#include <ansi.h>
#include <dbase.h>
//award eq list
string *file=({"bestaxe","bestfork","bestneck","bestsword","doll",
              "moonshade","lightwaist","fairsword","fairring","fairfist",
              "poorboots","poorcloth","poordagger","superpill"});

inherit F_VENDOR;
inherit NPC;
void gotoinn();
void create()
{
//=========================基本設定==========================

        set_name( "夢境幻影", ({ "dream illusion","illusion" }));
        set("long", "它是一個身體影像若有若無, 變化萬千的幻影...看起來相當神秘。\n");
        set("level",60);
        set("title","七域之影");
        set("gender", "男性");
        set("race","human");
        set("age",777);
//        set("exp",1000);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
//        set("str",100);			//設定屬性(可免)
//        set("dex",80);			//也可以只設定 level
//        set("con",80);			//其他沒設定的屬性系統就會自動產生,
//        set("int",80);			//即使是相同的level也會有不同屬性.
        
//        set("combat_exp",2000);		//戰熟(約在mob level的100倍左右為宜)
//        set("evil",20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("unarmed",100);		// 技能(自定)

//========================態度類別=================================
   set("attitude", "friendly");   //友善的 NPC。
//   set("attitude", "peaceful");   //溫和的 NPC。
//   set("attitude", "heroism");    //英雄主義的 NPC。
//   set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。
//   set("attitude", "killer");     //嗜殺成性的 NPC。


//=============================自動動作=================================
  set("chat_chance",10);  //動作機率
  set("chat_msg", ({       //動作內容
(:command("hmm"):),
(:command("say 有問題的話, 可以問我(talk with me)喔!"):),
}) );

//===========================問題回答==================================
//set("inquiry/name","我叫做吳生四...你好");


//=========================戰鬥訊息===========================
//     set("chat_chance_combat", 17);
//     set("chat_msg_combat", ({
//(:command("kick "+this_player()->query("id")):),
// HIR"大嘴很不爽的說 : 「可惡的傢伙∼﹗PK就PK, 誰怕誰﹗」\n"NOR,
//     }) );


// 排程動作

set("schedule",
([
	"00" : (: gotoinn :),
	"06" : (: gotoinn :),
	"12" : (: gotoinn :),
	"18" : (: gotoinn :)
]));
        setup();

//==========================裝備道具=============================
//      add_money("coin",200);		//帶的錢
//      carry_object("/u/l/luky/npc/item/bag");
      //carry_object(__DIR__"wp/kaisan_b")->wield();
      //carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk 時會執行此函式.
{
 command("hmm "+me->query("id") );
 command("say 有何貴幹? 哦, 大概是想換獎勵品的吧.");
 command("say 嗯. 告訴我你要拿多少貢獻值出來換, 我就會給你一些東西.");
 command("say 價目表自己打 glist 看看吧.");
 return 1;
}

void gotoinn()
{
 int a=random(4);
	if(!find_object("/open/world1/tmr/area/hotel")) return;
	if(!find_object("/open/world1/cominging/area/hotel")) return;
	if(!find_object("/open/world1/acme/area/hotel")) return;
	if(!find_object("/open/world2/shengsan/aovandis/room079")) return;
 message_vision("神秘的幻影一個閃身, 突然消失在眾人之前。\n", this_object());
 if( a == 0 ) {
   if( file_name(environment(this_object())) == "/open/world2/shengsan/aovandis/room079" ) a++;
   else this_object()->move("/open/world2/shengsan/aovandis/room079"); 
 }
 if( a == 1 ) {
   if( file_name(environment(this_object())) == "/open/world1/cominging/area/hotel" ) a++;
   else this_object()->move("/open/world1/cominging/area/hotel");
 } 
 if( a == 2 ) {
   if( file_name(environment(this_object())) == "/open/world1/acme/area/hotel" ) a++;
   else this_object()->move("/open/world1/acme/area/hotel");
 }
 if( a == 3 ) {
   if( file_name(environment(this_object())) == "/open/world1/tmr/area/hotel" ) a=0; 
   else this_object()->move("/open/world1/tmr/area/hotel");
 }
 message_vision("突然一個神秘的幻影站在你眼前, 你根本不知道它是何時出現的。\n", this_object());
}

void init()
{
	::init();
        add_action("do_glist","glist");
	add_action("do_change","change");
}
string item_desc(object ob)
{
	if(ob->query("skill_type")) return HIG+"武器"+NOR;
	else if(ob->query("armor_type")) return HIY+"防具"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"回復"+NOR;
	else return "道具";
}
int do_glist(string arg)
{
  string dir,list;
  object awardeq;
  int i,a,awardcost;
  dir = "/open/world1/award/";
  i = sizeof(file);
  list = "\n\n┌───────────────────────────┐\n";
  list +="│ 所需貢獻值        種類   目前可以兌換的物品          │\n";   
  list +="└───────────────────────────┘\n";
  for(a=0;a<i;a++) {
    if(load_object(dir+file[a])) {
      awardeq = load_object(dir+file[a]);
      awardcost = awardeq->query("needaward");
      list += sprintf("%6d ------------- %4s  %-30s",awardcost,item_desc(awardeq),awardeq->short()); }
    else break;
    list += "\n";
  }
  list +="\n";
  list +=" 注意事項: 兌換之後的物品遺失問題, 在下概不負責. 而此處兌換的\n";
  list +="           物品, 除了可以永久保存之外, 皆與一般物品無異, 務必\n";
  list +="           小心收藏! 要兌換請用 change 指令(尚未完成).\n";
  this_player()->start_more(list);
  return 1;
}
int do_change(string arg)
{
  return 0;
}

//======================動作反應======================================
/*void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"大嘴(bigmouth)想謀殺我!! 大嘴(bigmouth)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在用功\居然敢踢我!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"大嘴(bigmouth)想謀殺我!! 大嘴(bigmouth)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在用功\居然敢踢我!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say 滾遠一點!!別煩我!!");
                break;
        }
} */

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
        say("夢境幻影說道﹕多謝這位" + RANK_D->query_respect(who)
                + "﹐神明一定會保佑你的。\n");

        return 1;
}

void reset()
{
        // delete("memory");
}
