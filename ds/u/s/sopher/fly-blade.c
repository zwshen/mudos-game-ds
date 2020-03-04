#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);
int str=this_player()->query_str();
int con=this_player()->query_con();
int dex=this_player()->query_dex();
int sp_value;

string *parry_msg = ({
"§Ú¾×¡T§Ú¾×¡T§Ú¾×¡T¾×¡T¾×¡T\n"
        });

string *unarmed_parry_msg = ({
"¦ý¬O³Q$n®æ¶}¤F¡C\n",
"µ²ªG³Q$n¾×¶}¤F¡C\n",
});

string *nine_dragon = ({
HIC"             ¡ã¡ã¡ã³ü¡ã¡ã¡ã         ¥u¨£¤@¹D¤M¥ú´§¦V$nªº¡y ­ð¦Ë ¡z\n",
HIC"             ¡ã  ¡ã¶L  ¡ã  ¡ã       ¥u¨£¤@¹D¤M¥ú±×¬å¦V$nªº¡y °f³P¸Æ ¡z\n",
HIC"           ¡ã¡ã  ¡ã°Ñ¡ã  ¡ã¡ã       ¥u¨£¤@¹D¤M¥ú¾î¬å¦V$nªº¡y ¥k¸X(®ä)¡z\n",
HIC"           ¡ã¡ã¡ã  ¸v  ¡ã¡ã¡ã       ¥u¨£¤@¹D¤M¥ú±×¤Á¦V$nªº¡y ¥k¤Á¤W ¡z\n",
HIC"           ¡ã  ¡ã¡ã¥î¡ã¡ã  ¡ã       ¥u¨£¤@¹D¤M¥ú¥Ñ¤U¤Á¤W¦V$nªº¡y °f­· ¡z\n",
HIC"           ¡ã    ¡ã³°¡ã    ¡ã       ¥u¨£¤@¹D¤M¥ú±×¤Á¦V$nªº¡y ¥ª¤Á¤W ¡z\n",
HIC"             ¡ã¡ã  ¬m  ¡ã¡ã         ¥u¨£¤@¹D¤M¥ú¾î¬å¦V$nªº¡y ¥ª¸X(°f®ä) ¡z\n",
HIC"           ¡ã  ¡ã  ®Ã  ¡ã  ¡ã       ¥u¨£¤@¹D¤M¥ú±×¬å¦V$nªº¡y ³P¸Æ±Ù ¡z\n",
HIC"           ¡ã¡ã¡ã¡ã¨h¡ã¡ã¡ã¡ã       ¥u¨£¤@¹D¤M¥ú¨ë¦V$nªº¡y ¨ë¬ð ¡z\n",
});

string *shasword = ({
});



