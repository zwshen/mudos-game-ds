// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name("李長風", ({"lee charn fan","lee","fan"}));
        set("long",@LONG
一個滿頭白絲的老人，正在這裡掃地，動作看來雖然遲緩，但是
卻有一股說不出的流暢感。舉足不留痕，舞帚不揚灰，看來不是一個
平凡的老頭兒。

LONG
        );
        set("gender", "男性");
        set("title","掃地老叟");
        set("race", "human");
 	set("level",22);
        set("age", 76);
        //set("exp",300);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
			
//        set("env/wimpy", 10);		//逃跑wimpy (10%)
        set("evil",-20);		//邪惡度 -20 (正的表邪惡, 負表善良)

	set_skill("unarmed",99);	// 技能(自定)
	set_skill("combat",90);		//
	set_skill("fork",70);		//
	set_skill("bagi_fist",30);
	set_skill("horse-steps",20);
	set_skill("staff",90);
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (:command("exert hurrycan_staff"):),
         }) );

	
   set("attitude", "peaceful");   //溫和的 NPC。
set("inquiry",([
  "bagi":"八極神槍李就在小屋(house)裡面，進去(enter)見他吧。",
  "八極門":"八極神槍李就在小屋(house)裡面，進去(enter)見他吧。",
 ]));
set("talk_reply","...");
      setup();
      //set_element("metal");  //向性: none,metal,plant,wind,ground,water,fire
      add_money("coin", 820);		//帶的錢 古代:coin 現代:dollar 未來則用set("bank/future",數量);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/ironbroom_21")->wield();
}


