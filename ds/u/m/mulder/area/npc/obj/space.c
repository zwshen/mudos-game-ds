#include <ansi.h>
#include <combat.h>

inherit ITEM;
#define DELAY 1

string *nuclear = ({
        "火炎之光",
        "終結一擊",
        "全力一擊",
        "神聖之光",
        "黑之光",
        "愛心之光",
        "會心一擊",
        "水之光",
        "希望之光",
        "大神一擊 ",
	});


string *color = ({
	MAG,
	HIG,
	HIY,
	HIW,
	HIC,
	HIR,
	});

string *shipname = ({
        HIY+"保時捷 "+NOR,
        HIW+"法拉利 "+NOR,
        HIG+"林寶堅尼 "+NOR,
        HIW+"寶馬"+NOR,
        HIB+"麥羅輪 "+NOR,
        HIC+" 賓士"+NOR,
        HIY+"平冶 "+NOR,
	});
int v = random(sizeof(nuclear));
int x = random(sizeof(color));

void create()
{
	set("long","這是一些由前所未見的物質造成的宇宙船，相信這是由外太空得來的。\n");
	set_name(HIC"宇宙船"NOR+shipname[random(sizeof(shipname))],({"spaceship","ship"}));
	set("no_get",1);
	set("no_drop",1);
	set("nuclear",999999999999999999999);
	set("count",100000000000000000000);
	set("bullet",50000000000000000000);
}

void init()
{
	add_action("launch_Nuclear","laiser");
	add_action("do_ascend","ascend");
	add_action("do_descend","descend");
	add_action("do_fly","flyto");
	add_action("do_shoot","shoot");
}

int do_ascend()
{
	object me;

	me=this_player();
	if(me->query_temp("marks/ascend"))
	return notify_fail("你已經在宇宙船。\n");
	message_vision("$N進入了"+this_object()->name()+"的宇宙船。\n",me);
	me->set_temp("marks/ascend",1);
	me->add_temp("apply/short",({me->short()+HIY"(正指揮著"NOR+this_object()->name()+HIY")"NOR}));
	move(me);
	return 1;
}

int do_descend()
{
	object me;
	string *name;

	me=this_player();
	if(!me->query_temp("marks/ascend"))
	return notify_fail("你已經離宇宙船了。\n");
	message_vision("$N隨著"+this_object()->name()+"的緩降梯降了下來。\n",me);
	me->delete_temp("marks/ascend");
	me->delete_temp("apply/short");
	move(environment(me));
	return 1;
}

int launch_Nuclear(string arg)
{
	string msg;
	int nu;
	object who,me;
	me = this_player();

	if(this_object()!=present(this_object(),this_player()) )
	return notify_fail("你並未駕駛該宇宙船。\n");

	if( !(nu = (int)this_object()->query("nuclear")) ) {
	write(this_object()->name()+"武器已經用盡。\n");
	return 1;
	}
	nu--;
	set("nuclear", nu);

	if(!arg) return notify_fail("標定人員：你想以誰為激光中心？。\n");


	who = present(arg,environment(me));


	msg=HIR"宇宙船的激光炮緩緩開啟，"+HIW+"船內武器系統開始落點光學瞄準！！\n"NOR;
	message_vision(msg,me);
	message_vision(HIY"座標鎖定開始輸入慣性導航資料∼輸入確認！\n\n"NOR,me);

	if(!who) who=find_living(arg);
	if(!who) {
	who=this_player();
	message_vision(HIR"Ａｂｏｒｔ！！Ａｂｏｒｔ！！失去目標，緊急強迫取消發射！\n"NOR,me);
	return 0;
	}

	call_out("Nu_1",DELAY+2,me,who,arg);
	me->start_busy(3);
	return 1;
}

int Nu_1(object me,object who,string arg)
{
	message_vision(MAG"這裡是星艦武器官：確認啟動，激光發射開始！\n"NOR,me);
	message_vision(HIC"艦內回報："HIR"亞米加粒子炮準備發射！\n\n"NOR,me);
		message_vision(HIR"星艦武器官：亞米加粒子炮∼∼"HIB""+color[x]+nuclear[v]+color[x]+"∼確認！\n\n"NOR,me);

	tell_room(environment(who),
	HIG"雲層上空突然閃出很強大的光 ，"MAG"聲音越來越接近不像是閃電，有一條光線以高速飛來的樣子。\n\n"NOR);


	call_out("Nu_2",DELAY+5,me,who,arg);
	me->start_busy(5);
	return 1;

}

