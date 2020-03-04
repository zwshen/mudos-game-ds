#include <ansi.h>

inherit NPC;
inherit SELLMAN;

string *list = ({
	"/open/always/game_gift/mask.c",
	"/open/always/game_gift/necklace.c",
	"/open/always/game_gift/skirt.c",
        "/open/world1/alickyuen/zong/bag.c",
});

void create()
{
	set_name(HIY"賣粽嫂子"NOR, ({"zong seller", "seller"}));
        set("gender", "男性" );
        set("age", 22);
        set("long","一個年上幾大的賣粽子嫂子，他正趁著端午節賣粽子賺錢。\n你可用plist、zlist跟zbuy這三個指令。\n");
	set("level",1);
        set("attitude", "friendly");
        set("nickname", HIW"人人有份, 有機會贏得"HIY"香包"NOR HIW"一個喔 ~"NOR);
        set("rank_info/respect", "小二哥");
	set("sell_list",([
                __DIR__"bean" : 30,
                __DIR__"meat" : 30,
        ]) );
	set("chat_chance",10);
	set("chat_msg", ({
                (:command,"say 買粽子嗎？找我吧∼zlist 和 zbuy∼":),
                (:command,"wink":),
                (:command,"say 快來買粽啦 ! 有咸也有甜的 ~ 還可以抽獎喔! ":),
	}));
        set("no_kill", 1);
        set("no_fight", 1);
        setup();
}
void init()
{       
//        object ob;

        ::init();
/*
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
*/
        add_action("do_list","zlist");
        add_action("do_buy","zbuy");
	add_action("list_price", "plist");
}

void greeting()
{
	command("say 快來買粽啦！有咸也有甜的∼才賣５０００元一個．還可以抽獎喔！！！");
	return;
}

int list_price()
{
	string msg;

        msg = HIC"2008 年度端午節大抽獎之獎品如下：\n"NOR+
		HIW"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"NOR+
                HIG"\t大獎：隨機SAVE EQ一件。\n"NOR+
		HIW"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"NOR;

	this_player()->start_more(msg);

	return 1;
}

int accept_object(object me,object ob)
{
	object price;
	int lucky;

        lucky = random(5000);

        if( ob->query("id") !="zong ticket" )
		return notify_fail("賣粽嫂子說:我不要你這爛東東。\n");

	if( this_object()->is_busy() ) 
                return notify_fail(this_object()->query("name")+"說道:老娘好累啦,等等啦.\n");

	this_object()->add_temp("waiting", 1);
	if( this_object()->query_temp("waiting") >= 10 )
	{
                this_object()->start_busy(3);
		this_object()->delete_temp("waiting", 1);
	}

	call_out( (:destruct($1):), 1, ob);

	switch(lucky)
	{
		case 50:
                        price = new(list[random(sizeof(list))]);
			price->move(me);
                        command("shout 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了大獎，得到SAVE EQ一件！");
			                                log_file( "static/gamea",sprintf("[%s] %s(%s) get %s[%s]\n",ctime(time()),me->name(1),getuid(me),price->name(1),base_name(price))); 
			return 1;
		break;
/*
                case 20..22:
			me->add("exp", 1000000);
			command("tchat 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了二獎，得到1000000 exp！");
			return 1;
		break;
                case 30..35:
			me->add("popularity", 10);
			command("tchat 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了三獎，獲得10點聲望！");
			return 1;
		break;
		case 60..70:
			new(__DIR__"meat")->move(me);
			command("say 恭喜，你有一隻粽。");
			return 1;
		break;
		case 71..80:
			new(__DIR__"bean")->move(me);
			command("say 恭喜，你有一隻粽。");
			return 1;
		break;
*/
		default:
			command("say 真可惜，你什麼東西也沒抽中。");
			return 1;
		break;
	}
	return 1;
}
