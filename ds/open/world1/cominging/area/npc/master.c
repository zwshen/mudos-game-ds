#include <ansi.h>
inherit NPC;
void create()
{
	set_name(WHT"楊雙亟"NOR,({"master yang","yang","master"}));
        set("long" ,"他，就是疾風門近來武功\突飛猛進的人，在近日以來常有許\多\n"
		    "武林上的高手找他挑戰，但都是敗傷而去，頗有青出於藍於軒\n"
		    "轅烈的樣子。\n");
	set("nickname", "幻鎖內防" );
	set("attitude", "friendly"); 
	set("age", 35);
	set("gender","男性");
	set("combat_exp", 79000+random(4500));
	set("level", 41);
	set("title","《疾風門》光明右使" );
	set("max_ap",3000);
	set("class1","疾風門");
	set("flurrydodge",1);
	create_family("疾風門",10,"光明右使");
	set_temp("apply/armor",22);
	set_skill("fogseven",85);
	set_temp("sorgitimes",10);
	set_skill("unarmed", 80);
	set_skill("sword",90);
	set_skill("moon_force",50);
	set_skill("dodge", 80);
	set_skill("force", 70);
	set_skill("parry", 100);
	set_skill("sorgi_sword",80);
	map_skill("sword","sorgi_sword");
	map_skill("dodge","fogseven");
//          set("guild_gifts",({ 4,6,4,6 }))
          set("guild_gifts",({ 5,7,0,8 }));
	set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "parry" : ({ 110,3,80 }),
  "unarmed":({ 130,2,60 }),
  "sorgi_sword" : ({ 150,3,80 }),
  "moon_force" : ({ 175,4,85 }),
  "force" : ({ 135,3,85 }),
  "sword" : ({ 100,3,80 }),
  "fogseven" : ({ 140,3,80 }),
]));
	set("no_check_class",1);
	set("adv_class",1);
	set("chat_chance",8);
	set_temp("class_wind/power",200);
	set("chat_msg", ({
  "楊雙亟不停的在房子裡走來走去，似乎有些煩腦。\n",
  (:command("sigh"):),
  (:command("exert moon_force recover"):),
}));
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
  (:command,"exert sorgi_sword":),
  (:command,"exert sorgi_sword":),
  (:command("exert moon_force moon-arc"):),
}));

	set("inquiry/小狅","他就是我兒子，有什麼事嗎？\n");
	setup();
	carry_object(__DIR__"wp/shangsword")->wield();
	carry_object(__DIR__"eq/sandal")->wear();
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
	
	if( arg=="moon_force" )
	{
		if( this_player()->query_skill( "moon_force", 1 ) == 0 )
		return notify_fail("你並沒有殘月心法基礎，因此無法修練。\n");
	}
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
	object ob=this_object() , me=this_player();
	string gender;

	if( !arg && !me->query_temp("join_f") )
		return notify_fail("你想要加入什麼門派呀？(這裡可以 join 疾風門)\n");
	if( me->query_temp("join_f") && !arg ) arg = "疾風門";
	if( strsrch(arg, "疾風門") == -1 || strsrch(arg, "不") > -1)
		return notify_fail("你想要加入什麼門派呀？(這裡可以 join 疾風門)\n");
	if( me->query("gender") == "女姓" ) gender="女俠";
	else gender = "仁兄";
    message_vision("$N想加入「"+ HIC"" + arg + ""NOR+ "」。\n",me); 

	if( me->query("class1") )
		return notify_fail("你已是"+me->query("class1")+"的弟子了。\n");
        if( me->query("family/family_name")=="疾風門" )
		return notify_fail("你已是疾風門的門眾了。\n");
	if( !me->query_temp("fjoin") && !me->query_temp("join_f") ) {
		command("say 這位"+gender+"可否幫我完成一件事？");
		tell_object(me, ob->name()+HIG"在你耳邊說道："+gender+"可否幫我到在南邊森林中尋找一種名叫紫蘇玉蘭花的藥草？\n"NOR);
		me->set_temp("fjoin",1);
		return 1;
	}
	else if( me->query_temp("fjoin") && !me->query_temp("join_f") ) {
		command("say "+gender+"找到我所需的物品了嗎？");
		return 1;
	}
	else {
		command("pat "+me->query("id"));
		message_vision("$N成為疾風門的門徒。\n",me);
		me->set("class1","疾風門");
		me->create_family("疾風門",4,"弟子");
		me->set("adv_class",1);
		return 1;
	}
//	return 1;
}

int do_advance(string arg)
{
	if (this_player()->query("family/family_name")=="疾風門") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
	else return notify_fail("你不是疾風門的弟子。\n");
}

int accept_object(object me, object ob)
{
        object tob;
	tob = this_object();

	if( ob->query("id")!="gei-su flower" ) return 0;
	else {
		command("nod "+me->query("id"));
		command("say "+RANK_D->query_respect(me)+"既幫楊某如此大忙，就讓楊某收"+RANK_D->query_respect(me)+"為徒吧！\n");
		message_vision("$N將$n揉成了個球狀, 然後把$n給吞了下去。\n", this_object(), ob);
		tell_object(me,HIR"如果你要加入疾風門請再請求一次("HIY"Join"HIR")。\n"NOR);
		me->delete_temp("fjoin");
		me->set_temp("join_f",1);
		me->receive_heal("hp", 100);
		me->receive_heal("ap", 100);
		destruct(ob);
	}
	return 1;
}

string guild_rank(object me)
{
        string rank;
	int lv,force,steps,sword;
	force = me->query_skill("force",2);
	steps = me->query_skill("dodge",2);
	sword = me->query_skill("sword",2);
        lv = me->query("level");
        lv = lv/6; 
	if(force > 30 && force > sword -(lv*4) )
	{
		if ( force > 99 ) rank = HIC"內功\頂尖的疾風人"NOR;
		else if ( force > 65 ) rank = CYN"疾風門的內家高手"NOR;
		else if ( force > 30 ) rank = CYN"疾風門的內家新人"NOR; 
	}
	else if ( sword > 35 && sword > steps - lv*4 )
	{
		if ( sword > 99 ) rank = HIC"劍術無雙的疾風人"NOR;
		else if ( sword > 70 ) rank = CYN"疾風門的劍法高手"NOR;
		else if ( sword > 35 ) rank = CYN"疾風門的新興劍客"NOR;
	}
	else if ( steps > 40 )
	{
		if ( steps > 99 ) rank = HIC"步法頂絕的疾風人"NOR;
		else if ( steps > 75 ) rank = CYN"疾風門的輕功\高手"NOR;
		else if ( steps > 40 ) rank = CYN"初習縱躍的疾風人"NOR;
	}
	else
	{	switch( lv )
        	{
 	                case 0: rank = CYN"疾風門新一代學徒"NOR; break;
        	        case 1: rank = CYN"疾風門的初階弟子"NOR; break;
			case 2: rank = CYN"疾風門的中階弟子"NOR; break;
			case 3: rank = CYN"疾風門的得意門生"NOR; break;
			case 4: rank = HIC"嶄露頭角的疾風人"NOR; break;
			default: rank = CYN"疾風門第四代弟子"NOR;
        	}
	}
        return rank;
}
void die()
{
	object ob;
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	if( !ob ) 
	{
		::die();
		return;
	}
	message("world:world1:vision",
CYN"\n  武林傳出了一則消息:\n\n\t一「光明右使」楊雙亟敗給了"+ob->name(1)+"。\n\n"+NOR
	,users());
        ob->add("popularity", 1); 
	::die();
	//destruct(this_object());
	return;
}
