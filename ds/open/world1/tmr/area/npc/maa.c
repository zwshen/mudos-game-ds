/* ¤K·¥ªù ªì¯Å®v¤÷
 *
 * -By Tmr 
 * -Update 2002/02/22 
   -Update 2004/06/22 - JS@DS
 *
 */
inherit NPC;
inherit SSERVER;

#include <ansi.h>
void do_da_fork();
string *actions2=({
"¬ï¶³®g¤é","¼çÀsÅD²W","±öªáÂIÃB","ªø­iÂ¶¤Ñ","¦^¨­®·¼v","¥É±aÂ¶¸y","»í¬PÁ|µ§"
});
void do_six_open();
string *actions=({
"òE¥´³»¨y","©ê¥´³»¨y","³æ»L","¯ã¥´","Â½¨­¤pÄñ","©ê»L"
});

void create()
{
        set_name("§õ®Ñ¤å", ({ "master lee shu wen", "master", "lee" }) );
        set("nickname", "¯«ºj§õ");
        set("gender", "¨k©Ê");
        set("class","fighter");
        set("age", 60);
        set("adv_class",1);
        set("class1","¤K·¥ªù");

        set("guild_gifts",({10,7,0,3}));
        set("long",
"§õ®Ñ¤å¬Ý¨Óµu¤p¡A«oµ¹¤H¬Û·íºë®«ªº·PÄ±¡A¤@ÁyµÂ¿p¡A¥O¤H±æ¤§¥Í¬È¡C\n"
"¥L§ó¬O²{¤µ¡u¤K·¥ªù¡vªº²Ä¤»¥N´xªù¡A¤£¶Èºë³q¤K·¥®±¡A¨ä¤jºj³Z§ó¬O¤w¹F\n"
"µn®p³y·¥ªº¹Ò¬É¡A¦b¦¿´ò¤W¬O¦ì·¥¦³¦Wªº¤@¥N©v®v¡C\n"
        );
        set("max_ap",2225);
        set("attitude", "peaceful");
        set("level",40);
        set("guild_skills",([
        "bagi_fist":({150,3,60}),
        "horse-steps":({130,4,100}),
        "dodge" : ({120,2,60}),
        "parry" : ({120,3,70}),
        "unarmed":({110,3,80}),
        "fork":({120,3,70}),
        "da-fork":({150,3,60}),
        ])  );
        set_skill("unarmed", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("fork",90);
        set_skill("bagi_fist",99);
        set_skill("da-fork",90);
        set_skill("horse-steps",99);

        set_temp("apply/armor",38);
        set("no_check_class",1);
                set("chat_chance",20);
        set("chat_msg",({
                        "§õ®Ñ¤å¤f¤¤»¡µÛ¡uòE¥´³»¨y¡vªººq³Z¡A¤@­±ºt½m°_¨Ó¡C\n",
                        "§õ®Ñ¤å¤f¤¤»¡µÛ¡u©ê¥´³»¨y¡vªººq³Z¡A¤@­±ºt½m°_¨Ó¡C\n",
                        "§õ®Ñ¤å¤f¤¤»¡µÛ¡u´£»L¡vªººq³Z¡A¤@­±ºt½m°_¨Ó¡C\n",
                        "§õ®Ñ¤å¤f¤¤»¡µÛ¡u³æ¶§¥´¡vªººq³Z¡A¤@­±ºt½m°_¨Ó¡C\n",
                        "§õ®Ñ¤å¤f¤¤»¡µÛ¡u¯ã¥´¡vªººq³Z¡A¤@­±ºt½m°_¨Ó¡C\n",
                        "§õ®Ñ¤å¤f¤¤»¡µÛ¡uÂ½¨­¤pÄñ¡vªººq³Z¡A¤@­±ºt½m°_¨Ó¡C\n",
                        "§õ®Ñ¤å®¶¾Ä°_ºë¯«¡AÄ~Äò½m²ß¡u¤»¤j¶}¡vªº¤»­Ó°ò¥»©Û¦¡¡C\n",
                        }) );


                /*
        set("chat_msg",({
          "§õ®Ñ¤å»´»´»¡¹D¡G¡u¥@»P§Ú¦Ó¬Û¹H¡A´_¾r¨¥¤¼²j¨D¡H¡v\n" ,
          "§õ®Ñ¤å»´»´»¡¹D¡G¡u¥@»P§Ú¦Ó¬Û¹H¡A´_¾r¨¥¤¼²j¨D¡H¡v\n" ,
          "§õ®Ñ¤å»´»´»¡¹D¡G¡u®®¿Ë±­¤§±¡¸Ü¡A¼Öµ^®Ñ¥H®ø¼~¡C¡v\n" ,
          "§õ®Ñ¤å»´»´»¡¹D¡G¡u¤w¨o¥G.......¡v\n" ,
                (:command("exert horse-steps twine-power"):),
          "§õ®Ñ¤å»´»´»¡¹D¡G¡u´J§Î¦t¤º´_´X®É¡A¬T¤£©e¤ß¥ô¥h¯d¡A­J¬°¹N¹N±ý¦ó¤§¡H¡v\n" ,
          "§õ®Ñ¤å»´»´»¡¹D¡G¡uÃh¨}¨°¥H©t©¹¡A©Î´Ó§ú¦Ó¯ÐÐT¡A¡v\n" ,
          (:command("think"):),
          "§õ®Ñ¤å»´»´»¡¹D¡G¡uµnªF¯o¥HµÎ¼S¡AÁ{²M¬y¦Ó½á¸Ö¡C¡v\n" ,
          "§õ®Ñ¤å»´»´»¡¹D¡G¡u²á­¼¤Æ¥HÂkºÉ¡A¼Ö¤Ò¤Ñ©R´_®OºÃ¡C¡v\n" ,
                (:command("sigh"):),
         }) );

                */

                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("exert bagi_fist"):), // ¤K·¥®± ¯S§ð
                (:command("exert bagi_fist"):), // ¤K·¥®± ¯S§ð
                        (:command("exert da-fork"):),   // ¤jºj³Z ¯S§ð 
                        (:do_six_open:),                                // ¤»¤j¶}¯S§ð 
                        (:do_da_fork:),                    //ÀÀ-¤jºj¯S§ð
         }) );
        
        create_family("¤K·¥ªù", 6, "´xªù¤H");
        set_temp("apply/armor",80);     // ÃB¥~ªº¨¾¿m¤O
        setup();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"wp/masterfork")->wield();
} 
void do_da_fork()
{ 
        object me=this_object(),target;
                string act=actions2[random(sizeof(actions2))];

                target = offensive_target(me);  // ¼Ä¤H
                if(!me) return;
                if(!target) return;
                if(me->is_busy() ) return;
                if(me->query_temp("do_six_open") ) return; 
                
                message_vision(HIW"\n$N³Ü¹D¡G¡yÅý§A¹Á¹Á¯uªºªº¤jºj³Z§a¡I¤jºj³Z¤§-¤@À»§Þ¡z\n"NOR,me,target);
                message_vision(HIW"¤@ªÑ²`¨Iªº"HIC"®ð«l"HIW"³ò¸ÉµÛ"HIR"$n"HIW"ªº¥|©P..\n"NOR,me,target); 
                message_vision(HIW"¤@¦¡"+HIG"¡u"+act+"¡v"+HIW"¡A±Æ¤s­Ë®ü¤§®ð¡IÅ§¦V$n¡I\n"NOR,me,target);
                                if(  random(100) < COMBAT_D->attack_factor(me,"unarmed")*10/15 
                  || random(100) > -COMBAT_D->dodge_factor(target,"dodge")  ) {
                                message_vision(HIR "$n°{¸ú¤£¤Î¡A¬½¬½³Q$NÀ»¤¤¯Ý¤f¡A³Ø°Õ¤@Án¡A³º¬O¦Ø°©¸H±¼ªºÁn­µ¡I¡I\n" NOR,me,target);
                                target->receive_damage("hp",300+random(99));
                                target->start_busy(3);

                } else {
                        switch(random(3))
                        {
                        case 0:
                                message_vision(HIW "$N¦b¤d³¨¤@¾v¤§»Ú¡A°{¶}¤F$n²r¯Pªº§ðÀ»....\n" NOR,target,me);
                                break;
                        case 1:
                                message_vision(HIW "$N»´¥©¥©¦a¸õ¤F¶}¥h¡A¸ú¶}¤F³o¤@¦¸ªº§ð¶Õ....\n" NOR,target,me);
                                break;
                        case 2:
                                message_vision(HIW "$N¡u«z¡v¤@Án¦y¥s¡A©êµÛÀYÂ½¨­ºu¤F¶}¥h¡A¸ú¶}¤F³o¦¸ªºÀI¨Ç­P©Rªº§ðÀ»...\n" NOR,target,me);
                                break;
                        }
                
                }
}
                
