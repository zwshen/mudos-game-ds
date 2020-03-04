#include <ansi.h>
inherit NPC;
varargs int receive_damage(string type, int damage, object who);
void special();
void create()
{
        set_name(HIW"¤Ñ¤s³·"NOR,({"master tain","tain","master"}));
        set("long" ,
"±¡«°¦Àªº²Ä¤G¥N«°¥D¡A¨ä¤§¾_«°µ´§Þ[·À¯«Ã@ªk]¤w¦AªZªL¤¤±Æ¦W«e¤Q¡Aµ·²@\n"
"¤£¿éµ¹Å½¬Ü¡A¦³µÛÂù­«ªº©Ê­Ó¡AµL½×¬OªZ¥\\©Î¬O´¼¼z¡A§¡¤w¹F¦Ü¤Æ¹Ò¡A¬O¤@\n"
"¦W²`¤£¥i´úªº¤kÃ@¤â¡C\n");
        set("nickname", HIR"·À±¡µ´¹D"NOR );
        set("attitude", "friendly"); 
        set("age", 25);
        set("gender","¤k©Ê");
        set("combat_exp", 100000);
        set("level", 50);
        set("title","¡m±¡«°¦À¡n²Ä¤G¥N«°¥D" );
        set("max_ap",3000);
        set("MKS",150);
        set("class1","±¡«°¦À");
        create_family("±¡«°¦À",15,"²Ä¤G¥N«°¥D");
        set_temp("apply/armor",30);
        set_skill("seven-love",100);
        set_skill("masen_whip",80);
        set_skill("force",100);
        set_skill("run_cloud",75);
        map_skill("whip","masen_whip");
        map_skill("dodge","run_cloud");
        set("guild_gifts",({ 4,6,4,6 }));
        set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "whip" : ({ 110,3,80 }),
  "parry":({ 130,2,60 }),
 "masen_whip" : ({ 150,3,80 }),
  "force" : ({ 135,3,85 }),
  "unarmed" : ({ 100,3,80 }),
"run_cloud" : ({ 140,3,80 }),
]));
        set("no_check_class",1);
        set("adv_class",1);
        set("chat_chance",8);
        set("chat_msg", ({
  "¤Ñ¤s³·±æµÛµ¡¥~¡A¦ü¥G¦b«ä©ÀµÛ¬Y¤H¡C\n",
  (:command("sigh"):),
	(:command("wield whip") :),
  
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command("exert seven-love love"):),
  (:command("exert masen_whip"):),
                          (:special:), 
  (:command("exert masen_whip"):),
        (:command("wield whip") :),
        (:command("wield whip") :),
  (:command("exert masen_whip"):),
}));
        set("inquiry/¬Y¤H","§Ú¥¿¦b«ä©À§Ú®v¯ª(§®ªk¥P´L)¡A§A¦³¬Ý¨ì¦o¶Ü¡H\n");
        set("inquiry/§®ªk¥P´L","¦o¦Ñ¤H®a¦n¹³¤@ª½¸ú¦b³o«°¤¤ªº¬Y¤@³B§a¡H\n");
        setup();
  carry_object("/open/world1/kkeenn/love/npc/obj/blood_whip")->wield();
  carry_object("/open/world1/kkeenn/love/npc/obj/ten_pearl")->wear();
  add_money("coin",3000);
        }

