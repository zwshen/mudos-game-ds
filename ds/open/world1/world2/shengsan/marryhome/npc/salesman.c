// ÂÅ¤Ñ«Ø³]¾P°â¸g²z
// by Shengsan@DS  2002/4/2 05:07PM
#include <ansi.h>
#include <marry.h>
inherit NPC;
object ppl2, ppl1;

int do_buyhouse2(string index);
int do_buildhouse();
string query_ladyname();
void destlady();

void create()
{
        set_name( (: query_ladyname :), ({ "selling manager","manager" }));
        set("long", @LONG
¦o¬O¤@¦ì¾Ö¦³°g¤H­·ªöªº¬üÄR¤k¤H¡A«NÄRªºµu¾v¥[¤W¸Ë§ê¤£«UªºªA¹¢¡A
¤@ºØÄá¤Hªº²´¯«¥¿¦b¹ï§A¤W¤U¥´¶qµÛ¡A¥t¥~¥L§ó¬OÂÅ¤Ñ«Ø³]¸Ì¤@¦ì¾Ö¦³±M·~
¾P°â¸gÅçªº¸g²z¤H¡C

	buyhouse		¶R©Ð¤l

LONG
        );
	set("level",30);
	set("title","ºaÅA¤§");
	set("gender", "¤k©Ê");
	set("race", "¤HÃþ");
	set("age", 32);
	set("exp",1000);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
					//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
					//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
	set("combat_exp",2000);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
	set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set("attitude", "peaceful");		//·Å©Mªº NPC¡C
	set("talk_reply","¬°±z¤Î±zªº¥t¤@¥b¿ïÁÊ¤@¶¡·Å·xªº®a(home)§a..¨þ¨þ..");
	set("no_kill",1);
	set("no_fight",1);
	set("chat_chance", 1 );  //°Ê§@¾÷²v
	set("chat_msg", ({       //°Ê§@¤º®e
		"¾P°â¸g²z¯º¯º¦a»¡: ²¢»e»eªº¤p­Ç¤f¤]À³¸Ó­n¦³¦Û¤vªº©Ð¤l(house)§a... §Ú½æªº©Ð¤l¥i¬O¸U¤¤¤§¿ï³á!\n",
		"¾P°â¸g²z«Ü¦³¿³­P¦aª`µøµÛ§A, ²´¯«¤¤¦ü¥G±a¦³¤@ÂI«N¥Ö¡C\n",
		"¾P°â¸g²z®³°_ªM¤l³Ü¤F¨Ç¤ô¡C\n",
		(:command("grin"):),
		(:command("think"):),
		}) );
//===========================°ÝÃD¦^µª==================================
	set("inquiry/name", "[1;36m §Ú¬OÂÅ¤Ñ«Ø³]ªº»¶©f¸g²z... ½Ð¦h«ü±Ð!![m");
	set("inquiry/buy", "[1;36m ±z­n¶R©Ð¤l¶Ü? \n¦pªG±z³ßÅw³o¶¡©Ð¤l´N§â¥¦µ¹¶R¤U¨Ó(buyhouse)§a!![m");
	set("inquiry/house", "[1;36m ¯à¦³ÄÝ©ó¦Û¤vªº©Ð¤l¬O¨C­Ó¤Hªº¹Ú·Q... \n¦pªG±z³ßÅw³o¶¡©Ð¤l´N§â¥¦µ¹¶R¤U¨Ó(buyhouse)§a!![m");
	set("inquiry/home", "[1;36m ¯à¦³ÄÝ©ó¦Û¤vªº©Ð¤l¬O¨C­Ó¤Hªº¹Ú·Q... \n¦pªG±z³ßÅw³o¶¡©Ð¤l´N§â¥¦µ¹¶R¤U¨Ó(buyhouse)§a!![m");
	set("inquiry/buyhouse", "[1;36m ³á? §A­n¶R©Ð¤l... ½Ðª½±µÁä¤J buyhouse[m");
	setup();
	add_money("dollar", 250);		//±aªº¿ú

}

void init()
{
	seteuid(getuid(environment()));
	if(!userp(this_player())) return;
	
//	if(MARRY_D->query_house_bought(environment(this_object())->query("houseid")))
//	{
//		destruct(this_object());
//		return;
//	}
	
	add_action("do_buyhouse","buyhouse");
	add_action("do_yes",({"y"}));
	add_action("do_yes",({"yes"}));
	add_action("do_no",({"no"}));
	add_action("do_buildhouse","bh");
}

string query_ladyname()
{
	object envobj;
	string ladyname;
	
	envobj = environment(this_object());
	ladyname = envobj->query("Ladyname");
	if(!ladyname)
		ladyname = "»¶©f";
	return ladyname;
}

int do_buyhouse()
{
	object target, temp, ob = this_object(), me = this_player();
	string	targetname;

	if(ob->query("buyinghouse")) return notify_fail("¦o¦ü¥G¥¿¦b¦£¡C\n");

	if( !targetname = me->query("marry_id") )
	{
		command("think");
		command("say µ¥§A§ä¨ì²×¨­¦ñ«Q«á¦A¨Ó½Í§a¡I");
		return 1;
	}
	if(!target = find_player(targetname))
	{
		command("hmm");
		command("say ¦n¹³¨S³o¦ìªB¤Í³á¡A±z½Ð¦^§a¡C");
		return 1;
	}
	if(userp(target) && environment(target) == environment(ob))
	{
		ppl1 = me;
		ppl2 = target; 
		set("buyinghouse",1);
		command("hmm");
		call_out("do_buyhouse1",3);
		return 1;
	}

	command("say ½Ð±zªº°t°¸¤]¨Ó³o¸Ì¬Ý¬Ý©Ð¤l§a¡C");
	command("snicker");
	return 1;
}

