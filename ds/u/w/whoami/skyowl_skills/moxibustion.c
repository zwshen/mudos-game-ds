#include <ansi2.h>
inherit SKILL;
inherit SSERVER;

int HelpMoxibustion()
{

    write(@HELP
      ª¥¥Þ°w¨b¨Ï¥Î¤èªk:       exert moxibustion <¥\¯à> on <¬Y¤H>

          «D¾Ô°«¥\¯à¡G
          ¡mÀø®ð³Z¡nrekee       ®ø¯Ó¤º«lÂI¼Æ(AP)¨Ó¦^ÂÐ¥Í©RÂI¼Æ(HP)
          ¡mÀøºë³Z¡nregin       ®ø¯ÓÅ]ªkÂI¼Æ(MP)¨Ó¦^ÂÐ¤º«lÂI¼Æ(AP)
    ¡mÀø¯«³Z¡nresen       ®ø¯Ó¤º«lÂI¼Æ(AP)¨Ó¦^ÂÐÅ]ªkÂI¼Æ(MP)
    ¡mµ½¥@³Z¡nadvkee      ®ø¯Ó¤º«lÂI¼Æ(AP)¨Ó«ùÄò©Ê¦^ÂÐ¥Í©RÂI¼Æ(HP)
    ¡m¶
}
¤Ñ³Z¡nsky         ®ø¯ÓÅ]ªkÂI¼Æ(MP)¨Ó¦^ÂÐ¥þ®æª±®aªº¤º«lÂI¼Æ(AP),¥Í©RÂI¼Æ(HP)
¡mÂ¡¥Á³Z¡nheal        ®ø¯ÓÅ]ªkÂI¼Æ(MP)¨ÓªvÂ¡¨ü¶Ë³B
¡m³±¤ß³Z¡naddint      ®ø¯Ó¤j¶q¤º«lÂI¼Æ(AP)¡AÅ]ªkÂI¼Æ(MP)¨Ï´¼¼z(INT)´£¤É
¡m¤TµJ³Z¡naddcon      ®ø¯Ó¤j¶q¤º«lÂI¼Æ(AP)¡AÅ]ªkÂI¼Æ(MP)¨ÏÅé½è(CON)´£¤É
¡m¶hÄÆ³Z¡nadddex      ®ø¯Ó¤j¶q¤º«lÂI¼Æ(AP)¡AÅ]ªkÂI¼Æ(MP)¨Ï±Ó±¶(DEX)´£¤É
¡m¤Ó¶§³Z¡naddstr      ®ø¯Ó¤j¶q¤º«lÂI¼Æ(AP)¡AÅ]ªkÂI¼Æ(MP)¨Ï¤O¶q(STR)´£¤É
¡m°­³±¥@ºë³Z¡nghost   ®ø¯Ó¤º«lÂI¼Æ(AP)¡AÅ]ªkÂI¼Æ(MP)¡A¥Í©RÂI¼Æ(HP)¨Ïª«²z§ðÀ»¤O©Mª«²z¨¾¿m¤O´£¤É
¾Ô°«¥\¯à¡G
¡m¯«´d°­ª_³Z¡nattack  ®ø¯Ó¤j¶q¤º«lÂI¼Æ(AP)¡AÅ]ªkÂI¼Æ(MP)¹ï¼Ä¤Hªº­n¥Þµo¥X
­P©Rªº¤@À»
HELP);
return 1;
       }

       void ShowMessage(object me, object target, string msg)
       {
           message_vision( msg, me, target);
       }

       void MoxibustionFail(object me, object target, string msg)
       {
           if( target != me )
           {
               msg += HIB "$N"HIB"¤@­Ó¤À¤ß¡A°w´N´¡¿ù¤F¥Þ¦ì¡AÅý$n"HIB"·P¨ì¤@°}©ü³Ö¡E\n" NOR;
           }
           else
           {
               msg += HIB "$N"HIB"¤@­Ó¤À¤ß¡A°w´N´¡¿ù¤F¥Þ¦ì¡A¦Û¤v·P¨ì¤@°}©ü³Ö¡E\n" NOR;
           }
           ShowMessage(me, target, msg);
       }

       void ShowDamage(object me, object target,int damage)
       {
           if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
               tell_object(me,HIY"("+damage+")"NOR);
           if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
               tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
           if(wizardp(me) && me->query("env/debug"))
               tell_object(me, HIR"  ("+damage+")\n"NOR);
       }

       void SkillImporving(object me, int Bonus)
       {
           me -> improve_skill("moxibustion", 1+Bonus);
           me -> improve_skill("acupuncture_cognition", random(Bonus));
       }

       void rekee(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"ªºÁy¥Ñ»a¥Õ²@µL¦å¦â¡Aº¥¦Ó«ì´_¤F¤£¤Ö¦å®ð¡C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*4/5);
           target -> receive_heal("hp", effect);
       }

       void regin(object me, object target, int effect, string msg)
       {
           msg += HIC"$N"HIC"¯¿¶Ãªº¤º®§¦ü¥G¦³©Ò±±¨î¡A³vº¥Ã­©w¤F¤U¨Ó¡C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("mp", effect*4/5);
           target -> receive_heal("ap", effect);
       }

       void resen(object me, object target, int effect, string msg)
       {
           msg += HIM"ºë¯«µäÃû¤£®¶ªº$N"HIM"¡A¹y®É®e¥ú·Øµo¡Aºë¯««³«³¡C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*4/5);
           target -> receive_heal("mp", effect);
       }

       void advkee(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"»a¥ÕªºÁy¦â¡A¦]¬°¦å®ðªº¹B¦æ¡Aº¥º¥¬õ¼í¤F°_¨Ó¡C\n"NOR ;
           target -> apply_condition("advkee", effect*me->query_tec());
           target -> set_temp("advkee", effect);
       }

       void sky(object me, object target, int effect, string msg)
       {
           object *s_target = all_inventory(environment(me));
           int x,y = sizeof(s_target);
           for(x=0;x<y;x++)
           {
               if( !userp(s_target[x]) || !living(s_target[x]))
                   continue;
               if( s_target[x] == me )
                   continue;
               if( random(me->query_skill("acupuncture_cognition")) > 40 )
               {
                   message_vision("$N·PÄ±¨ì¤@ªÑ®ð±q¡u©Rªù¥Þ¡v¤Î¡u³Ò®c¥Þ¡v½Ä¥X¡A¹y®É¦å®ðªº¹B¦æ¤Î¤º®§³£Ã­©w¤F¤£¤Ö¡C", s_target[x]);
                   me -> receive_damage("mp", effect*19*y/20);
                   s_target[x] -> receive_heal("hp", effect);
                   s_target[x] -> receive_heal("ap", effect);
               }
               else
               {
                   message_vision(HIB"$N"HIB"¤@­Ó¤À¤ß¡A°w´N´¡¿ù¤F¥Þ¦ì¡AÅý$n·P¨ì¤@°}©ü³Ö¡E\n"NOR, me, s_target[x]);
                   me -> receive_damage("mp", effect*19*y/20);
                   s_target[x] -> receive_damage("mp", random(20));
                   s_target[x] -> receive_damage("ap", random(20));
               }
           }
           SkillImporving(me, x*(me->query_int()/8));
       }

       void heal(object me, object target, int effect, string msg)
       {
           msg += HIC"$N"HIC"¨­¤Wªº¶Ë¤f¡A¦åº¥º¥¤î¦í¤F¡A¶Ë¤f¤]¥H½wºCªºªº³t«×ºCºCªººÇ¦X°_¨Ó¡C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("mp", effect*5);
           target -> receive_curing("all", effect);
       }

       void addAttribute(object me, object target, int effect, string msg, int x)
       {
           string Attr;
           switch( x )
           {
           case 0:
               msg += HIY"$N"HIY"ªº¨­¼v¤]º¥º¥ÅÜ±o°ª¤j±j§§¡A¦Ù¦×ªÈµ²¦Ê¾w¥æ¿ù¡I¡I\n"NOR ;
               Attr = "str";
               break;
           case 1:
               msg += HIG"$N"HIG"ªº¨­Åé·PÄ±¦³¤F¨Ç³\ªº§ïÅÜ¡A¦ü¥G±j°·¤F¤£¤Ö¡C\n"NOR ;
               Attr = "con";
               break;
           case 2:
               msg += HIW+BLK"$N"HIW+BLK"©¿µMÄ±±o¾ã­Ó¤H¨IÃ­¤F¤U¨Ó¡A¸£¤¤ªº«äºü¦ü¥G§ó²M·¡¤F¤@¨Ç¡C\n"NOR ;
               Attr = "int";
               break;
           default:
               msg += HIW"$N"HIW"©¿µMÄ±±o¨­Åéªº¨I­«·P®ø¥¢¤F¤£¤Ö¡A¦³ºØ»´ÄÆÄÆªº·PÄ±¡C\n"NOR ;
               Attr = "dex";
               break;
           }
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*15);
           me -> receive_damage("mp", effect*15);
           target -> start_busy(effect/5);
           target -> set_temp("add"+Attr, effect);
           target -> apply_condition("add"+Attr, effect*me->query_tec());
           target -> add_temp("apply/"+Attr, effect);
           target -> add_temp("e_"+Attr, 1);
       }

       void ghost(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"ªº¤â«l©¿µM¼W±j¤F¨Ç³\¡A¹ï©ó¥~¬Éªº§ðÀ»¤]¦h¤F¤£¤Ö©è§Ü¯à¤O¡C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*18);
           me -> receive_damage("mp", effect*18);
           target -> set_temp("ghost", effect);
           target -> start_busy(effect/5);
           target -> apply_condition("ghost", effect*me->query_tec());
           target -> add_temp("apply/damage", effect);
           target -> add_temp("apply/armor", effect);
           target -> add_temp("d_a_up",1);
       }

       void attack(object me, object target, int damage, string msg)
       {
           int BusyTime, HitRate, DodgeRate;


           damage = (me->query_damage()) * (me->query_tec()/2);
           damage -= target->query_armor();
           damage += random((me->query_int())/25 * me->query_skill("moxibustion"));
           damage = COMBAT_D->Merits_damage(me, target, damage, "tec");
           if( damage < 0 )
               damage = 0;

           HitRate = (me->query_skill("acupuncture_cognition"))*2 + me->query_dex();
           DodgeRate = (target->query_dex())/2 + target->query_skill("acupuncture_cognition");

           if( HitRate > DodgeRate )
           {
               msg += HIB"¨­¤W¤Q¤G­Ó­n®`ªº¥Þ¦ì³£³Q´H®ðÀþ¶¡«I¤J¡A¹y®ÉµL¤O©Û¬[¡AÅé¤º®ð«lÃz¨«¡A¤­Å¦¤»µÆ³£¨ü¨ìÄY­«ªº¶Ë®`¡C"NOR ;
               BusyTime = me->query_tec()/3;
               target -> start_busy(BusyTime);
           }
           else
           {
               msg += CYN"¾÷ÆFªº°{¹L¥b¼Æ´H®ð¡A¦ý¤£§KÁÙ¬O¨ü¨ì¤p¤pªºªi¤Î¡C"NOR ;
               damage /= 4;
           }
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", 150);
           me -> receive_damage("mp", 250);
           me -> start_busy(random(2));
           target -> receive_damage("hp", damage);
           target -> receive_damage("ap", damage*4);
           ShowDamage(me, target, damage);
           COMBAT_D->report_status(target);
       }

       int cast_skill(object me, object target, string arg)
       {
           object weapon = me->query_temp("weapon"), *s_target;
           string msg;
           int HitRate, DodgeRate, effect, sk1, sk2, Bonus, x;
           if( !target )
               target = me;
           sk1 = me->query_skill("acupuncture_cognition");
           sk2 = me->query_skill("moxibustion");

           if( arg == "?" || arg == "help" )
               return HelpMoxibustion();

           if( !weapon )
               return notify_fail("§A¤â¤W¨S°w¬O¤£¯à¬I®iª¥¥Þ°w¨bªº¡C\n");
           if( weapon->query("skill_type")!="needle" )
               return notify_fail("§A¤â¤W¨S°w¬O¤£¯à¬I®iª¥¥Þ°w¨bªº¡C\n");
           if( !target )
               return notify_fail("§A¨S¦³¥i¥H¬I®iªº¥Ø¼Ð¡C\n");
           if( me->query("class2") )
           {
               if( target != me && me->query("class2") != "skyowl_med" )
                   return notify_fail("§A¹ï§O¤H¨­¤Wªº¥Þ¹D¦ì¸mªº´x±±ÁÙ¤£¼ô½m¡A¤£¯à¹ï¥L¤H¬I®i¦¹©Û¡C\n");
           }
           if( me->is_busy() )
               return notify_fail("§A²{¦b¥¿¦b¦£¡AµLªk¨Ï¥Îª¥¥Þ°w¨b¡I\n");

           switch( arg )
           {
           case "rekee":
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 5 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 5 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIC"Àø®ð³Z"NOR"¡n¡E\n");
               if( target->query("hp") >= target->query("max_hp") )
                   return notify_fail(target->query("name")+"¨Ã¨S¦³¨ü¶Ë¡A¦ü¥G¤£»Ý°w¨b¡E\n");

               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HIC"Àø®ð³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"¨­Åé¤W·þ¯ßªº¡u©Rªù¥Þ¡v¡C\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   rekee(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "regin":
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 5 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 5 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIG"Àøºë³Z"NOR"¡n¡E\n");
               if( target->query("ap") >= target->query("max_ap") )
                   return notify_fail(target->query("name")+"ªº¤º«l¥R¨K¡A¦ü¥G¤£»Ý°w¨b¡E\n");

               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HIG"Àøºë³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"¤â´x¤W¡u³Ò®c¥Þ¡v¡C\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   regin(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "resen":
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 5 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 5 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"NOR+MAG"Àø¯«³Z"NOR"¡n¡E\n");
               if( target->query("mp") >= target->query("max_mp") )
                   return notify_fail(target->query("name")+"¤´ºë¯«¥ç¥ç¡A¦ü¥G¤£»Ý°w¨b¡E\n");

               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"NOR+MAG"Àø¯«³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"¨­Åé¤W¥ô¯ßªº¡u¯«Âö¥Þ¡v¡C\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   resen(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "advkee":
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 10 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 15 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIC"µ½¥@³Z"NOR"¡n¡E\n");
               if( target->query("hp") >= target->query("max_hp") )
                   return notify_fail(target->query("name")+"¨Ã¨S¦³¨ü¶Ë¡A¦ü¥G¤£»Ý°w¨b¡E\n");
               if( target->query_temp("advkee") )
                   return notify_fail(target->query("name")+"¨­Åé¤º¤w¸g¦³¤@ªÑ·x·x®ð¬y¥¿¦b½w½wªº¬y°ÊµÛ¡C\n");
               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HIC"µ½¥@³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"¤ßÅ¦¤§«áªº¡u¯«¹D¥Þ¡v¡C\n"NOR ;
               if( random(sk1) > 35 )
               {
                   effect = sk2/2;
                   me -> start_busy(2);
                   Bonus = me->query_int()/4;
                   advkee(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "sky":
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 15 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 30 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIR"¶}¤Ñ³Z"NOR"¡n¡E\n");
               message_vision(HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HIR"¶}¤Ñ³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J¨­Ãä©Ò¦³¤Hªº¡u©Rªù¥Þ¡v¤Î¡u³Ò®c¥Þ¡v¡C\n"NOR, me, target);
               if( random(sk1) > 45 )
               {
                   effect = sk2;
                   me -> start_busy(2);
                   sky(me, target, effect, msg);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "heal":
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 20 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 40 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIC"Â¡¥Á³Z"NOR"¡n¡E\n");
               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HIC"Â¡¥Á³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"¨­¤Wªº¶Ë¤f¥|©P¡C\n"NOR ;
               if( random(sk1) > 45 )
               {
                   effect = sk2/5;
                   me -> start_busy(2);
                   Bonus = me->query_int()/4;
                   heal(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addint":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"ªº¨­Åé¤w¸gµLªk¦A±µ¨ü¦×Åé¤Wªº±j¤Æ¤F¡C\n");
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 30 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 50 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIW+BLK"³±¤ß³Z"NOR"¡n¡E\n");
               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"BLK"³±¤ß³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"ÀY³»ªº¡u¦Ê·|¥Þ¡v¡C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 2);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addcon":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"ªº¨­Åé¤w¸gµLªk¦A±µ¨ü¦×Åé¤Wªº±j¤Æ¤F¡C\n");
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 30 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 50 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIG"¤TµJ³Z"NOR"¡n¡E\n");
               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HIG"¤TµJ³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"¨­Åé¤W¤¤¤UµJ¤T³¡¥÷¡C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 1);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "adddex":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"ªº¨­Åé¤w¸gµLªk¦A±µ¨ü¦×Åé¤Wªº±j¤Æ¤F¡C\n");
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 30 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 50 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIW"¶hÄÆ³Z"NOR"¡n¡E\n");
               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-¶hÄÆ³Z¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"»L¤Wªº¡u­·¥«¥Þ¡v¡C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 3);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addstr":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"ªº¨­Åé¤w¸gµLªk¦A±µ¨ü¦×Åé¤Wªº±j¤Æ¤F¡C\n");
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 30 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 50 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIY"¤Ó¶§³Z"NOR"¡n¡E\n");
               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HIY"¤Ó¶§³Z"HIW"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"­I³¡ªº¡uªø±j¥Þ¡v¡C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 0);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "ghost":
               if( target->query_temp("d_a_up") )
                   return notify_fail(target->query("name")+"ªº¨­Åé¤w¸gµLªk¦A±µ¨ü¦×Åé¤Wªº±j¤Æ¤F¡C\n");
               if( me->is_fighting() )
                   return notify_fail("¥´°«¤¤§A¨S¦³®É¶¡´À"+target->query("name")+"°w¨b¡C\n");
               if( me->query("level") < 30 )
                   return notify_fail("§Aªº¸gÅç¤£¨¬¡A¤£¯à¾Õ¦Û´À¥L¤H°wª¥¡E\n");
               if( sk2 < 55 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HBWHT+BLK"°­³±¥@ºë³Z"NOR"¡n¡E\n");
               msg+= HIW"$N"HIW"»´»´ªº§u°ÛµÛ¥j¦ÑªºÁ~¶Ç¸Öºq-"HBWHT+BLK"°­³±¥@ºë³Z"NOR"¡A¤â¤¤"+weapon->name()+HIW"¤]¤Æ¬°ÂIÂI´H¨~¨ë¤J$n"HIW"¤¦¥Ð¤U¡u¤¤·¥¥Þ¡v¡BÀV¤U¡u¤Ñ¬ð¥Þ¡v¡BªÓÀY¡uªÓ¤«¥Þ¡vµ¥¤Q¤G³B¥Þ¹D¤W¡C\n"NOR ;
               if( random(sk1) > 65 )
               {
                   effect = sk2/4;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   ghost(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "attack":
               if( target == me )
                   return notify_fail("¥Î suicide «ü¥O·|¤ñ¸û§Ö:P¡C\n");
               if( sk2 < 70 )
                   return notify_fail("§A¹ïª¥¥Þ°w¨b¤£°÷¼ô½m¡AµLªk¨Ï¥X¡m"HIR"¯«´d°­ª_³Z"NOR"¡n¡E\n");
               if(!me->can_fight(target))
                   return 0;

               if(!me->is_fighting(target))
                   me->kill_ob(target);
               if(!target->is_fighting(me))
                   target->kill_ob(me);

               msg+= HIC"$N"HIC"®©¥X»a¥Í¸Uª«¦º¶Ë½ü°jªº¤Ñ¦a´`Àô¯u²z¡A¯«¦â´d²Y¡C" ;
               msg+=    "\n    ÀH§Y¤@°}¨g²rªº´H®ð¦Û$N"HIC"¤â¤¤ªº°w¾WÂ«¥X¡A¦V$n"HIC"¤Q¤G©Rªùª½öt¦Ó¥h¡I¡I\n" ;
               Bonus = me->query_int()/2;
               attack(me, target, 1, msg);
               SkillImporving(me, Bonus);

               break;
           }
           return 1;
       }

       int valid_learn(object me)
       {
           return 1;
       }
       int practice_skill(object me)
       {
           return 1;
       }
       int improve_limite(object ob)
       {
           return 100;
       }

