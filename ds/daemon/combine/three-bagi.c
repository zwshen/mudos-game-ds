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

//²Ä¤@¶¥¬q	
	message_vision("\n"HIW"  $N, $n©M"NOR,me,member1);
	message_vision(HIW"$N¬ðµM¦U¦Û¦V«á¸õ¶}¤@¨B, ±N$n³ò¦b¤¤¶¡!!\n\n"NOR,member2,target);
	message_vision(
     HIW"	[1;37;42m¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{[0m\n"
	"	[1;37;42m¢x  ¤K·¥¶ø¸q  ­×Ã¹ÅQ¤ý¾aµØ¤s  ¢x[0m\n"
	"	[1;37;42m¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}[0m\n\n"
	"[1;37;44m¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{[0m\n"
	"[1;37;44m¢x    ,o      o      o/¡¸     ¢x[40;33m$N­º¥ýµo°Ê§ð¶Õ!! ¤@¦¡´­¬¶²r¯PªºÀ»¦V$n,\n"
	"[1;37;44m¢x    '|)    ,|'    ()  ¡¹    ¢x[0m\n"
	"[1;37;44m¢x    / >     >\\    / >       ¢x[40;31m$n´e­ó¤@Án, ¦R¤F¤@¤fÂA¦å, §N¦½ª½¬y!!\n"
	"[1;37;44m¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}[0m\n"
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

//²Ä¤G¶¥¬q

	message_vision(
"[1;37;44m¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{[0m\n"
"[1;37;44m¢x o      o      o_,   o_,¡¹  ¢x[40;36m$NÀH§Y¤@­Óºj¨B,·m§ð¦Ó¤W,²rªêµwª¦¤s¶¶¶Õ±À¥X!!\n"
"[1;37;44m¢x ),    <)      ) '   )-' ¡¸ ¢x[0m\n"
"[1;37;44m¢x >^     >~'   / >    >\\     ¢x[40;37m±Æ¤s­Ë®üªº¤@´x±N$n¥´ªº³s°h¤T¨B,Áy¦âºG¥Õ!!\n"
"[1;37;44m¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}[0m\n"
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

//²Ä¤T¶¥¬q
	message_vision(
"[1;37;44m¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{[0m\n"
"[1;37;44m¢x  o_,    o_    o_    _o ¡¸  ¢x[40;32m$nÁÙ¨S¯¸Ã­,¬ðµM­I«á¦R§oÁn°_,¤£¸T·t¦Û¥s­W.\n"
"[1;37;44m¢x  )-'    )_'   )''  `,(  ¡¹ ¢x[0m\n"
"[1;37;44m¢x  >\\     >\\    >\\    /<     ¢x[40;35m$nÁÙ¨Ó¤£¤Î¦^ÀY,¤w³Q$NªºÅK¤s¾a¼²­¸¤Q¤Ø!!\n"
"[1;37;44m¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}[0m\n\n"
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
tell_object(member1,HIW"  §A±o¨ìÃB¥~ªº"+damage1*5+"ÂI¸gÅç­È!\n\n"NOR);
tell_object(member2,HIW"  §A±o¨ìÃB¥~ªº"+damage2*5+"ÂI¸gÅç­È!\n\n"NOR);
tell_object(me,HIW"  §A±o¨ìÃB¥~ªº"+damage3*5+"ÂI¸gÅç­È!\n\n"NOR);
	return 1;
}
