#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
	set_name(HIC"龍胳臂"NOR,({"dragon fist","fist"}) );
	set("long",@long
這是一對呈龍臂形狀的手用武器，為八極門掌門李書文，於早年雲遊
四海時，所使用的獨門武器。傳聞李書文曾憑藉此龍胳臂，單槍匹馬，獨
挑十三寨數百名山賊盜寇，前後不出三天，登時遍傳武林，更使得此項兵
器更是揚名立萬，成為徒手兵器之王。
long
	);
       set_weight(8000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","對");
		set("volume",2);
	set("value",7000);
            set("limit_str",20);
	set("wield_msg",
HIW "$N雙手套上一對$n"HIW+"，登時$N散發出一股凜冽殺氣，令人不寒而慄。\n"
NOR);
	}
	set("weapon_prop/hit",10);
	init_fist(45);
	setup();
}

void attack(object me,object target)
{
	int damage,def;

    if(me->query_skill("unarmed") > 50 && me->query_str() > 20 && random(10)<3 )
	{
	message_vision( 
 MAG "\n只見$N"+MAG "手中的龍爪氣勁紫氣大現，一道接一道的氣勁，狠狠攻向$n要害！！\n" NOR
	,me,target);

	damage += me->query_skill("unarmed")+me->query_str()+random(50);
	def += target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
	def = def/3;
	if(damage-def>0 && random(10)>5)
	{
    damage=damage+random((damage-def));
       message_vision(HIR "$N閃躲不及，八道龍爪氣勁照單全收，頓時身上爪痕累累看來傷得不輕！！\n"NOR,target);
    target->receive_damage("hp",damage);
	}
	else
	{
      message_vision(HIG "$N接二連三躲開龍爪氣勁的攻勢。\n"NOR,target);
	}

	}
	return;
}
