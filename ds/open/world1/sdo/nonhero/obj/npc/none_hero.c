#include <ansi2.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name(HIW"無名英雄英靈"NOR,({"none hero","hero"}));
        set("long",@LONG
祂的週遭籠罩著一層白光，讓你幾乎不敢直視，而且也頗為傾服於祂
所散發出來的氣勢。無名英雄是當年無上國中的英雄之一。在他死後
仍然對國家念念不忘，所以死後意念匯聚，希望能找到繼承人，繼續
保家衛國。
LONG
	);

        set("level",43);
	set("no_fight",1);
        set("age",200+random(50));
        set("combat_exp", 200000);
	set("gender","男性");

	set_skill("fork",100);
	set_skill("block",50);
        set_skill("parry", 85);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        
        set_skill("combatwolf-fork",100);
	map_skill("fork","combatwolf-fork");

	set_temp("apply/armor",40);

	setup();

	set("talk_reply",HIW"你要接受試練嗎？\n"NOR);
        set("chat_chance", 10);
        set("chat_msg", ({
	HIW"無名英雄說道：不知道後世有沒有人有能力繼承我的遺志？\n"NOR,
	(: command("think") :),
	(: command("sigh") :),
	}));
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
	(:command,"exert combatwolf-fork skywolf":),
	(:command,"exert combatwolf-fork icewolf":),
	(:command,"wield pike":),
	}));
        carry_object(__DIR__"wp/hero_pike.c")->wield();
        carry_object(__DIR__"eq/hero_armor.c")->wear();
	carry_object(__DIR__"eq/hero_shield.c")->wear();
	carry_object(__DIR__"eq/hero_leggings.c")->wear();
}

void init()
{
	add_action("reply_say","say");
}

int reply_say(string str)
{

	if(this_object()->query_temp("fight") != 0) return 0;

	if (str=="我" || str=="要")
	{   
	object me;
	me=this_player();

	message_vision(
	HIW"\n英靈對著$N微笑道：好！好！有膽識的人！\n"
	HIW"英靈大喝一聲：留神來！\n\n",me);

	this_object()->kill_ob(this_player());
	delete("no_fight");
	set_temp("fight",1);
	return 1;
	}
}    

void die()
{
        object ob,me,obj;
	me=this_player();
	obj=load_object(SDO_PAST+"nonhero/obj/coffin");
	obj->delete("temp/opened");

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision", 
	HIC"\n\n    無名英雄英靈對"+ob->name(1)+"說道：\n\n"NOR
	HIC"            『太好了！太好了！我後繼有人了！』\n\n"NOR, 
	users());

	message_vision(
	HIW"\n你看到一道白光回到棺木之中。\n"NOR,me);

        ob->add("popularity", 3); //聲望
	tell_object(ob,HIC"[因為你的努力，你得到了 3 點聲望!!]\n"NOR);
        ::die();
        return;
}