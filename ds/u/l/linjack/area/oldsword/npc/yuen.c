#include <ansi.h>
inherit NPC;
void create()
{
	set_name("雲天翔",({"Yuen tan shang","yuen","shang","master"}));
	set("long" ,"你眼前這人目光內殮、炯炯有神, 太陽穴微微鼓起,\n"
                    "明顯是個內家高手, 原來此人就是名盛江湖的向雲堂\n"
                    "之主----「雲天翔」！他的過去如謎一般, 只知道曾\n"
                    "被"HIR"血劍修羅"NOR"『左宗平』授業兩年。如果你現在\n"
                    "還無師可承, 向雲堂是不錯的選擇, 向他問問入門的事吧.\n");
	set("nickname", "如雲幻霧");
	set("attitude", "peaceful"); 
	set("age", 43);
	set("gender","男性");
	set("level",40);
	set("title",HIC"向雲堂"NOR"創堂堂主");
	set("class1","向雲堂");
	create_family("向雲堂",1,"創堂堂主");

	set_skill("unarmed",75);
	set_skill("blade",85);
	set_skill("dodge",90);
	set_skill("force",90);
	set_skill("parry",75);
	set_skill("cloudblade",90);
	set_skill("cloudsteps",100);
	set_skill("cloudforce",90);
	set_skill("cloudfist",80);
	set_skill("cloudmove",50);
	set("guild_skills",([
  "cloudblade" : ({ 110,3,30 }),
  "parry" : ({ 200,2,30 }),
  "unarmed":({ 150,2,6 }),
  "cloudsteps" : ({ 175,2,30 }),
  "cloudfist" : ({ 200,3,30 }),
  "cloudforce" : ({ 200,2,20 }),
  "dodge" : ({ 200,2,20 }),
  "blade" : ({ 200,2,20 }),
  "force" : ({ 250,2,20 }),
]));

	set("adv_class",1);
	set("chat_chance",8);
	set("chat_msg", ({
  "雲天翔抬頭看了看屋頂。\n",
  "雲天翔頭轉了一轉, 似乎很累的樣子。\n",
  (:command("exert cloudsteps"):),
  (:command("exert cloudblade"):),
  (:command("exert cloudfist"):),
}));
        set("chat_chance_combat",100);
	set("chat_msg_combat",({
  (:command,"exert cloudblade":),
	  (:command,"exert cloudfist":),
  (:command,"exert cloudfist sky-force":),
}));

	set("inquiry/wife","別再提她了.....。\n");
        set("inquiry/夫人","別再提她了.....。\n");
        set("inquiry/cloudmove","問這做什麼？閣下怎麼會知道『縱雲五行功\』這部功\夫呢？\n");
        set("inquiry/左宗平","他是我的授業恩師, 可是最近我沒有他的消息.\n");
        set("inquiry/血劍修羅","他就是左宗平前輩啊..!\n");
	set("inquiry/冉紅塵","他是我的師兄, 現在山巔的古劍亭上, 但目前本堂不開放外人進入後山.\n");
        set("inquiry/後山","這個我就不太清楚了...\n");
	set("inquiry/向雲堂","哈哈, 若沒有左宗平恩師當年的幫助, 怎麼有今天的向雲堂呢?\n");
        set("inquiry/入門","你想入我門下? 我得考慮考慮..\n");
	setup();
	carry_object(__DIR__"eq/c_blade")->wield();
	carry_object(__DIR__"eq/c_armor")->wear();
	carry_object(__DIR__"eq/c_boots")->wear();
	carry_object(__DIR__"eq/c_cloth")->wear();
	carry_object(__DIR__"eq/c_cloak")->wear();
}

void init()
{
	::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        if(arg=="cloudfist" && !this_player()->query("learn_cloudfist") ) 
	{
		command("say 為何我要傳授你這門博大精深的武學?");
		return 0;
	}
	else if(arg=="cloudforce" && (this_player()->query("level") < 12 || !this_player()->query("learn_cloudforce")) )
	{
		command("say 你還不適合學這部內功心法.");
		return 0;
	}
        else if(arg=="cloudsteps" && this_player()->query_skill("dodge") < 12 )
	{
		command("say 你的腳底功\n夫還太差.");
		return 0;
	}
	else return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
	object ob,me;
	ob=this_object();
	me=this_player();
	message_vision("$N想加入「"+arg+"」。\n",me);	
	if( me->query("class1") )
		return notify_fail("你已經是"+me->query("class1")+"的弟子了。\n");
        if( me->query("family/family_name")=="向雲堂" )
		return notify_fail("你已經是向雲堂的弟子了。\n");
	if( !me->query_temp("cloud/solvequest") && !me->query_temp("cloud/questmark") ) {
		command("say 真想入我門下? 這嘛.....");
		if( me->query("level") > 2 ) {
			command("say 閣下看來已經身有武藝，吾不便再教導。");
			return notify_fail("雲天翔拒絕收你做他的弟子。");
		}
		else {
		me->set_temp("cloud/listen",1);
		call_out("questtalk",1,me); }
		return 1;
	}
	else if( me->query_temp("cloud/questmark") && !me->query_temp("cloud/solvequest") ) {
		command("say 你可有何消息？");
		return 1;
	}
	else {
		command("nod "+me->query("id"));
		message_vision("$N成為向雲堂的一份子。\n",me);
		me->set("class1","向雲堂");
		me->create_family("向雲堂",2,"弟子");
		me->set("adv_class",1);
		return 1;
	}
//	return 1;
}

int do_advance(string arg)
{
	if (this_player()->query("family/family_name")=="向雲堂") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
	else return notify_fail("你不是向雲堂的弟子。\n");
}
int accept_object(object me, object ob)
{
	object tob,letter,a;
	tob = this_object();
	if( ob->query("id")!="blood letter" ) return 0;
	else {
		command("emote 看了看這封信。");
		command("say 啊!!原來如此，這位"+RANK_D->query_respect(me)+"真是助吾一大忙，那吾便收"+RANK_D->query_respect(me)+"為徒吧。\n");
		tell_object(me,YEL"如果你要拜入向雲堂, 就再請求一次吧 ["HIY"join"NOR"] 。\n");
		me->delete_temp("cloud/questmark");
		me->set_temp("cloud/solvequest",1);
	}
	return 1;
}
void questtalk()
{
	int a;
	object me,obj;
	me=this_player();
	obj=this_object();
	a=obj->query_temp("cloud/listen");
	switch(a)
	{
		case 1:
		  command("say 好吧，但吾有一事相求，附耳來。");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 2:
		  command("whisper "+obj->query("id")+" 此事絕不可給第三人知情，否則吾絕不放過你。");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 3:
		  command("whisper "+obj->query("id")+" 吾妻逝世近一年，十三日後便是吾妻忌日，");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 4:
		  command("whisper "+obj->query("id")+" 但進日來吾常於堂內外附近見到一女子，");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 5:
		  command("whisper "+obj->query("id")+" 相貌極像吾妻，但吾礙於身份難以向她開口詢問...");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 6:
		  command("whisper "+obj->query("id")+" 若你能助吾向她問出個所以然來，");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 7:
		  command("whisper "+obj->query("id")+" 吾感激之餘，即收你為我門下。");
		  obj->set_temp("cloud/listen",a+1);
		  call_out("questtalk",2,me);
		  break;
		case 8:
		  command("nod");
		  command("say 快去吧。");
		  obj->set_temp("cloud/questmark",1);
		  obj->delete_temp("cloud/listen");
		  break;
	}
}
