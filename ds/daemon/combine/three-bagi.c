//
#include <ansi.h>
inherit SKILL;

int combine(object me, object target,object *members)
{
	string msg;
	object member1,member2;
	int i,damage1,damage2,damage3,exp;
	
	if( !target ) return 0;
	if(random(3)) return 0;
	if(!me->can_fight(target)) return me->can_fight(target);
	
	for(i=0;i<sizeof(members);i++)
	{
	 if(members[i]->query_skill_mapped("unarmed")!="bagi_fist") continue;
	 if(members[i]->is_busy()) continue;
	 if(!member1) member1=members[i];
	 else {
	    	member2=members[i];
	 	break;
	      }
	}
	
	if(!member1 || !member2)
	{
		//message_vision("Combine_attack Error: Can't find member !\n",me);
		return 0;
	}
	
	if(member1->query("ap")< 10 || member2->query("ap")< 10 || me->query("ap") < 10 ) return 0;

//第一階段	
	message_vision("\n"HIW"  $N, $n和"NOR,me,member1);
	message_vision(HIW"$N突然各自向後跳開一步, 將$n圍在中間!!\n\n"NOR,member2,target);
	message_vision(
     HIW"	[1;37;42m┌──────────────┐[0m\n"
	"	[1;37;42m│  八極奧義  修羅霸王靠華山  │[0m\n"
	"	[1;37;42m└──────────────┘[0m\n\n"
	"[1;37;44m┌──────────────┐[0m\n"
	"[1;37;44m│    ,o      o      o/☆     │[40;33m$N首先發動攻勢!! 一式揚炮猛烈的擊向$n,\n"
	"[1;37;44m│    '|)    ,|'    ()  ★    │[0m\n"
	"[1;37;44m│    / >     >\\    / >       │[40;31m$n悶哼一聲, 吐了一口鮮血, 冷汗直流!!\n"
	"[1;37;44m└──────────────┘[0m\n"
	,member1,target);

		damage1=member1->query_damage() + member1->query_skill("bagi_fist")/3;
		damage1-=target->query_armor()/2;
		damage1*=2;
		if(damage1<5) damage1=5;
		target->receive_damage("hp",damage1,member1);
		member1->receive_damage("ap",5);
		target->start_busy(2);
		member1->start_busy(1);
        member1->add("exp",damage1*5);
		member1->improve_skill("bagi_fist",1+member1->query_int());

//第二階段

	message_vision(
"[1;37;44m┌──────────────┐[0m\n"
"[1;37;44m│ o      o      o_,   o_,★  │[40;36m$N隨即一個槍步,搶攻而上,猛虎硬爬山順勢推出!!\n"
"[1;37;44m│ ),    <)      ) '   )-' ☆ │[0m\n"
"[1;37;44m│ >^     >~'   / >    >\\     │[40;37m排山倒海的一掌將$n打的連退三步,臉色慘白!!\n"
"[1;37;44m└──────────────┘[0m\n"
	,member2,target);

		damage2=member2->query_damage() + member2->query_skill("bagi_fist")/3;
		damage2-=target->query_armor()/2;
		damage2*=2;
		if(damage2<7) damage2=7;
		target->receive_damage("hp",damage2,member2);
		member2->receive_damage("ap",7);
		target->start_busy(2);
		member2->start_busy(1);
		
        member2->add("exp",damage2*5);
		member2->improve_skill("bagi_fist",1+member2->query_int());

//第三階段
	message_vision(
"[1;37;44m┌──────────────┐[0m\n"
"[1;37;44m│  o_,    o_    o_    _o ☆  │[40;32m$n還沒站穩,突然背後吐吶聲起,不禁暗自叫苦.\n"
"[1;37;44m│  )-'    )_'   )''  `,(  ★ │[0m\n"
"[1;37;44m│  >\\     >\\    >\\    /<     │[40;35m$n還來不及回頭,已被$N的鐵山靠撞飛十尺!!\n"
"[1;37;44m└──────────────┘[0m\n\n"
	,me,target);

		damage3=me->query_damage() + me->query_skill("bagi_fist")/2;
		damage3-=target->query_armor()/2;
		damage3*=2;
		if(damage3<10) damage3=10;
		target->receive_damage("hp",damage3,member2);
		me->receive_damage("ap",10);
        target->add_block(3);
		me->start_busy(1);
        me->add("exp",damage3*5);
		me->improve_skill("bagi_fist",1+me->query_int());
tell_object(member1,HIW"  你得到額外的"+damage1*5+"點經驗值!\n\n"NOR);
tell_object(member2,HIW"  你得到額外的"+damage2*5+"點經驗值!\n\n"NOR);
tell_object(me,HIW"  你得到額外的"+damage3*5+"點經驗值!\n\n"NOR);
	return 1;
}