void do_buyhouse1()
{
	object ob = this_object();

	if(environment(ppl1) != environment(ob))
	{
		command("flop");
		command("say «È¤H¶]¤F¡AÃø¹D¬O§Ú¤£°÷§l¤Þ¤O¶Ü¡H¨º³o¼Î¶R½æ´N¦¹¥´¦íÂP¡C");
		delete("buyinghouse");
		delete("asking");
		return;
	}
	if(environment(ppl2) != environment(ob))
	{
		command("?");
		command("say «ç»ò±zªº·R¤H¤@Âà²´´N¤£¨£¤F¡H");
		delete("buyinghouse");
		delete("asking");
		return;
	}
	command("look "+ppl2->query("id"));
	command("say ¶â... «Ý§Ú¸ß°Ý¹ï¤èªº·N¨£¡C");
	tell_object(ppl2,HIC+ppl1->name(1)+"´£¥X¶R³o´É©Ð¤lªº´£Ä³¡A½Ð°Ý±z¦P·N¶Ü¡H [yes/no]\n"NOR);
	set("asking",1);
	return;
}

int do_yes()
{
	if(this_player() == ppl2 && query("asking"))
	{
		do_buyhouse2("y");
		return 1;
	}
	return 0;
}

int do_no()
{
	if(this_player() == ppl2 && query("asking"))
	{
		do_buyhouse2("n");
		return 1;
	}
	return 0;
}



int do_buyhouse2(string index)
{
	object ob = this_object();
	object obj1,obj2;

	delete("asking");
	if(index == "y")
	{
		message_vision(HIR"\n[$N±æµÛ$N·P°Ê¦a»¡: ¦n·P°Ê¡I§Ú·íµM¦P·NÂP¡I]\n\n"NOR,ppl2,ppl1);
		command("say ¶â¡ã¤Ó¦n¤F¡I");
		command("grin");
		if(environment(ppl1) != environment(ob))
		{
			command("flop");
			command("say ¶R¥D¶]¤F¡A¨º³o¼Î¶R½æ´N¦¹¥´¦íÂP¡C");
			delete("buyinghouse");
			return 1;
		}
		if(ppl1->query("bank/now") < HOUSE_VALUE )
		{
			message_vision("$NºNºN¦Û¤vªº¤f³U«á¡AÁy¤WÅS¥XÀª§¼ªºªí±¡¡C", ppl1);
			command("flop");
			command("ack");
			command("say ­ì¨Ó¬O½a¥ú³J?! ¥»¬ü¤k¯u¬O¬Ý¨«¤F²´¡A¨º³o¼Î¶R½æ´N¦¹¥´¦í¤F§a¡C");
		}
		else if(!objectp(obj1 = present("marry ring", ppl1)))
		{
			command("flop");
			command("say "+ppl1->name(1)+"¡A§Aªºµ²±B§Ù«ü©O¡H§Aªº±B«ÃÃö«Y­È¼w°Óºe³á¡A¨º³o¼Î¶R½æ´N¦¹¥´¦í¤F§a¡C");
		}
		else if(!objectp(obj2 = present("marry ring", ppl2)))
		{
			command("flop");
			command("say "+ppl2->name(1)+"¡A§Aªºµ²±B§Ù«ü©O¡H§Aªº±B«ÃÃö«Y­È¼w°Óºe³á¡A¨º³o¼Î¶R½æ´N¦¹¥´¦í¤F§a¡C");
		}
		else if(!do_buildhouse())
		{
			command("think");
			command("say ©_©ÇÂP... ÂÅ¤Ñ«Ø³]¹ï©ó³o¦¸ªº¶R½æ¦ü¥G¤£¥H¬°·N¡C(½Ð³qª¾½u¤W§Å®v)");
			command("say ¬JµM¦p¦¹... ¨º³o¼Î¶R½æ´N¦¹¥´¦í¤F¡C");
		}
		else
		{
			ppl1->add("bank/now",-HOUSE_VALUE);
			tell_object(ppl1,HIG"[¾P°â¸g²z¸ò±z¦¬¤F "+HOUSE_VALUE+" ªTª÷¹ô¡C] \n"NOR);
			message_vision(HIR"\n[$Nµ¹¤F¾P°â¸g²z "+HOUSE_VALUE+" ªTª÷¹ô¡I]\n\n"NOR,ppl1);
			ppl1->save();
			ppl2->save();
		}
	}
	else
	{
		message_vision(HIC"\n[$N°í¨Mªº·n¤F·nÀY]\n\n"NOR, ppl2);
		ob->command("say ¬Ý¨Ó±zªº·R¤H¨Ã¤£¦P·N­C¡A¨º´Nºâ¤F¡A¨º³o¼Î¶R½æ´N¦¹¥´¦íÂP¡C");

	}
	delete("buyinghouse");	
	return 1;
}

int do_buildhouse()
{
	object ob = this_object();
	int i;
	i = MARRY_STD->buildhouse(ob);
	return i;
}

void reset()
{
	delete("buyinghouse");
	delete("asking");
	command("say ±z¨Óªº¤£¥©¡A¤µ¤Ñ¤½¥ð¤é¡A·Q¶R©Ð¤l©ú¤Ñ½Ð¦­¡C");
}

void destlady()
{
	int i;
	
	i = MARRY_D->query_house_bought(environment(this_object())->query("houseid"));
	if(i)
		destruct(this_object());
	return;
}