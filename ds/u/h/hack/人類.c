// ¡¹ ¤@¯ë¤HÃþNPC 

#include <ansi.h>
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "®È«È", ({ "passenger","®È«È","passenger",}));
        set("long", "¤@­Óº¡Áy¾î¦×ªº®È«È¡M¥¿¦b³Q¦w¥þÄµ½Ã½L°ÝµÛ¡C\n"
        );
        set("level",20);
        set("title","[1;33m¥~¦a¤H[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 42);
        set("exp",1000);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
        				
        set("str",31);			//³]©wÄÝ©Ê(¥i§K)
        set("dex",21);			//¤]¥i¥H¥u³]©w level
        set("con",33);			//¨ä¥L¨S³]©wªºÄÝ©Ê¨t²Î´N·|¦Û°Ê²£¥Í,
        set("int",18);			//§Y¨Ï¬O¬Û¦Pªºlevel¤]·|¦³¤£¦PÄÝ©Ê.
        
        set("combat_exp",2000);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
//        set("env/wimpy", 20);		//°k¶]wimpy (20%)
        set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",40);		// §Þ¯à(¦Û©w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================ºA«×Ãþ§O=================================
//   set("attitude", "friendly");   //¤Íµ½ªº NPC¡C
   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
//   set("attitude", "heroism");    //­^¶¯¥D¸qªº NPC¡C
//   set("attitude", "aggressive"); //¥D°Ê§ðÀ»,¥Í©Ê¦n°«ªºªº NPC¡C
//   set("attitude", "killer");     //¶Ý±þ¦¨©Êªº NPC¡C


//=============================¦Û°Ê°Ê§@=================================
  set("chat_chance", 0 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
"®È«È¥Î¤Oªº½ð¤FÀð¾À¤@¸}!! ¦ü¥G«D±`¥Í®ð..\n",
(:command("say «z¾a!! ³o¬O¤°»òªA°ÈºA«×¹À!!!"):),
(:command("say ¨ì©³­n§Ú»¡´X¦¸°Ú~~ ³o§â¶}¤s¤M¬O§Ú­è­è¾ß¨ìªº.."):),
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m§Ú¥s°µ¤û¹L...§A°Ý³o­Ó·F¤°»ò?? µL²á!![m
LONG );

//set("talk_reply","§A¤ÖºÞ¶¢¨Æ....");
//=========================¾Ô°«°T®§===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"®È«È¯}¤f¤j½| : ¡u¥i´cªº³Ã¥ë¡ã¡T§Ú¥´¦º§A¡T¡v\n"NOR,
     }) );

        setup();

//==========================¸Ë³Æ¹D¨ã=============================
      add_money("coin", 200);		//±aªº¿ú
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk ®É·|°õ¦æ¦¹¨ç¦¡.
{
 command("smile "+me->query("id") );
 return 1;
}

void init()
{
	::init();
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m¦w¥þÄµ½Ã°¨¤W¯¸¥X¨Ó¹ï$N[1;37m»¡: ½Ð¤£­n°Ê¤â, ¥æµ¹§Ú­Ì³B²z´N¦n¤F¡C[m\n",this_player());
 return 1;
 }
return 0;
}

//======================°Ê§@¤ÏÀ³======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")´dºGªº²Y²D§o³Û: ±Ï©Rªü!! ±Ï©Rªü!!!\n"
        	+"®È«È(passenger)·Q¿Ñ±þ§Ú!! ®È«È(passenger)¬O±þ¤H¥û¤â!![m\n");
                command("say ¥L@#$ªº, ¦Ñ¤l¥¿¦b®ðÀY¤W©~µM´±½ð§Ú!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")´dºGªº²Y²D§o³Û: ±Ï©Rªü!! ±Ï©Rªü!!!\n"
        	+"®È«È(passenger)·Q¿Ñ±þ§Ú!! ®È«È(passenger)¬O±þ¤H¥û¤â!![m\n");
                command("say ¥L@#$ªº, ¦Ñ¤l¥¿¦b®ðÀY¤W©~µM´±°½¥´§Ú!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say ºu»·¤@ÂI!!§O·Ð§Ú!!");
                break;
        }
}

//======================±µ¨ü¤ÏÀ³======================================
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("¥L¤£·Q¦¬§AªºªF¦è¡C\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "®È«È»¡¹D¡R¦hÁÂ³o¦ì" + RANK_D->query_respect(who)
                + "¡M¯«©ú¤@©w·|«O¦ö§Aªº¡C\n");

        return 1; //¦³retrun 1 ¤~·|¦¬¤UªF¦è.
}

void reset()
{
        // delete("memory");
}

