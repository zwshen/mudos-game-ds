// °Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void call_help();
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "´H¤j´I", ({ "harn-tar-fu","harn","fu","boss"}));
        
        //tmr, long§A¦Û¤v§ï§ï§a. °tÂIeq..
        set("long", "¤@­Ó¨­¬ïµØÄRªA¹¢ªº·L­D¤¤¦~¤H, ¥L¤]¬O³o¶¡¿ú²øªº¥D¤H¡C\n\n"
        	    +"  ¬d¸ß±b¤á½Ð¥Î <balance> \n"
                +"  ­n¦s¿ú½Ð¥Î <deposit °ò¥»ª÷ÃB> \n"
        	    +"  ­n´£¿ú½Ð¥Î <withdraw °ò¥»ª÷ÃB> \n\n"
        );
        
        set("level",17);
        set("title","[1;32m­û¥~[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 45);

        set("combat_exp",1700);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
        
        set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",40);		// §Þ¯à(¦Û©w)
	set_skill("parry",40);		//
	set_skill("dodge",40);		//

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
   set("talk_reply","·Q¦s¿ú(deposit)¶Ü? ±`±`¦s´Ú¥i¥HÁ×§K¿ò¥¢³á!!");

  set("chat_chance", 3 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
(: command("stare") :),
}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
 HIR"­û¥~¤j¥s : ¡u±Ï©R£«¡ã¡T¦³¤H·m§T£«¡T¡v\n"NOR,
     }) );
//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ´H¤j´I.. ½Ð¦h«ü±Ð!![m
LONG );

        setup();

	add_money("gold", 1);		//±aªº¿ú(coin¥j¥N,dollar²{¥N,¥¼¨Ó¨S¦³)
	add_money("silver", 36);
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

void call_help()
{
	object guard,target;
	target = offensive_target(this_object());
	if(!target) return ;

	guard=present("guard", environment(this_object()));
	if(!guard)
	{
		message_vision("­û¥~¤j¥s: §Ö¨Ó¤H­þ~~ ±Ï©R£«!! \n",target);
		return ;
	}
	if(guard->is_fighting(target))
	{
		message_vision("¦u½Ã¬Ý°_¨Ó«Ü¥Í®ðªº¼Ë¤l!!\n",target);
		return ;
	}
	else
	{
	 guard->kill_ob(target);
	 message_vision("¦u½Ã¤j³Ü¤@Án, ¶}©l¹ï$Nµo°Ê§ðÀ»!!\n",target);
	 return ;
	}
}

