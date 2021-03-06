#include <ansi.h>
inherit NPC;
void create()
{
	set_name("死刑犯", ({ "capital prisoner","prisoner" }) );
	set("long","他是個死刑犯，不知犯了何罪而被判死刑。\n");
	set("race","人類");
	set("gender","男性");

	set("level", 10);
	set("age",45);

	set_skill("parry", 20);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);

	set("talk_reply","唉∼我家有妻小，還有七十多歲的老母，如今被關在此，\n"
	    "       還被判了死罪，唉∼我看你是幫不了我的！",);

	set("inquiry",([
  "死罪" : "我以前殺人放火，無惡不作的大壞蛋，前些日子在做一\n"
	    "       件案子，不知誰通風報信，不幸被官兵逮個正著，罪證\n"
	    "       鑿，只好認了。但我已大徹大悟！從此不做壞事！可是\n"
	    "       為時已晚，唉∼∼",
  "案子" : "你是說前陣子我幹下那案子啊！唉∼那時在大街上看見\n"
	    "       一個小妞，長得還挺標緻的，所以就∼嘿∼嘿∼",
  "小妞" : "你是說那個小妞啊！唉∼那個小妞不堪羞辱，當天晚上\n"
	    "       就上吊自盡了！唉∼∼罪過！罪過！",
  "坑洞" : "咦！？這是個方便用的坑洞啊！？難不成你要去挖(dig)！？"
]));

	setup();
}

void init()
{ 
	 add_action("do_dig","dig");
}

int do_dig(string arg)
{
	int i;
     object me,ob,wine,wine2,wine3;

	me=this_player();
	ob=this_object();
	i = me->query_temp("SKYCITY/hole");

	if( arg != "坑洞" ) return 0;
	if( me->is_busy() ) return notify_fail("你的動作還沒有完成﹐不能做動作。\n");

	switch(i) {
	case 0: 
		message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break; 

	case 1: 
		message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break;

	case 2: 
		message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break;

	case 3: 
		message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
		command("say 咦！？你怎會如此聽話！？竟會連挖四次！！"); 
		command("say 嗯！我倒覺得這位"+RANK_D->query_respect(ob)+"膽識過人。");
		command("say 你再挖一次試試！！");
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break;

	case 4: 
		message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
		command("say 很好！很好！你真的很聽話。");
		command("say 這樣吧，反正我早晚也得死，我就把我從不離身的寶物給你。");
		command("slap "+me->query("id"));
		command("say 哼！！你當我這麼容易受騙嗎？這巴掌就是我不離身的寶物啦！！");
		me->start_busy(2);
		me->set_temp("SKYCITY/hole",i+1);
	break;

	case 5:
		if(ob->query_temp("SKYCITY/hole")==0)
		{
			wine=new(__DIR__"item/wine");
            wine2=new(__DIR__"item/wine");
            wine3=new(__DIR__"item/wine");
			message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
			command("tsk "+me->query("id"));
			command("say 原來你還挺有骨氣的，不管如何打罵、譏笑，還是阻止不了你挖大便的野心。");
			command("say 我看你也挖的很辛苦，來吧！我這瓶酒給你，雖然這不是什麼好酒，不過你還是收下吧。");
         message_vision("死刑犯給了$N一些燒刀子。\n",me);
        wine->move(me);
        wine2->move(me);
        wine3->move(me);
			me->set_temp("SKYCITY/hole", i+1);
			ob->set_temp("SKYCITY/hole", 1);
			me->start_busy(2);
		}
		else {
			message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
			command("say 你這人還真奇怪！這洞如此的髒，還不住的挖！怪人！");
			command("snort "+me->query("id"));
			me->start_busy(2);
		}
	break;

	case 6:
		message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
		command("say 不用挖了啦，我沒有什麼寶物給你啦！");
		me->start_busy(2);
	break;

	}
	return 1;
}