int Nu_2(object me,object who,string arg)
{
	mixed all;
	object room,a;
	int i;
	room = environment(who);
	all = all_inventory(room);

	message_vision(HIY"資訊導航官：命中目標∼∼依電腦管理標準計算，破壞半徑200哩確認。\n\n"NOR,me);

	tell_room(environment(who),
	HIR""+nuclear[v]+"激光穿破大氣層往"+ who->query("name") +"射來。\n\n"
	HIY"轟∼∼∼的一聲巨響，"HIG"激光中心捲起一陣紅光的沖天火焰。\n\n"
	HIR"幾乎在同一時間，火焰像狂風一般的襲捲吞沒了這一片空間。\n\n"
	HIW"隨著你肉體的消逝，所有在此的人也都毫無機會的在片刻間死去。\n\n"NOR);


	for(i = 0 ; i < sizeof(all) ; i++)
	{
	 a = all[i];
	 if(living(a))		//add by Luky
	 {
	   a->die();
	   CHANNEL_D->do_channel(this_player(),"rumor",
		sprintf("%s在亞米加粒子炮"+nuclear[v]+"殘酷的攻擊之下，無能為力的消失在火焰中！",a->name()));
	 }
	}
	return 1;
}

int do_fly(string arg) //拷貝MH的teleport,想修改成能計算upkeep....:P
{
	object who,me;
	int count1;


	if( this_object() != present(this_object(),this_player()) )
		return notify_fail("你並未駕駛該宇宙船。\n");

	if( !arg ) return notify_fail("導航官：艦長，請指定飛行點。\n");

	me=this_player();
	who = find_player(arg);
	if (!who) who = find_living(arg);
	if (!who) return notify_fail("導航官：艦長，請指定飛行點。\n");

	count1 = (int)this_object()->query("count");
	if( (count1 -= 4) < 0 ) {
		count1 += 4;
		set("count",count1);
		return notify_fail(this_object()->name()+"能量已經不足以進行飛行。\n");
	}

	set("count",count1);
		message_vision("$N"HIW"引擎啟動，開始航向導航點。\n",this_object());
	tell_room(who,this_object()->name()+HIB"飛向此地，定位停陣完畢。\n"NOR);
	me->move(environment(who));
	return 1;
}

int do_shoot(string act)
{
	string msg;
	object ob,target;

	ob = this_object();
	if( this_object() != present(this_object(),this_player()) )
	return notify_fail("你並未駕駛該艦。\n");

	if(ob->query("bullet")<=0) {
	write(this_object()->name()+"槍砲武器已經用盡。\n");
	return 1;
	}

	if( act ) target = present( act, environment(this_player()) );

	if(!target
	||	!target->is_character()
	|| target->is_corpse()
	||	target==this_player())
		return notify_fail("炮手：艦長，請指定射擊目標。\n");

	msg = "$n"+HIR+"雷達開始捕捉目標瞄準，還將目標了鎖定"+HIY+"保護者"+HIR+"高速飛彈機炮開啟。\n"NOR;
	message_vision(msg,target,ob);
	message_vision("$n"HIB"上的砲塔，開始旋轉對準"NOR"$N"HIY"，準備開始射擊。\n"NOR,target,ob);

	call_out("shoot_2",DELAY+2,this_player(),target,ob,act);
	this_player()->start_busy(3);
	return 1;
}

int shoot_2(object me,object target,object ob,string act)
{
	string msg;
	int damage,i,bul,dp,pp,dx,nt,kr,cha;

	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE) ;
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE) ;
//	dx = target->query_attr("dex");	//
//	nt = target->query_attr("int");	//參考 /feature/attribut.c
//	kr = target->query_attr("kar");	//這裡的用法如下兩行
	dx = target->query_dex();
	nt = target->query_int();

	cha = pp*2 +dp*2 +dx +nt +target->query_armor()*3;

	for(i=0; i<10; i++)
	{
	bul = (int)this_object()->query("bullet");
	if ( (bul -= 50+random(100) ) < 0 ) {
	bul += 50+random(100);
	set("bullet",bul);
	}  
	set("bullet",bul);

	damage = 500+random(500) -cha/3;

	if(ob->query("bullet") <= 0 ) 
	{
	message_vision("$n"HIW"的飛彈倉卡∼卡的空響著，顯然彈藥已耗盡。\n"NOR,target,ob);
	ob->set("bullet",0);
	break;
		}
	else{
	msg = HIY"砲塔噴火地射出第"+(i+1)+"枝飛彈∼"NOR;
	}
	if ( damage > 0) {
	msg +=HIR"$N"HIR"鮮血狂噴而出。"HIR"(" + damage + ")\n" NOR;
		message_vision(msg,target,ob);
		target->receive_damage("hp", damage, me);	//fix by luky
		COMBAT_D->report_status(target);		//fix by luky
	}  else {
	msg +=HIW"可是飛彈無害的打在"NOR"$N"HIW"身上。\n"NOR;
	message_vision(msg,target,ob);
		} 
	}
	me->start_busy(1);
	target->start_busy(1);
	return 1;
//	}
}
