#include <ansi.h>
inherit NPC;
void create()
{
	set_name("王婆婆",({"grandma wang","wang","grandma"}) );
	set("long",@LONG
王婆婆今年已經七十有餘了，不過還是精神奕奕的喜歡到處串門子。
LONG);
	set("age",72);
	set("title","梅龍鎮民");
	set("level",18);
	set("race","human");
	set("gender","女性");
	set("evil",-10);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","現在的年輕人真的吃不了苦。");
	setup();

	carry_object(__DIR__"../eq/cloth_boots_5")->wear();
	carry_object(__DIR__"../eq/cloth_skirt_6")->wear();
	carry_object(__DIR__"../eq/cloth_robe_12")->wear();
	add_money("dollar",430);
}
int talk_action(object me)	
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 command("say "+@TALK_1
  聽說有顆巨大的水晶名為精靈之夢，可以引出生物體內的潛能。
希望這神聖的自然力量不要落入邪惡陣營裡。
TALK_1
 );
 //book->add_quests_note("SadSworder","『燒刀子』是一種極為濃烈的酒，為心情鬱悶，或是「為情所困」之人的最愛。");
 return 1;
}

