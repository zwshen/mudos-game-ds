#include <ansi.h>

inherit NPC;
//inherit GUILDMASTER;    // 新版的GUILDMASTER 可以不用繼承

void create()
{
	set_name("亞克", ({"master ark","master","ark"}) );
    set("gender", "男性");
    set("combat_exp", 100000);
    set("long",
    "他是諸位新手的指導教師，提供基本的技巧訓練。你可以\n"
    "使用"HIY"list"NOR"來看看有什麼技巧可以提供學習(train)。也可\n"
    "以用advance <level或屬性> 來升級, 升級前建議先使用\n"
    "level 指令來查閱\所需要的經驗值。\n"
    );
	set("title","退休勇者");
	set("race","human");
	set("no_join", 1);
	set("level", 62);
	set("age", 50);
        set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set("guild_skills", ([  // // 難度, 等級1可學的上限, 上限
		"unarmed":({70,5,99}),
		"blade":({70,5,99}),
		"sword":({70,5,99}),
		"whip":({70,5,99}),
		"axe":({70,5,99}),
		"dagger":({70,5,99}),
		"fork":({70,5,99}),
		"staff":({70,5,99}),
		"hammer":({70,5,99}),
		"dodge":({70,5,99}),
		"parry":({70,5,99}),
	]) );
	set("chat_chance", 5);
/*  set("chat_msg", ({
    "新手導師緩緩的道:"HIC"歡迎各位時空旅行者在這裡學習。"NOR"\n",
	"新手導師緩緩的在房間裡慢慢的走著。\n",
    }) ); */
	set("inquiry/master", "你可以利用導師(master)來學習(train or learn)技能與法術。\n");
	setup();

  carry_object(__DIR__"../wp/iron_staff_10")->wield();
  carry_object(__DIR__"../eq/leather_boots_8")->wear();
  carry_object(__DIR__"../eq/iron_armor_18")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("d_advance","advance");
        add_action("d_list","list");
        add_action("d_train","train");
}

int d_advance(string arg)
{
 if(this_player()->query("race")!="human") return notify_fail("只有人類(human)才需要靠拜師成長。\n");
 return GUILDMASTER->do_advance(this_object(),this_player(),arg);
}

int d_list(string arg)
{
 return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int d_train(string arg)
{
 if(this_player()->query("race")!="human") return notify_fail("只有人類(human)才需要靠拜師成長。\n");
 if(this_player()->query("class1") || this_player()->query("class2") ) 
   if(this_player()->query("class1")!="adventurer")
     return notify_fail(this_object()->name()+"說: 很抱歉，我只指導尚未加入職業門派的新進冒險者。\n");
 return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) )
        {
                case 0:
			say(this_object()->name()+"說:"HIC"歡迎各位冒險者在此學習基本的技巧。"NOR"\n");
                        break;
                case 1:
                        say(this_object()->name()+"道:"HIY"羅馬可不是一天造成的。"NOR"\n");
                        break;
                default:
                	break;
        }
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/5;     

        if( me->query("gender") == "男性" )
        {
                switch( lv )
                {
                        case 0: rank = "無家可歸的流浪漢"; break;
                        case 1: rank = "四處流浪的冒險者"; break;
                        case 2: rank = "浪跡天涯的冒險者"; break;
                        case 3: rank = "難得一見的冒險家"; break;
                        case 4: rank = "不可思議的超勇者"; break;
                        default: rank = HIC "夢幻般的大冒險王" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "楚楚可憐的小ㄚ頭"; break;
                        case 1: rank = "成熟嫵媚的小姑娘"; break;
                        case 2: rank = "熱力四射的女勇者"; break;
                        case 3: rank = "難得一見的女勇士"; break;
                        case 4: rank = "不可思議的女勇者"; break;
                        default: rank = HIC "夢幻般的女冒險王" NOR;
                }

        }
        return rank;
}