void init()
{
        object me=this_player();
        object ob=this_object();
   object npc,room;
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
        room=load_object(environment(this_object())->query("exits/up"));
 if( room && objectp(npc = present("sen",room)))
    {
tell_object(me,HIG"¼Ó¤W¼b³Ü¤@Án¡A¤@¹D«æ³tµL¤ñªº¶Â¼v¦V§A½Ä¨Ó¡I\n"NOR);     
tell_object(me,npc->name()+HIG"»¡¹D¡G¤s³·¡A²öÅå¡I¬°®v¨Ó§U§A¤@Áu¤§¤O¡I\n"NOR);     
tell_object(me,npc->name()+HIG"¤jÁn³Ü¹D¡G´c¸é¡I¦º¨Ó§a¡I\n"NOR);     
   npc->set("auto",1);
	npc->move(environment(this_object()));
    }
                        return;
        }
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
//        add_action("do_guard","go");
        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
        object ob=this_object() , me=this_player();
        string gender;

        if( !arg && !me->query_temp("join_l") )
                return notify_fail("§A·Q­n¥[¤J¤°»òªù¬£§r¡H(join ±¡«°¦À)\n");
        if( me->query("gender") == "¨k©Ê" )
                return notify_fail("¤Ñ¤s³·»¡: «Ü¬O©êºp¡A¥»«°¬O¤£±µ¨ü¨k©Êªº¡C\n");

        if( me->query_temp("join_l") && !arg ) arg = "±¡«°¦À";
        if( strsrch(arg, "±¡«°¦À") == -1 || strsrch(arg, "¤£") > -1)
                return notify_fail("§A·Q­n¥[¤J¤°»òªù¬£§r¡H(join ±¡«°¦À)ù)\n");
        if( me->query("gender") == "¤k©Ê" ) gender="©h®Q";
        else gender = "¥S§Ì";
    message_vision("$N·Q¥[¤J¡u"+ HIM"" + arg + ""NOR+ "¡v¡C\n",me); 

        if( me->query("class1") )
                return notify_fail("§A¤w¬O"+me->query("class1")+"ªº§Ì¤l¤F¡C\n");
        if( me->query("family/family_name")=="±¡«°¦À" )
                return notify_fail("§A¤w¬O¤Ñ¤s³·ªº®{§Ì¤F¡C\n");
        if( !me->query_temp("ljoin") && !me->query_temp("join_l") ) {
                command("say ³o¦ì"+gender+"¥i§_À°§Ú§¹¦¨¤@¥ó¨Æ¡H");
                tell_object(me, ob->name()+HIG"¦b§A¦ÕÃä»¡¹D¡G"+gender+"¥i§_À°§ÚÀ°§Ú¯d·N¤@¤U±Í®v¯ª³Ìªñªºª¬ªp¡H\n"NOR);
                tell_object(me, ob->name()+HIG"¦b§A¦ÕÃä»¡¹D¡G¥u­n¸ò¦o¦Ñ¤H®a»¡¤@Án[±z³Ìªñ¦n¶Ü?]¡A³o¼Ë§Ú´Nº¡¨¬¤F¡C\n"NOR);
                me->set_temp("ljoin",1);
                return 1;
        }
        else if( me->query_temp("ljoin") && !me->query_temp("join_l") ) {
                command("say "+gender+"¨£¨ì§Ú®v¯ª¤F¶Ü¡H");
                return 1;
        }
        else {
                command("bow "+me->query("id"));
                me->set("guild_rank","±¡«°¦À¤§¤Jªù¾Ç®{");
message("world:world1:vision",
HIM"\n\t¡m±¡«°®ø®§¡n¡G"HIR"·À±¡µ´¹D "HIW"¤Ñ¤s³·"HIM" ¦¬¤F"+me->name(1)+HIM"¬°±¡«°¦À¤J«Ç§Ì¤l¡C\n"NOR,users() );

                message_vision("$N¦¨¬°±¡«°¦Àªº§Ì¤l¡C\n",me);
                me->set("class1","±¡«°¦À");
                me->create_family("±¡«°¦À",3,"§Ì¤l");
                me->set("adv_class",1);
                return 1;
        }
//      return 1;
}

int do_advance(string arg)
{
//        if (this_player()->query("family/family_name")=="±¡«°¦À") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        if (this_player()->query("class1")=="±¡«°¦À" && !this_player()->query("class2") ) return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        else return notify_fail(this_object()->query("name")+"¨Ã¨S¦³²z·|§A¡C\n");
}

int accept_object(object me, object ob)
{
        object tob, herb,a;
        tob = this_object();
        if( ob->query("id")!="ron letter" ) return 0;
        if( me->query("gender")!="¤k©Ê" ) 
               return notify_fail("¤Ñ¤s³·»¡: «Ü¬O©êºp¡A¥»«°¬O¤£±µ¨ü¨k©Êªº¡C\n");
        else {
                command("thank "+me->query("id"));
command("say "+RANK_D->query_respect(me)+"¬J§U¤s³·®ø°£ºÃ´b¡A´NÅý¤s³·¦¬"+RANK_D->query_respect(me)+"¬°®{§a¡I\n");
                message_vision("$N±N$n¦b´x¤ß¤¤¤@´|¡A$n´N¤Æ¬°¤ù¤ùªº¯È½¹½º­¸¥h¡A·Ù¬O¦n¬Ý¡C\n", this_object(), ob);
                tell_object(me,HIR"½Ð¦b¥´¤@¦¸("HIY"Join ±¡«°¦À"HIR")¥H«K¤s³·¦¬§A¬°®{¡C\n"NOR);
                me->delete_temp("ljoin");
                me->set_temp("join_l",1);
                destruct(ob);
        }
        return 1;
}