mapping *action = ({
//1
        ([
                "action"     :
HIY"$N¦¬°_$wÂ½¥Û¼·¤g ,¨Ï¥X¤F­¸¤Ñ±s¼C¬y¶ÃÀ»³NÇU¡y ¤gÀs°{ ¡z¡T
"HIY"Àþ¶¡¤g¥Û¤Æ´Ý¼v­Y­¸¦V$n¦Ó¥h¡T",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "·ï¶Ë"
        ]),
//2
        ([
                "action"     :
HIY"$N­¸¨­°ªÅD ,®ø¥¢¦b$nªºµø½u¤º ,°¿µM¨Ï¥X¤F­¸¤Ñ±s¼C¬y¡y Àsºl°{ ¡z¡T
"HIY"±q¤WªÅÁ|°_$w¼A¤F¤U¥h ,¥u¨£$wÀ£¦±¦a¹Gªñ$nªº¸£ªù¡T",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "·ï¶Ë"
        ]),
//3
        ([
                "action"     :
HIY"$N¨B­Y´å¥ú ,¥H¯«§Öªº³t«×¨B¤J$n­±«e ,¨Ï¥X¤F­¸¤Ñ±s¼C¬y¡y Àsµ¾°{ ¡z¡T
"HIY"$wªº¤M¥ú¦p¯E¤é¥ú½÷¥Ñ¤U©¹¤W´§¦V$n³ï¤ß",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "³Î¶Ë"
        ]),
//4
        ([
                "action"     :
HIY"$N¬ðµM±þ®ð¥|·¸ ,¤j³Ü¤@Án¡T¨Ï¥X¤F­¸¤Ñ±s¼C¬y¶ÃÀ»³NÇU¡y Às±_°{ ¡z¡T
"HIY"ªx°_ªiªi±þ·N¦p¤b³Â¤@¯ë¦a¦V$n¶Ã±Ù¦Ó¥h"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "³Î¶Ë"
        ]),
//5
        ([
                "action"     :
HIC"$N±N¤â¸Ìªº$w¦¬¤J¼CÀT¤º ,¨Ï¥X¤F­¸¤Ñ±s¼C¬yÇU©Þ¤M³N"HIR"¡y ÂùÀs°{ ¡z"HIY"¡T
¥H¯«³tªº¨­¤â©â¥X$w ,©¹$nªº¨­¤W´§¥h"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                140,
                "force"      :                140,
//                "post_action":                (: sp_attack4 :),
                "damage_type":               "³Î¶Ë"
        ]),
//6
        ([
                "action"     :
HIY"$N¤@­Ó­Ë¨­Âà ,¦p®p°j¸ôÂà¯ëÂ¶¨ì$nªº¨­®Ç ,¨Ï¥X¤F­¸¤Ñ±s¼C¬y¡y Às¨÷°{ ¡z¡T
"HIY"$N§Q¥Î°j¤ß¤Oªº°j±Û¨ÏµÛ$w¬å¦V$nªº¨­«á­n®`"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                150,
                "force"      :                150,
//                "post_action":                (: sp_attack5 :),
                "damage_type":               "¨ë¶Ë"
        ]),
//7
         ([     "action"     :
HIY"$N»Eºë¾®¯« ,¬ðµM¨B­Y­¸¼C½Ä¦V$n  ,¨Ï¥X¤F­¸¤Ñ±s¼C¬y¶ÃÀ»³NÇU¡y ¤EÀYÀs°{ ¡z¡T
"HIY"¥u¨£¤M¥ú¦p±á¥ú¥E²{ ,¤Æ¦¨¤E±øª÷Às¹º¦V$n",
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                150,
                "force"      :                150,
                "post_action":                (: sp_attack6 :),
                "damage_type":                "¨ë¶Ë",
           ]),
});

int valid_learn(object me)
{

       if( !me->query_temp("weapon")){
        tell_object(me,"½m­¸¤Ñ±s¼C¬y¥²»Ý¥ý®³§â¤M¡C\n");
        return 0;
                                     }

        return   1;
}

int exert(string usage)
{
        return ( usage=="blade" || usage=="parry" );
}


mapping query_action(object me, object *weapon)
{

 int skill_level,limit,i;

 skill_level = (int)(me->query_skill("fly-blade",1));
 limit= skill_level;

        if (limit < 15)
        return action[random(1)];
        else if (limit < 30)
                return action[random(2)];
        else if (limit < 45)
                return action[random(3)];
        else if (limit < 60)
                return action[random(4)];
        else if (limit < 75)
                return action[random(5)];
        else if (limit < 90)
                return action[random(6)];
        else
          return action[random(7)];
}

void sp_attack0(object me, object victim, object  weapon, int damage)
{
  int i, lose;
  sp_value = 5 * me->query("level") / victim->query("level") + 1;
  if( sp_value > 10)  sp_value = 10;
lose = random(str/4+con/8);
  if( lose > 5 )  lose = 5;
  message_vision(HIR"µL­­ªº¥ú¼u©¹$n­¸¤F¹L¥h¡T\n"NOR, me, victim);
  for(i = 0; i < lose; i++)
  {
  victim->receive_damage("hp",random(sp_value/2),me);
  COMBAT_D->report_status(victim);
  }
  if(random(victim->query("psy") / 2 + victim->query("dex") ) < 20)
  {
  message_vision(HIY"$n³Q¥ú¼u¶ÃÀ»«á ,¤@®É¤ß¶Ã¤j³Ý¤ß¯«¥¼©w¡C\n"NOR,me,victim);
  victim->start_busy(1);
  }
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
    sp_value = str + con / 2 +dex /4;
    if(victim->query("level") < ( me->query("level") / 3 ) ) {
    message_vision(HIR"$n©Ó¨ü¤£¤FÀsºl°{ªº½ÄÀ»¦Ó©ü³Ö­Ë¦a¡C\n"NOR, me, victim);
victim->set("hp",-1);
    victim->set(",mp",-1);
    COMBAT_D->report_status(victim);
    victim->set_temp("unconcious", 1);
    return 0;
    }
    if(victim->query("level") < ( me->query("level") * 2 / 3 ) ) {
message_vision(HIY"$n¦]Àsºl°{ªº½ÄÀ»¦Ó©ü©ü±ý¼Y ,¤@®É¯¸¤£Ã­¡C\n"NOR, me, victim);
    victim->start_busy(2);
    victim->receive_wound("hp",random(sp_value/4));
    COMBAT_D->report_status(victim);
    return 0;
    }
   if(victim->query("level") < ( me->query("level") * 4 / 3) ){
   message_vision(HIY"$n¦]Àsºl°{½ÄÀ»ªº¼vÅT¦Ó·ò¤F¤@¤U¡C\n"NOR,me ,victim);
   victim->start_busy(1);
   return 0;
   } else {
   message_vision(HIC"$n¦ü¥G¨S¨ü¨ì¬Æ»ò¼vÅTªº¼Ë¤l¡C\n"NOR,me ,victim);
   return 0;
   }
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
    sp_value =random(con+str/4+dex);
    message_vision(HIC"$N®ð¶Õ¦p§» ,¥u¨£$n³ï¤ß"HIR"¦"HIW"å"HIR"¥"HIW"ú"HIC"¥|Âq "NOR);
    victim->receive_damage("hp",sp_value/4,me);
    COMBAT_D->report_status(victim);
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
    int i ,lose;
    sp_value =random(str)+10;
    lose = random(str/2+dex/8+con/4)+str/2;
    if( lose > 7 ) lose = 7;
    message_vision(HIW"¥u¨£$n³Q¼C¼v¤M¥ú©Ò³ò ,¥E¬Ý¤§¤U´N¦pÀs±_¤@¯ë ,¥ú¼v¥|®g ,¹p¥ú¥|Âq"NOR);
    for(i = 0; i < lose; i++ )
    {
victim->receive_damage("hp",sp_value ,me);
    COMBAT_D->report_status(victim);

}
   if(random(victim->query("psy") / 2 + victim->query("int") ) < 40)
   {
   message_vision(HIR"$n¨­¤W¤M¶Ë¦h³B ,³Ý®§¤£©w ,¤@®É°Ê¼u¤£±o¡C\n"NOR,me,victim);
   victim->start_busy(3);
   }
   victim->start_busy(2);
}
void sp_attack4(object me, object victim, object  weapon, int damage)
{
    int i;

    message_vision(HIR"
$N¶X¶ÕÂ½¨­­¸ÅD¡A±×°j¼C¦y¡A©ÀÂàÆF°Ê¨Ï¥X"HIW"¡y¬õ¬V¤i¶§¡z"HIR"¡AÀK®É
±þ·N¨g©b¡A±ý¾½¦å¸{µLªk¦Û¨î¡A¼C¹ª­·±Û¡A³sÂê¦¨µL¼ÆµL§Î­·¤b¡A«d
¦×¨í°©±ý½}¤£¯à"NOR,me,victim);
me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");

}
void sp_attack6(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;

  force=me->query("force",1);
  enemy = me->query_enemy();
i=random(sizeof(enemy));

message_vision(HIR"
¯w²´¶¡ ,¤M¾Wªxªx±þ·N ,¤M¥úº¥¦p¿V¤é¹G¤H
     $N¤@Án¤j³Ü ,¤â¤¤ÇU¤MµS¦üª÷ÀsºR¤Ñ¡A¤M¤Û¤d¥ú¥u¦b¤@Àþ¶¡$n¤w§¹¥þª÷Às³Q§]¨S¡T
\n"NOR,me,victim);
    for(j=0; j < 9; j++) {
       do_action = nine_dragon[j];
              actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
         if( random(me->query("level")) > random(enemy[i]->query("level"))/6 ) {
       message_vision("\n$N°{¸ú¤£¤Î ,¨­¤WÀþ®É¦h¥X¤F¤@¹D¦å²O²Oªº¤M²ª¡T\n" , enemy);
       enemy[i]->receive_wound("hp",random(100)+100,me);
       me->add("force",-30);
       COMBAT_D->report_status(enemy[i]);
                             }
else message_vision("\n$N¤H¤ñ¤M§Ö¡AÅåÀI¦a°{¹L¡T\n" , enemy[i]);
                }
}