// ¡¹¡¹ ¦³¯S§ð¤§NPC(1) §Þ¯à¦¡¯S§ð
// ¡¹¡¹¡¹¡¹ Â¾·~¤u·|¾É®v
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("¬yµL§Î" , ({ "invisible liu","liu" }) );
        create_family( HIC "£i¯«ªZ±Ð£i" NOR ,2,"±Ð¥D");
        set("level",50);
        set("race","¤HÃþ");
        set("age",65);
         set("adv_class",1);
         set("class1","¯«ªZ±Ð");
        set("gender","¨k©Ê");
        set("int",100);
        // ³]©wÄÝ©Ê¤À°tªí, ¨C¤@¶µªº­È¦b­t9¦Ü¥¿10¤§¶¡
        // ¦Ó¥B¥|¶µªºÁ`©M­n­è¦nµ¥©ó 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
               "sword" : ({160,2,60}),
               "godsword" : ({140,2,70}),
               "meditate" : ({160,2,20}),
               "mirage-steps" : ({150,2,50}),
        ])  );
     set("guild_spells",([
                "god-fire" : ({170,2,60}),
                "god-benison" : ({170,2,50}),
        ]) );
        set_spell("god-fire",80);
        set_spell("god-benison",70);
        set_skill("force", 100);
        set_skill("mirage-steps",100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set("long",@long
¥L¬O£i¯«ªZ±Ð£iªº±Ð¥D¡A´£¨Ñ°ò¥»ªº§Þ¥©°V½m¡C§A¥i¥H
¨Ï¥Îlist¨Ó¬Ý¬Ý¦³¤°»ò§Þ¥©¥i¥H´£¨Ñ¾Ç²ß(train)¡C¤]¥i
¥H¥Îadvance <level©ÎÄÝ©Ê> ¨Ó¤É¯Å, ¤É¯Å«e«ØÄ³¥ý¨Ï¥Î
level «ü¥O¨Ó¬d¾\©Ò»Ý­nªº¸gÅç­È¡C
long
);
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("cast god-fire"):),
                  (:command("exert mirage-steps"):),
                  (:command("cast god-benison"):),
        }) );
        setup();
             carry_object("/open/world1/acme/area/npc/wp/godsword.c")->wield();
}

int accept_object(object who,object ob)
{
        object plate;
        object me;
      me = this_player();

        if(ob->name()!="¯«ªZ¥OµP")
                return 0;
        else {
                command("say «x¡I¡I³o¤£¬O®v¤÷ªº¥OµP¶Ü¡I¡I");
                command("say ­ì¨Ó®v¤÷¦w¦n¡A¬Ý¨Ó§Ú¬O¦h¾á¤ß¤F¡C");
                command("smile");
                command("say ³o¦ì" +  RANK_D->query_respect(ob) + "¦hÁÂÀ°¦£¡C\n");
if(me->query("class1")  ) 
{
  notify_fail("§A¤w¬O"+me->query("class1")+"ªº§Ì¤l¤F¡A¦Ñ¤Ò´N¦¹ÁÂ¹L¤F¡C\n");
}
else {
            command("say §A­Yµê¤ß¤W¶i¡A¦Ñ¤Ò´N¦¬§A¬°®{§a¡I\n");
            command("say ¤J§Ú±Ð·í¦æ«L¥M¸q¡A°£±jÀÙ®z¡I\n");
            who->set("adv_class",1);
            who->set("class1","¯«ªZ±Ð");
            who->create_family("¯«ªZ±Ð",3,"±Ð®{");
           who->set("guild_rank",HIC"¯«ªZ±Ð¡ó"HIG"¶}¤s¯ª®v"NOR);
return 1;
}
       }
  return 1;     
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_force","force");
}
int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);    //¼È®É
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
//      GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//        return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")=="¯«ªZ±Ð") return notify_fail("§A¤w¬O¯«ªZ±Ð§Ì¤l¤F¡C\n");
         if(arg!="¯«ªZ±Ð") return notify_fail("§A­n«ô¤J¨º¤@­Óªù¬£?\n");
     say("¬yµL§Î¥¿¦Ûµo·T¡A¨Ã¨S¦³µo²{§A­n¥[¤J¡C\n");
     say("¬yµL§Î³ä³ä¦Û»yªº¹D¡G®v¤÷¥L¦Ñ¤H®a¤£ª¾¦w¦n¡A¤w¤Q¦~¤KÀ¹¥¼³q®ø®§¡C\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="¯«ªZ±Ð") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("§A¤£¬O¯«ªZ±Ð®{¡C\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="acme")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("«ü¥O®æ¦¡¡Rforce <¤Hª«> to <«ü¥O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("³o¸Ì¨S¦³ " + dest + "¡C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"¥¿¦£µÛ¡A¨S¦³ªÅÅ¥§AªºÅX¨Ï¡C\n");
        command(cmd);
        return 1;
}