void do_six_open()
{
        object me=this_object(),target;
                string act=actions[random(sizeof(actions))];

                target = offensive_target(me);  // ¼Ä¤H
                if(!me) return;
                if(!target) return;
                if(me->is_busy() ) return;
                if(me->query_temp("do_six_open") ) return;

                message_vision(HIG "\n$N¨Ï¥X¡u¤»¤j¶}¡v±j¯P¤º«l¡A¤@ªÑ±j«l¦ÓÀê¼öªºÁ³ßí®ð«l¥|´²¦Ó¥X...\n" NOR,me,target);
                message_vision(HIG "$N¤@©Û"+ HIB "¡u"+ act + "¡v"+HIG"¡AÂ²¼ä¦Ó¨³³t¦a®µµÛÁ³ßí«l¬½¬½À»¦V$n¯Ý«e­n®`¡I¡I\n" NOR,me,target);
                
        // §ðÀ»©R¤¤
                if(  random(100) < COMBAT_D->attack_factor(me,"unarmed")*10/15 
                  || random(100) > -COMBAT_D->dodge_factor(target,"dodge")  ) {
                                message_vision(HIR "$n°{¸ú¤£¤Î¡A¬½¬½³Q$NÀ»¤¤¯Ý¤f¡A³Ø°Õ¤@Án¡A³º¬O¦Ø°©¸H±¼ªºÁn­µ¡I¡I\n" NOR,me,target);
                                target->receive_damage("hp",50);
                                target->start_busy(1);
                                target->apply_condition("six_open_force",5);

                } else {
                        switch(random(3))
                        {
                        case 0:
                                message_vision(HIW "$N¦b¤d³¨¤@¾v¤§»Ú¡A°{¶}¤F$n²r¯Pªº§ðÀ»....\n" NOR,target,me);
                                break;
                        case 1:
                                message_vision(HIW "$N»´¥©¥©¦a¸õ¤F¶}¥h¡A¸ú¶}¤F³o¤@¦¸ªº§ð¶Õ....\n" NOR,target,me);
                                break;
                        case 2:
                                message_vision(HIW "$N¡u«z¡v¤@Án¦y¥s¡A©êµÛÀYÂ½¨­ºu¤F¶}¥h¡A¸ú¶}¤F³o¦¸ªºÀI¨Ç­P©Rªº§ðÀ»...\n" NOR,target,me);
                                break;
                        }
                
                }
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_speak","speak");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
         return GUILDMASTER->do_skill_list(ob,me,arg);   
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();
        if(me->query("race") != "human" ) return 0;
        message_vision("$N·Q¥[¤J¡u"+ arg+ "¡v¡C\n",me); 
        if(arg != "¤K·¥ªù") return notify_fail("§õ®Ñ¤åºÃ´bªº¬ÝµÛ§A¡C\n");
        if(me->query("adv_class")) return notify_fail("§A¤w¥[¤Jªù¬£¤F¡C\n");
        if(me->query_temp("can_join_bagi"))
        {
                i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
                switch(i)
                {
                case 1:
                        me->set("adv_class",1);
                        me->set("class1","¤K·¥ªù");
                        me->create_family("¤K·¥ªù",7,"«L«È");
                        message_vision("$N¥[¤J¤F¤K·¥ªù¡C\n",me);
                        me->delete_temp("can_join_bagi");
                        return 1;
                case -1: return notify_fail("§A¤w¦³ªù¬£¤F¡C\n");
                case -2: return notify_fail("§A¤w¦³ªù¬£¤F¡C\n");
                case -8: return notify_fail("¨S¦³³oºØªù¬£¡C\n");
                }
                return 0;
        }
        if(me->query_temp("eight_speak") )
                command("say ³o¦ì"+ RANK_D->query_respect(me) +"¦p¤£ª¾¨º¥y¸Ü¡A´N¬O¦b¦¹¸÷¤F¤T¤Ñ¤T©]¡A§Ú¤]¬O¤£·|¦¬ªº¡C\n");
        else    
        {
                command("say ¤£´±·í¡A¦p§A¯à»¡¥X(speak)¥»ªù³Q¦¿´ò©Ò²±¶Çªº¤@¥y¸Ü¡A§Ú´N¦¬¤F§A§a");
                me->set_temp("eight_speak",1);                                          default: rank = HIC "¤K·¥ªù¤§¤@¥N¤k³Ç" NOR;
                }

        }
        return rank;
}


        
        return 1
