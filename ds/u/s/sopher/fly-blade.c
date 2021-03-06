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
"我擋﹗我擋﹗我擋﹗擋﹗擋﹗\n"
        });

string *unarmed_parry_msg = ({
"但是被$n格開了。\n",
"結果被$n擋開了。\n",
});

string *nine_dragon = ({
HIC"             ∼∼∼壹∼∼∼         只見一道刀光揮向$n的『 唐竹 』\n",
HIC"             ∼  ∼貳  ∼  ∼       只見一道刀光斜砍向$n的『 逆袈裟 』\n",
HIC"           ∼∼  ∼參∼  ∼∼       只見一道刀光橫砍向$n的『 右稚(桐)』\n",
HIC"           ∼∼∼  肆  ∼∼∼       只見一道刀光斜切向$n的『 右切上 』\n",
HIC"           ∼  ∼∼伍∼∼  ∼       只見一道刀光由下切上向$n的『 逆風 』\n",
HIC"           ∼    ∼陸∼    ∼       只見一道刀光斜切向$n的『 左切上 』\n",
HIC"             ∼∼  柒  ∼∼         只見一道刀光橫砍向$n的『 左稚(逆桐) 』\n",
HIC"           ∼  ∼  捌  ∼  ∼       只見一道刀光斜砍向$n的『 袈裟斬 』\n",
HIC"           ∼∼∼∼玖∼∼∼∼       只見一道刀光刺向$n的『 刺突 』\n",
});

string *shasword = ({
});



mapping *action = ({
//1
        ([
                "action"     :
HIY"$N收起$w翻石撥土 ,使出了飛天御劍流亂擊術ソ『 土龍閃 』﹗
"HIY"瞬間土石化殘影若飛向$n而去﹗",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "瘀傷"
        ]),
//2
        ([
                "action"     :
HIY"$N飛身高躍 ,消失在$n的視線內 ,倏然使出了飛天御劍流『 龍槌閃 』﹗
"HIY"從上空舉起$w劈了下去 ,只見$w壓曲地逼近$n的腦門﹗",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "瘀傷"
        ]),
//3
        ([
                "action"     :
HIY"$N步若游光 ,以神快的速度步入$n面前 ,使出了飛天御劍流『 龍翔閃 』﹗
"HIY"$w的刀光如浩日光輝由下往上揮向$n喉心",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "割傷"
        ]),
//4
        ([
                "action"     :
HIY"$N突然殺氣四溢 ,大喝一聲﹗使出了飛天御劍流亂擊術ソ『 龍巢閃 』﹗
"HIY"泛起波波殺意如刃麻一般地向$n亂斬而去"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "割傷"
        ]),
//5
        ([
                "action"     :
HIC"$N將手裡的$w收入劍鞘內 ,使出了飛天御劍流ソ拔刀術"HIR"『 雙龍閃 』"HIY"﹗
以神速的身手抽出$w ,往$n的身上揮去"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                140,
                "force"      :                140,
//                "post_action":                (: sp_attack4 :),
                "damage_type":               "割傷"
        ]),
//6
        ([
                "action"     :
HIY"$N一個倒身轉 ,如峰迴路轉般繞到$n的身旁 ,使出了飛天御劍流『 龍卷閃 』﹗
"HIY"$N利用迴心力的迴旋使著$w砍向$n的身後要害"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                150,
                "force"      :                150,
//                "post_action":                (: sp_attack5 :),
                "damage_type":               "刺傷"
        ]),
//7
         ([     "action"     :
HIY"$N聚精凝神 ,突然步若飛劍衝向$n  ,使出了飛天御劍流亂擊術ソ『 九頭龍閃 』﹗
"HIY"只見刀光如晨光乍現 ,化成九條金龍劃向$n",
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                150,
                "force"      :                150,
                "post_action":                (: sp_attack6 :),
                "damage_type":                "刺傷",
           ]),
});