// ¡¹¡¹¡¹ ¦³¯S§ð¤§NPC(2) ¯S®í¯à¤O¦¡

#include <ansi.h>
inherit NPC;
void make_mark();

void create()
{
	set_name("»ÈÅG",({"yin-bian","bian"}) );
	set("long","¥L¬O¶ø¤Z­}´µ¸Ì¦³¦Wªº­×¦æªÌ¡AÅ¥»¡¥L¾Ö¦³¶W¯à¤O¡C\n");
	set("age",30);
	set("level",40);
	set("race","¤HÃþ");
	set("guild_gifts",({3,4,8,5}));
	set("evil",-10);
	set("exp_point",4);	// ³]©w±j«×, exp¤Îcombat_exp·|°Ñ¦Ò¨ì³o­Ó­È
				// 0 <= exp_point <= 9
				// ¤º©w­È¬° 0 , ½Ð¨Ì¾Ú±j«×¨Ó³]¦X²zªº­È...
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say ³o¬O®y¬üÄRªº«°¥«¡A½Ð¤£­n°µ¥X¹Hªkªº¨Æ±¡³á¡I"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say ¬°¤FºûÅ@¶ø¤Z­}´µªº¦w¥þ¡A§Ú¨­¬°¨µ©x¡A¤@©w­n±N§@¶ÃªÌ´N¦a¥¿ªk¡I¡I"):),
		(: make_mark :),
//		(:command("cast mindkill"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
//	set_spell("mindkill",70);
	set_skill("staff",70);

	set("talk_reply","³á¡A³o¬O®y¬üÄRªº«°¥«¡C½Ð°O±o¤£­n¶Ã¥á©U§£³á¡C");
	setup();

	carry_object(__DIR__"eq/aihun_robe")->wear();

	add_money("dollar",200);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 2 + random(3) )
	{
		command("say §A³o­Ó§@¶ÃªÌ¡A©~µM¬°«D§@¤ï¡A¤µ¤Ñ³Q§Ú¹J¨ìºâ§A­Ë·°¡C");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}

}


void make_mark()
{
	object *enemy, ob;
	command("think");
	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say ­ó!µLªkµL¤Ñªº"+ob->query("name")+", §Úµo»}­n±N§A³v¥X¶ø¤Z­}´µ¡C");
	ob->add_temp("quest/aovandis",1);	// ±N´Û­t¥«¥Áªº¤H°µ¤W¼Ð°O
	this_object()->set("helpready/"+ob->query("id"),1);	// »P id µ²¤³

}

int special_attack(object me,object victim,int hitrole)
{
	int damage,c;

	if(!victim) return;
	if(me->query("mp")<20) return;
	me->receive_damage("mp",20);
	command("say "+victim->query("name")+"¡AÅý§A¬Ý¬Ý§Ú¶W¯à¤Oªº§Q®`¡C");


	tell_room(environment(me),"\n"+me->query("name")+"¬ðµM¨­¤l©¹«á°h¤F¤@¨B\n");
	tell_room(environment(me),"\n§A¬Ý¨ì¥LªºÂù¤â¦ÛµMªº««¤U¡AÂù¥ØÅÜ±o²§±`ªº¦³¯«¡C\n");

	if( victim->query_int() < random(150) )
	{
	    victim->add_busy(2);
	    message_vision(HIR"\n$N¬ðµM¹ï©P¾DªºÀô¹Ò¥Rº¡µÛ®£Äß¡A$Nªº¦æ°Ê¦n¹³³Q­­¨î¦í¤F¡C\n",victim);
	    damage = random(300)+query_int()*5;
	    damage = damage/2+random(damage/2);
	    c=victim->quer_shield();
	    damage = damage-c/2-random(c/2);
	    if(damage<0) damage=0;
	    damage = COMBAT_D->Merits_damage(me,victim,damage,"sou");
	    victim->receive_damage("hp", damage, me );
	    if(damage>0)
	    	message_vision(HIR"\n$N¬ðµM³Q²ö¦Wªº¤O¶q©Ò¥´¤¤¡A¤f¦RÂA¦å¡A¾ã­Ó¤H³Q¥´¦bÀð¾À¤W°Ê¼u¤£±o¡C\n"NOR,victim);
	    else
		message_vision(HIW"\n¥Ñ©ó$NªºÆF¤O³Ó¹L "+me->query("name")+" ¤@Äw¡A¬¡¥Í¥Í¦a±µ¤U¤F³oªÑ²ö¦W¤§¤O¡C\n"NOR,victim);

	    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
	    if(victim->query_temp("apply/show_damage") || victim->query_temp("show_damage") )
	        tell_object(victim,HIR"("+damage+")"NOR+" ("+victim->query("hp")+"/"+victim->query("max_hp")+")");
	    message_vision("\n",victim);
	    if(wizardp(victim) && victim->query("env/debug"))
	        tell_object(victim,"  ³y¦¨"+damage+"ÂI¶Ë®`!!\n"); 
	    COMBAT_D->report_status(victim);	

	}
	else message_vision("\n²ö¦W¤§¤Oª½ª½§ð¦V$N¡Aµ²ªG³Q$N¾÷ÆFªº¤Æ¸Ñ¤F¡C\n",victim);

 	me->start_busy(1);

}