int do_speak(string arg
        object me
        me=this_player()
        if(!me->query_temp("eight_speak") )return 0
        if(arg != "¼A±¾°Ñ¤K·¥¡A­^¶¯¼Û²ö¤Î"
        
                message_vision("$N¤jÁn»¡¥X¡G¡u"+ arg +"¡C¡v\n",me)
                command("shake")
                command("say ¤£¬O¤£¬O¡A¦A·Q·Q§a¡C")
        
        els
        
                message_vision("$N¤jÁn»¡¥X¡G¡u"+ arg +"¡C¡v\n",me)
                command("say ¦n¡A´N¬O³o¥y¸Ü¡A§A¥i¥H¥[¤J¡u¤K·¥ªù¡v¤F¡I(join ¤K·¥ªù)¡C")
                me->set_temp("can_join_bagi",1)
                me->delete_temp("eight_speak")
        }      
        return 1
int do_advance(string arg
        object ob, me
        ob = this_object()
        me = this_player()
            if(me->query("level") > 24 && me->query("class2")=="¤K·¥ªù" 
          return notify_fail("§A¤£¬O§õ®Ñ¤åªº§Ì¤l¡C\n")
        if(me->query("class1")=="¤K·¥ªù" 
                return GUILDMASTER->do_advance(ob,me,arg)
        else
                return notify_fail("§A¤£¬O¤K·¥ªùªº§Ì¤l¡C\n")
void die(
        object ob
        if( !ob = query_temp("last_damage_from") 
        ob = this_player(1)
        if( !ob )
        
                ::die()
                return
        
        message("world:world1:vision"
  HIG"\n¡iªZªL®ø®§¡j" +HIW"¤@¥N©v®v¡u¯«ºj¡v§õ®Ñ¤å¦º¦b"+ob->name(1)+"ªº¤â¤¤¤F¡C\n\n"+NO
        ,users())
        ob->add("popularity",1); //Án±
        ::die()
        //destruct(this_object())
        return
string guild_rank(object me
        string rank
        int lv
        lv = me->query("level")
        lv = lv/10;     // ±N rank ¤À¬°¤»­Ó¼h¦
        if( me->query("gender") == "¨k©Ê" 
        
                switch( lv 
                
                                // LV 1 ~ 
                        case 0: rank = "¤K·¥ªù¤§ªì¥X­TÄª"; break
                                // LV 10 ~ 1
                        case 1: rank = "¤K·¥ªù¤§²¤¦³¤p¦W"; break
                                // LV 20 ~ 2
                        case 2: rank = "¤K·¥ªù¤§¥M¸q¦¿´ò"; break
                                // LV 30 ~ 3
                        case 3: rank = "¤K·¥ªù¤§«L®ð»·¼½"; break
                                // LV 40 ~ 4
                        case 4: rank = "¤K·¥ªù¤§´­¦W¤Ñ¤U"; break
                                // LV 5
                        default: rank = HIC "¤K·¥ªù¤§¤@¥N©v®v" NOR
                
        
        els
        
                switch( lv 
                
                                // LV 1 ~ 
                        case 0: rank = "¤K·¥ªù¤§ªì¥X¶|©Ð"; break
                                // LV 10 ~ 1
                        case 1: rank = "¤K·¥ªù¤§²¤¦³­^¦W"; break
                                // LV 20 ~ 2
                        case 2: rank = "¤K·¥ªù¤§¥M¸q¥|®ü"; break
                                // LV 30 ~ 3
                        case 3: rank = "¤K·¥ªù¤§­^®ð»·¼½"; break
                                // LV 40 ~ 4
                        case 4: rank = "¤K·¥ªù¤§´­¦W¤Ñ¤U"; break
                                // LV 5