string guild_rank(object me)
{
        string rank;
        int lv,steps,whip;
        steps = me->query_skill("dodge");
        whip = me->query_skill("whip");
        lv = me->query("level");
        lv = lv/6; 
        if ( whip > 35 && whip > steps - lv*4 )
        {
                if ( whip > 99 ) rank = HIM"±¡«°¦À¤§Ã@ªk¥P¤l"NOR;
                else if ( whip > 70 ) rank = HIW"±¡«°¦ÀªºÃ@ªk±Ð½m"NOR;
                else if ( whip > 35 ) rank = HIC"±¡«°¦ÀªºÃ@ªk¾Ç®{"NOR;
        }
        else if ( steps > 40 )
        {
                if ( steps > 99 ) rank = HIC"¤é¦æ¸U¨½°l¶³¬y¨B"NOR;
                else if ( steps > 75 ) rank = HIW"±¡«°¦À¤§¤d¨½³ø°¨"NOR;
                else if ( steps > 40 ) rank = HIM"±¡«°¦Àªº¨Bªk¾Ç®{"NOR;
        }
        else
        {       switch( lv )
                {
                        case 0: rank = HIR"±¡«°¦À¤§¬õ¦ç§Ì¤l"NOR; break;
                        case 1: rank = HIB"±¡«°¦À¤§ÂÅ¦ç§Ì¤l"NOR; break;
                        case 2: rank = HIW"±¡«°¦À¤§¥Õ¦ç§Ì¤l"NOR; break;
                        case 3: rank = HIY"±¡«°¦À¤§¶À¦ç§Ì¤l"NOR; break;
                        case 4: rank = MAG"±¡«°¦À¤§µµ¦ç§Ì¤l"NOR; break;
                        default: rank = HIC"±¡«°¦À¤U¥ô¤K¥P¤l"NOR;
                }
        }
        return rank;
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

	if( this_object()->query_temp("flee") )
	{
		this_object()->set("hp", this_object()->query("max_hp") );
		call_out( (:destruct(this_object()) :), 1);
			return;
	}

        if( !ob ) 
        {
                ::die();
                return;
        }
        if( ob->query_temp("kill_love") ) 
        {
        if( ob->query("class1") == "±¡«°¦À" ) 
        {
message("world:world1:vision",
HIY"\n\n¡m¤j©ñ²§±m¡n"HIM":\n\n\t±¡«°¦À§Ì¤l "+ob->name()+HIM"³q¹L±¡«°¦Àªº¤j¦ÒÅç¡I\n\n"+NOR
        ,users());
     ob->add("quest/win",1);
if ( ob->query("quest/win") < 10 )
      {  
          ob->set("title","±¡«°¦À¤§¥X®v§Ì¤l"); 
      } 
if ( ob->query("quest/win") > 10 )
      {  
          ob->set("title","±¡«°¦À²Ä¥|¥N¥P¤l");
      }
if ( ob->query("quest/win") > 20 )
      {  
          ob->set("title","±¡«°¦À²Ä¥|¥N±þ¤â");
      }
 if ( ob->query("quest/win") > 50 )
      {  
          ob->set("title","±¡«°¦À²Ä¥|¥NÅ@ªk");
      }
 if ( ob->query("quest/win") > 100 )
      {  
          ob->set("title","¡m±¡«°¦À¡n°Æ«°¥D");
      }
 if ( ob->query("quest/win") > 500 )
      {  
          ob->set("title","±¡«°¦À²Ä¥|¥N«°¥D");
      }  
if ( ob->query("quest/win") > 1000 )
      {  
          ob->set("title","±¡«°¦À¤§¤è¥~ªø¦Ñ");
      } 
        ob->delete_temp("kill_love");
	ob->add("popularity", 7); 
        ob->set("guild_rank",HIW"¡i"HIR"¦å¤â±¡"HIC"¦B¤ß«°"HIW"¡j"NOR);
        message_vision(HIW"$N¦]¬°³q¹L±¡«°¦Àªº¦ÒÅç¡A©Ò¥HÀò±o7ÂIÁn±æ\n"NOR,ob);
                ::die();
                return;
        }
message("world:world1:vision",
HIR"\n  ¡mªZªL¬õ©«¡n"HIM":\n\n\t±¡«°¦À¤@¬£³Q"+ob->name()+HIM"À»±Ñ¡A¦b¦¿´ò¤W³Q°£¦W¤F¡I\n\n"+NOR
        ,users());
	ob->add("popularity", 7); 
        ob->delete_temp("kill_love");
        ob->set("guild_rank",HIW" ¡i"HIC"®{¤â"HIR"·À"HIM"±¡«°"HIW"¡j "NOR);
        message_vision(HIW"$N¦]¬°·À¤F±¡«°¦À¤@¬£¡A©Ò¥HÀò±o7ÂIÁn±æ\n"NOR,ob);
                ::die();
                return;
        }

        message("world:world1:vision",
HIR"\n  ¡m±¡«°ºG¼@¡n:\n\n\t"HIM"±¡«°¦À²Ä¤G¥N«°¥D "HIW"¤Ñ¤s³·"HIM"ºG¾D"+ob->name(1)+"ªºÅ]¤ö¡I\n\n"+NOR
        ,users());
        ob->add("popularity", 3); 
        ::die();
        return;
}
int do_guard(string arg)
{
        if( this_player()->query("class2") == "±¡«°¦À") return 0;
        if( (arg!= "up") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "±N§AÄd¤F¤U¨Ó¡C\n");
      command("sorry");
           say(HIW"¤Ñ¤s³·"NOR"»¡¹D¡G"HIG"¹ï¤£°_¡A¤W­±¬O¥»¬£ªº­«¦a¡C\n"NOR);
        return 1;
}
varargs int receive_damage(string type, int damage, object who)
{
        int val;
       object targets;
        if( damage < 0 ) error("F_DAMAGE: ¶Ë®`­È¬°­t­È¡C\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: ¶Ë®`ºØÃþ¿ù»~( ¥u¯à¬O hp, mp, ap¨ä¤¤¤§¤@ )¡C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(150)<30)
                {
                        damage/=2;
                        message_vision(HIM "\n$N±N¤â¤¤Ã@¤lÂà¥X¤E¤E¤K¤Q¤@­Ó°é¤l¡A¤Æ¥h¤F±j¤jªº§ð¶Õ¡C\n" NOR,this_object());
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
 if(query("hp")<query("max_hp")/8 && !is_busy() && !this_object()->query_temp("flee") && random(100) > 80 ) 
           {
	object *go;
//        if( !go = query_temp("last_damage_from") )
//        go = this_player(1);
	go = this_object()->query_enemy();
                this_object()->remove_all_killer();
           command("hehe");
           this_object()->set_temp("flee", 1);
           command("bye");
  message("world:world1:vision",HIM "\n¤Ñ¤s³·²M¯º¤@Án¡A¦^¨­­¸¤W«ÎÃ²»¡¹D¡G\n\n\t\t\t¦¹¦¸Áö±Ñ¡A¤U¦¸©w¬O¨ú§A­Ìª¯©R®É¡A°ª¤s¬y¤ô...¦A·|°Õ~~«¢~~«¢~~¡C\n" NOR,users());
        if(go) 
	{
		foreach(object each in go)
	{
		if( !query_temp("added") )
		{
                each->add("popularity" ,1);
		each->delete_temp("kill_love");
		this_object()->set_temp("added", 1);
		}
	}
	}
     this_object()->move(__DIR__"../room30");  
	this_object()->set("hp", this_object()->query("max_hp") );
                call_out( (:destruct($1):),1,this_object() );
           }

                return damage;
}

void special()
{
        object me=this_object();
        object* target; 
        int dam = 400 + random(me->query_skill("unarmed"));   
        if(me->is_busy() ) return;
        target=query_enemy();
      message_vision(HIW"\n$N±N¤â¤¤ªºÃ@¤l¥æ¦Ü¥ª¤â¡A¹B°_¦Û³ÐµÛ¯«¯µµ´©Û\n\t\t¡i"HIR"µ´±¡·À¹D"HIW"¡j¡I¡I\n¤@ªÑ¤£¥¢±j¤j¤S­Ý¦³µL¤ñ´d¶Ëªº¯u®ðªï­±¦V$n®u±²¦Ó¥h¡A$n¦b±¹¤â¤£¤Îªº±¡ªp¤§¤U\n¨ºªÑ¯u®ðª½±µ©R¤¤$nªº¯ÝµÄ¡A$n¬ðµMÅÜªº³·¥Õ¡A¦ü¥G¬O¨ü¨ì¤Q¤ÀÄY­«ªº¤º¶Ë¡I",me,target);
        target->receive_damage("hp",dam,me);
        message_vision("³y¦¨$N" +dam+ "ÂIªº¶Ë®`¡C\n",target);
    return;
}
