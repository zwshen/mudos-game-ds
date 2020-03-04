#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("闇黑之劍",({"darkfool sword","sword"}) );
	set("long",@long
一把看來非常黝黑的長劍，尤如漆黑、寂靜的宇宙一般，毫無大自然
的生機，令人寒懼。這口長劍相傳為數百年前，一位宇宙探險家－「闇黑
傻瓜」，於一次探測「楊威利星座群」的「龍蝦黑洞」中所得到的「藍藍
的礦石」打鑄而成的。據聞此劍能容讓其主人的魔法力，而有更強力的攻
擊力，你不禁想試試....(powerin)
long
	);
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	set("unit","把");
	set("wield_msg","$N「刷」一聲，從腰間抽出一把漆黑長劍握在手上。 \n");
	set("value",500);
	set("material","iron");
	set("limit/str",30);
	set("weapon_prop/hit",30);
	set("weapon_prop/parry",30);
	set("weapon_prop/int",10);
	}
	init_sword(20);
	setup();	
}

void init()
{
	add_action("do_powerin","powerin");
}
void attack(object me,object target)
{

int damage,str,dex;

if(this_object()->query_temp("power") )
{
	str = me->query("str");
	dex = me->query("dex");
	damage=(str+dex)*(1+random(10));

	message_vision("                  冰•風暴戰斧突然發出強大的光芒

                       從天上召喚來一陣冰雹

              向$N擊去！！！造成$N"+damage+"點的傷害！！！！\n",me
	);
	this_object()->set_temp("power",0);
   return;
}

}

int do_powerin(string arg)
{
	object me,obj;
	me=this_player();
	obj=this_object();

 	if(arg) return 0;
	if(me->query("mp") <200) return notify_fail("你的魔法力不夠，不能加持。\n");
	if(me->is_busy() ) return notify_fail("你現在沒有空！\n");
	if(me->query_temp("powering") ) return notify_fail("你已在加持法力了。\n");
	me->set_temp("powering",1);
	me->start_busy(5);
	message_vision(HIW"\n\n       $N緊握著劍柄，喃喃地唸道：「龍蝦大大...請賜給我神祕的力量∼∼∼」\n"NOR,me);
	message_vision(HIG"\n只見$N的雙手發出一陣陣綠色的神聖光芒，漸漸地包圍住闇黑之劍。\n"NOR,me);
	call_out("powerin_msg",5,me,obj);			
	return 1;
}
int powerin_msg(object me,object obj)
{
	int i;
	if(!me) return 0;
	i=random(10);
	me->add("mp",-100);	
	message_vision(HIG "\n只見瑩繞著闇黑之劍的綠色神聖光芒漸漸地被劍所吸收了....\n" NOR ,me);
	
	if(i<2)
	{	
		tell_object(me,BLU"你覺得你所灌注的魔法力由如石沈大海一去無蹤.....\n"NOR);
	}	
	else
	{
		tell_object(me,BLU"輕過你幸苦地加持之後，闇黑之劍似乎更顯得耀眼、鋒銳。\n"NOR);
	}

	obj->set_temp("power",1);
	me->delete_temp("powering");
	return 1;
}