// ¡¹¡¹¡¹¡¹ ½ÆÂø°Ê§@¤§NPC




// ¡¹¡¹¡¹¡¹¡¹ ªþ¥[¥\¯à¤§NPC (¨Ã°Ñ¨£¨ä¥L½d¨Ò)

#include <ansi.h>
#define DRAGON_M "/open/always/dragon_mark"
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "À°·|¨ÏªÌ", ({ "club messager","messager"}));
        set("long", "¤@­Ó¶Â¦ç¤H¡C\n§A¦pªG¿ò¥¢¤FÀ°·|«Hª«, ¥i¥H¥´(checkclub)¦V¥L¥Ó½Ð¤@­Ó·sªº«Hª«¡C\n"
        );
        set("level",1);
        set("title","[1;33m¸q¤u[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 1);
        set("exp",10);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
        				
        set("str",1);			//³]©wÄÝ©Ê(¥i§K)
        set("dex",1);			//¤]¥i¥H¥u³]©w level
        set("con",1);			//¨ä¥L¨S³]©wªºÄÝ©Ê¨t²Î´N·|¦Û°Ê²£¥Í,
        set("int",1);			//§Y¨Ï¬O¬Û¦Pªºlevel¤]·|¦³¤£¦PÄÝ©Ê.
        
        set("combat_exp",1);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
//        set("env/wimpy", 20);		//°k¶]wimpy (20%)
        set("evil",-20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",40);		// §Þ¯à(¦Û©w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================ºA«×Ãþ§O=================================
//   set("attitude", "friendly");   //¤Íµ½ªº NPC¡C
   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
//   set("attitude", "heroism");    //­^¶¯¥D¸qªº NPC¡C
//   set("attitude", "aggressive"); //¥D°Ê§ðÀ»,¥Í©Ê¦n°«ªºªº NPC¡C
//   set("attitude", "killer");     //¶Ý±þ¦¨©Êªº NPC¡C


//=============================¦Û°Ê°Ê§@=================================
  set("chat_chance", 0 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
§A°Ý³o­Ó·F¤°»ò?? µL²á!!
LONG );


//=========================¾Ô°«°T®§===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"®È«È¯}¤f¤j½| : ¡u¥i´cªº³Ã¥ë¡ã¡T§Ú¥´¦º§A¡T¡v\n"NOR,
     }) );

        setup();

//==========================¸Ë³Æ¹D¨ã=============================
//      add_money("coin", 200);		//±aªº¿ú
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk ®É·|°õ¦æ¦¹¨ç¦¡.
{
 command("say §A¦pªG±¼¤FÀ°·|«Hª«´N¨Ó§ä§Ú¥Ó½Ð(checkclub)§a!");
 return 1;
}

void init()
{
	::init();
add_action("do_checkclub","checkclub");
}

int do_checkclub(string arg)
{
	object me,ob,mark;
	string clubname;
	me=this_player();
	if(mark=present("club_mark",me)) return notify_fail("§A¤w¸g¦³À°·|«Hª«¤F¡C\n");
	
	if(!clubname=me->query("club/name")) return notify_fail("§A¨Ã¨S¦³°Ñ¥[À°·|ªº¬ö¿ý¡C\n");
	switch(clubname)
	{
		case "¨gÀsÀ°":
				ob=new(DRAGON_M);
				ob->move(me);
				message_vision("$N®³¤F¤@"+ob->query("unit")+ob->name()+"µ¹$n¡C\n",this_object(),me);
				me->save();
				return 1;
		default:
			return notify_fail("¨ÏªÌÁÙ¨S¦³®³¨ì³o­ÓÀ°¬£«Hª«¡C\n");
	}

}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("¥L¤£·Q¦¬§AªºªF¦è¡C\n");
        else if( val > 1000 )
        {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/10000) );
        }
        say( "¨ÏªÌ»¡¹D¡R¦hÁÂ³o¦ì" + RANK_D->query_respect(who)
                + "¡M¯«©ú¤@©w·|«O¦ö§Aªº¡C\n");

        return 1;
}
