#include <ansi.h>
inherit NPC;
void create()
{
    set_name("冉紅塵",({"ran hon chen","ran","master"}));
	set("long" ,
    "他是血劍修羅「左宗平」唯一的弟子, 若現在左宗平還在世, 應該八十\n"
    "多歲了, 你眼前的冉紅塵眼睛炯炯有神, 氣宇軒昂, 似乎只有四十出頭,\n"
    "但事實上已經年過半百了, 你不禁開始相信練些高深的武學可以延年益壽,\n"
    "讓你青春永駐... 聽說冉紅塵練成了一套曠世劍法, 曾在古劍會之上力挫\n"
    "五大派掌門, 實力不容小覷。\n"
    );
	        set("attitude", "friendly"); 
    set("level",57);
	set("age", 52);
    set("nickname","血劍修羅嫡傳弟子");
	set("combat_exp", 300000+random(77777));
    set("chat_chance",5);
	set("chat_msg",({(:command,"say 唉, 為什麼總是有最後一道關卡突不開.":),
			 (:command,"sigh":),
			 (:command,"say 我自知大限將至....天啊..給我一點機會吧.":)}));
    set("chat_chance_combat",90);
   set("chat_msg_combat",({(:command,"exert thundersword":)}));
	set_skill("unarmed",70);
	set_skill("sword",90);
	set_skill("dodge",80);
	set_skill("force",90);
	set_skill("parry",90);
	set_skill("thundersword",90);
    map_skill("sword","thundersword");
    set("guild_gifts",({6,4,4,6}));
	setup();
	carry_object(__DIR__"eq/d_boots")->wear();
	carry_object(__DIR__"eq/shurasword")->wield();
	carry_object(__DIR__"eq/d_cloth")->wear();
}