int valid_learn(object me)
{

       if( !me->query_temp("weapon")){
        tell_object(me,"練飛天御劍流必需先拿把刀。\n");
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
  message_vision(HIR"無限的光彈往$n飛了過去﹗\n"NOR, me, victim);
  for(i = 0; i < lose; i++)
  {
  victim->receive_damage("hp",random(sp_value/2),me);
  COMBAT_D->report_status(victim);
  }
  if(random(victim->query("psy") / 2 + victim->query("dex") ) < 20)
  {
  message_vision(HIY"$n被光彈亂擊後 ,一時心亂大喘心神未定。\n"NOR,me,victim);
  victim->start_busy(1);
  }
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
    sp_value = str + con / 2 +dex /4;
    if(victim->query("level") < ( me->query("level") / 3 ) ) {
    message_vision(HIR"$n承受不了龍槌閃的衝擊而昏厥倒地。\n"NOR, me, victim);
victim->set("hp",-1);
    victim->set(",mp",-1);
    COMBAT_D->report_status(victim);
    victim->set_temp("unconcious", 1);
    return 0;
    }
    if(victim->query("level") < ( me->query("level") * 2 / 3 ) ) {
message_vision(HIY"$n因龍槌閃的衝擊而昏昏欲墜 ,一時站不穩。\n"NOR, me, victim);
    victim->start_busy(2);
    victim->receive_wound("hp",random(sp_value/4));
    COMBAT_D->report_status(victim);
    return 0;
    }
   if(victim->query("level") < ( me->query("level") * 4 / 3) ){
   message_vision(HIY"$n因龍槌閃衝擊的影響而痲了一下。\n"NOR,me ,victim);
   victim->start_busy(1);
   return 0;
   } else {
   message_vision(HIC"$n似乎沒受到甚麼影響的樣子。\n"NOR,me ,victim);
   return 0;
   }
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
    sp_value =random(con+str/4+dex);
    message_vision(HIC"$N氣勢如宏 ,只見$n喉心"HIR"�"HIW"�"HIR"�"HIW"�"HIC"四濺 "NOR);
    victim->receive_damage("hp",sp_value/4,me);
    COMBAT_D->report_status(victim);
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
    int i ,lose;
    sp_value =random(str)+10;
    lose = random(str/2+dex/8+con/4)+str/2;
    if( lose > 7 ) lose = 7;
    message_vision(HIW"只見$n被劍影刀光所圍 ,乍看之下就如龍巢一般 ,光影四射 ,雷光四濺"NOR);
    for(i = 0; i < lose; i++ )
    {
victim->receive_damage("hp",sp_value ,me);
    COMBAT_D->report_status(victim);

}
   if(random(victim->query("psy") / 2 + victim->query("int") ) < 40)
   {
   message_vision(HIR"$n身上刀傷多處 ,喘息不定 ,一時動彈不得。\n"NOR,me,victim);
   victim->start_busy(3);
   }
   victim->start_busy(2);
}
void sp_attack4(object me, object victim, object  weapon, int damage)
{
    int i;

    message_vision(HIR"
$N趁勢翻身飛躍，斜迴劍尖，念轉靈動使出"HIW"『紅染夕陽』"HIR"，霎時
殺意狂奔，欲噬血腥無法自制，劍鼓風旋，連鎖成無數無形風刃，削
肉刮骨欲罷不能"NOR,me,victim);
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
眨眼間 ,刀鋒泛泛殺意 ,刀光漸如燄日逼人
     $N一聲大喝 ,手中ソ刀猶似金龍摧天，刀幻千光只在一瞬間$n已完全金龍被吞沒﹗
\n"NOR,me,victim);
    for(j=0; j < 9; j++) {
       do_action = nine_dragon[j];
              actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
         if( random(me->query("level")) > random(enemy[i]->query("level"))/6 ) {
       message_vision("\n$N閃躲不及 ,身上瞬時多出了一道血淋淋的刀痕﹗\n" , enemy);
       enemy[i]->receive_wound("hp",random(100)+100,me);
       me->add("force",-30);
       COMBAT_D->report_status(enemy[i]);
                             }
else message_vision("\n$N人比刀快，驚險地閃過﹗\n" , enemy[i]);
                }
}

