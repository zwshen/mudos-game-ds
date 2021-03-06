#include <ansi.h>
inherit NPC;
void consider();
void create()
{
	set_name("石丈人", ({ "stone man", "stone", "man" }) );
        set("nickname", "盤石怪傑");
	set("gender", "男性");
     set("level",40);
	set("age", 130);
	set("long",
		"石丈人看來年事已高，留著一頭白色長髮和一把白鬍鬚，\n"
                "且穿著著白色長杉，遠遠望去，不知情的人還以為見到鬼\n"
                "魅了，他是在百年前令人聞之喪膽的武林怪傑，一套「盤\n"
                "石刀法」縱橫江湖，無人能出其右，但是在五六十年前，\n"
                "這位武林怪傑就此消聲匿跡，從此江湖上傳說不斷，說他\n"
                "被仇家殺死了，說他閉關苦練武功\為求更高境界，眾說紛\n"
                "云，但他身在何處，所為何事，卻極少人知道，或許\你可\n"
                "去問問他。\n"
           );
	set("attitude", "peaceful");
        set("talk_reply","你最好別來煩我！");
        set("inquiry", ([
            "消聲匿跡" : "你為何問我這問題！？\n"
            "            我在這兒修練武功\，順便引某物上門啊！！",
            "某物" : "石丈人說道：嘿嘿！！這無可奉告。",
            "旱魃" : "咦！？你也知道此怪！？難道牠已出現了不成！？\n"
            "            據稱，這旱魃會尋找寒冷的水域，而在水域之上修\n"
            "            練其內丹，我三十年前來到此地，發現這裡的小溪\n"
            "            異常寒冷，照著此怪的習性，把這的大石削平了，\n"
            "            等著此怪上門，一等就等了三十年了。",
            "內丹" : "我在這熬三十年所求的就是這老怪魃的內丹了。",
        ]) );
        set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
          (:command("exert stone-blade"):),
	}) );
	set_skill("unarmed", 120);
	set_skill("blade", 100);
     set_skill("stone-blade",100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();
         carry_object(__DIR__"wp/s_blade")->wield();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="暫不接受東西")
        {
           command("bag "+who->query("id"));
           command("say 老夫並不需要這個東西。");
           return 0;
        }
        else {
         destruct(ob);
           command("say 咦！？太好了！！我終於得到此內丹了！");
           command("say 如此一來，練功\可會事半功\倍呀！");
           command("jump");
//           if(who -> query_temp("kill_devil")>0 || who -> query_skill("stone-blade") >0)
//           {
//             command("say 這位"+RANK_D->query_respect(who)+"，實在是感激不盡，我就把這套「盤石刀法」教於你吧！");
//             message_vision("($N細心的學習石丈人所傳授的「盤石刀法」。)\n",who);
//             who->set_skill("stone-blade",1);
//           }
//           else {
             if(obj->query_temp("give_blade")>0)
             {
               command("say 我也沒什麼東西給你了，你自個兒好自為之吧！");
             }
             else {
               command("say 這樣吧！我把這把刀送給你。");
               command("give blade to "+who->query("id"));
               obj->set_temp("give_blade",1);
             }
//           }
           return 1;
        }

}
void consider()
{
	int i, flag = 0;
	object *enemy;

	enemy = query_enemy() - ({ 0 });
	for(i=0; i<sizeof(enemy); i++) {
		if( !living(enemy[i]) ) continue;
		if( enemy[i]->query_temp("weapon") ) {
			flag++;
			if(	!query_temp("weapon") ) {
				command("say " + RANK_D->query_respect(enemy[i]) + "既然使兵刃﹐在下空手接招未免不敬。");
				command("wield blade");
				command("say 進招吧﹗");
				break;
			}
		}
	}
	if( !flag && query_temp("weapon") ) {
		if( sizeof(enemy) > 1 )
			command("say 嗯... 既然" + chinese_number(sizeof(enemy)) + "位都是空手﹐在下理當奉陪﹗");
		else
			command("say 既然" + RANK_D->query_respect(enemy[0]) + "不使兵刃﹐在下自然奉陪﹗\n");
		command("unwield blade");
	}
}
