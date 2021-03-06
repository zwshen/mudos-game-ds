#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
        set_name( "伏魔羅漢" ,({"fu-mo luo hang","fu-mo","lo","hang"}) );
        set("long",@LONG
在你眼前正是佛界中赫赫有名的伏魔羅漢，為如來佛祖身旁專管去妖除魔
的工作，具有無上的神通力。伏魔羅漢對於做惡的鬼怪，是從不手下留情的，
對於心腸善良的人或動物，則是慈愛有加，毫不因一已之強而加害。
LONG
);
        set("age",200);
        set("race","人類");
        set("title","尊者");
        set("level",40);
        set("attitude", "friendly");   //友善的 NPC。
		set("gender", "男性" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        setup();
        set_living_name("buddha-war-jingang");
                set("combat_exp",500000);
		carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/boots")->wear();
}

void die()
{
        object ob,me;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }
		me=this_object();
		message_vision(
		HIR "\n$N強烈的死亡恐懼，致使他用盡全身的力量做出最後一擊！！\n\n"
	   +HIY "$N使出如來九式第五式" + HIY "「迎佛西天」，一拳浩蕩無涯的氣勁直往$n面前攻去！！\n\n" NOR
	   	,me,ob);
                 if( random(10)>4) {
			message_vision(HIR "$N難以躲避，狠狠地被擊飛數丈之遠！！\n" NOR,ob );
			ob->set("hp",ob->query("max_hp")/10);
	        COMBAT_D->report_status(ob);
			tell_room(ob,CYN +"(" + ob->query("name")+"帶著一道鮮血往南飛了過去...)\n" NOR,ob);
			ob->move(TMR_PAST"advbonze/summit1.c");
                        tell_room(environment(ob),ob->query("name")+"全身沾滿鮮血的飛了過來，「碰」的一聲摔在雪地上。\n",ob);
			ob->start_busy(1);
		} else {
			message_vision(HIW "$N勉強地躲避了這致命一擊，但也臉色嚇得蒼白...\n" NOR,ob );
		}
        tell_object(ob,HIG"\t你得到二點聲望。\n"NOR);
        ob->add("popularity",2); //聲望

        ::die();
        return;
}
