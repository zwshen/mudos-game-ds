// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "¢â¢±¢¯¢¯¢¯«¬²×µ²ªÌ" NOR, ({ "terminater" }) );
	set("long",
		"·s«¬²×µ²ªÌ¯«±¡­Ð¶Æ¦a¯¸¦b§A­±«e¡M¥Lªº²´¯«´²µo¥X¤@ªÑ¥O¤H²¿®§\n"
		"ªº¥i©È±þ®ð, À£±o§A´X¥G³Ý¤£¹L®ð¨Ó¡M§Aªº¸£¸Ì¦ü¥G¦³¤@­ÓÁn­µ¦b\n"
		"¶D§A¡R¡u §Ö Â÷ ¶} ³o ¸Ì ¡T¡T¡v\n");

	set("age", 7777);
	set("level", 100);
	set("max_hp", 5000);
	set("max_mp", 5000);
	
	set("str", 100);
	set("int", 100);
	set("con", 100);
	set("dex", 100);

	set("combat_exp", 5000000);

	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

    set_temp("apply/attack", 2500);
    set_temp("apply/defense", 2500);
    set_temp("apply/armor", 2500);
    set_temp("apply/damage", 2500);
      set_temp("apply/shield", 2500);


	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
	LOGIN_D->set_reboot(3);
	message("system",
		HIY	"\n\n ¹Í¢w¢w¹Í¢w¢w¹Í¢w¢w¹Í¢w¢w¹Í¹Í¢w\n\n"
		HIW	"¶W¯Å¨t²Î¢w"HIG"·Rº¿"HIW"¢wµo¥XÄµ§i¡R\n\n"
		HIC	"\t\t\t¦Û °Ê ·´ ·À ¸Ë ¸m ·Ç ³Æ ²× ¤F ¡T\n\n"
		HIC	"\t\t\t¤T ¤À ÄÁ «á ±Ò °Ê ·´ ·À ¨t ²Î ¡T\n\n"
		HIR	"\t\t\t\t¢¨¢i¢i¢i¢©\n"
			"\t\t\t\t        ¢i\n"
			"\t\t\t\t        ¢i\n"
			"\t\t\t\t  ¢i¢i¢i¢«\n"
			"\t\t\t\t        ¢i\n"
			"\t\t\t\t        ¢i\n"
			"\t\t\t\t¢ª¢i¢i¢i¢«\n"NOR,
		users() );
	call_out("countdown", 60, 3);
}

private void countdown(int min)
{
	object *user;
	int i;
	min--;
	if( min == 2 )
	{
		LOGIN_D->set_reboot(2);
		message("system",
		HIR	"\n\n\t\t\t\t¢¨¢i¢i¢i¢©\n"
			"\t\t\t\t        ¢i\n"
			"\t\t\t\t        ¢i\n"
			"\t\t\t\t¢¨¢i¢i¢i¢«\n"
			"\t\t\t\t¢i\n"
			"\t\t\t\t¢i\n"
			"\t\t\t\t¢ª¢i¢i¢i¢«\n\n"
		HIW	"\t\t¢w¢w ·´ ·À ¨t ²Î ±N ©ó ¤G ¤À ÄÁ «á ±Ò °Ê  ¡T ¢w¢w\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else
	if( min == 1 )
	{
		LOGIN_D->set_reboot(1);
		message("system",
		HIR	"\n\n\t\t\t\t     ¢¨\n"
			"\t\t\t\t   ¢¨¢i\n"
			"\t\t\t\t     ¢i\n"
			"\t\t\t\t     ¢i\n"
			"\t\t\t\t     ¢i\n"
			"\t\t\t\t     ¢i\n"
			"\t\t\t\t   ¢¨¢i¢©\n\n"
		HIW 	"\t\t¢w¢w ·´ ·À ¨t ²Î ±N ©ó ¤@ ¤À ÄÁ «á ±Ò °Ê  ¡T ¢w¢w\n\n" NOR,
			users() );
		user=users();
		for(i=0;i<sizeof(user);i++)
		{
			user[i]->save();
			tell_object(user[i],"¦Û°ÊÀx¦s§¹²¦¡T\n");
		}
		call_out("countdown", 60, min);
	} else
	if(!min)
	{
		message("system",
		HIR	"\n\n\t\t\t\t¢¨¢i¢i¢i¢©\n"
			"\t\t\t\t¢i      ¢i\n"
			"\t\t\t\t¢i      ¢i\n"
			"\t\t\t\t¢i      ¢i\n"
			"\t\t\t\t¢i      ¢i\n"
			"\t\t\t\t¢i      ¢i\n"
			"\t\t\t\t¢ª¢i¢i¢i¢«\n\n"
		HIW "\t\t ·´ ·À ¨t ²Î ¶} ©l ¶i ¤J ±Ò °Ê µ{ §Ç £»£»£» \n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	} else
	{
		message("system",
		HIW "\n\n\t\t¢w¢w ·´ ·À ¨t ²Î ±N ©ó " + chinese_number(min) + " ¤À ÄÁ «á ±Ò °Ê  ¡T ¢w¢w\n\n" NOR,
		users() );
		call_out("countdown", 60, min);
	}
}

private void do_shutdown()
{
    foreach(object tmp in children("/obj/user"))
                if( file_name(tmp) != "/obj/user" )tmp->save();
	message("system",@DOWN
	
[1;37m                   ¢w ¦Û °Ê ·´ ·À ¸Ë ¸m ¤w ±Ò °Ê ¢w
[0;31m
	                          ______
	                       .-"      "-.
	                      /            \
	          _          |     ¢Ò¢á     |          _
	         ( \         |,  .-.  .-.  ,|         / )
	          > "=._     | )(__/  \__)( |     _.=" <
	         (_/"=._"=._ \/     /\     \/ _.="_.="\_)
	                "=._"(_     ^^     _)"_.="
	                    "=\__|IIIIII|__/="
	                   _.="| \IIIIII/ |"=._
	         _     _.="_.="\          /"=._"=._     _
	        ( \_.="_.="     `--------`     "=._"=._/ )
	         > _.="                            "=._ <
	        (_/                                    \_)


[1;31m §AÅ¥¨ìªþªñ¶Ç¨Ó¤@Án«e©Ò¥¼¦³ªº¥¨¤jÃz¬µÁnÅT ¡T©Ò¦³ªº¤@¤Á³£¦bÀþ¶¡³´¤Jµ´¹ïªº¶Â·t....[0m

DOWN
,users() );
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	LOGIN_D->set_reboot(0);
	if( !ob ) return;
	// °µ¬ö¿ý
	log_file("static/reboot","Reboot terminated by "+ob->query("id")+" at "+ctime(time())+"\n");

	message("system",
		HIW "\n\n\t¢w¢w ¦Û °Ê ·´ ·À µ{ §Ç ¤w ³Q " + ob->name(1) + " ¤¤ Â_ ¢w¢w\n\n"
		    "\n\n\t ........ ¦Û·´©R¥O¸Ñ°£§¹¦¨¡C\n\n" NOR,
		users() );
	destruct(this_object());
}
