#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"虎符"NOR, ({"tiger tally","tally"}) );
	set_weight(80);
	                       
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一張斑駁的黃色符令，大大的虎形印在上面！");
		set("unit", "張");
		set("value", 1);		
	}
	setup();
}

void init()
{
	add_action("do_use", "use");
}

int do_use(string arg) 
{
	object me = this_player(), ob = this_object();
	if( !this_object() ) return 0;
	if( !this_object()->id(arg) ) return 0;
	
	me->set("env/msg_home", HIG"虞.. 我的美人..妳在哪裡！霸王回來了...\n"NOR);
	me->set("env/msg_clone", HIG"$N一振臂，隨身的十八鐵騎即刻策馬將$n"HIG"呈上來。\n"NOR);
	me->set("env/msg_min", HIG"剎時戰雲密佈，戰鼓聲憾天震地！十八鐵騎簇擁著$N以秋風掃落葉之姿奔來！\n"NOR);
	me->set("env/msg_mout", HIG"$N怒喝一聲：「隨我來！」十八鐵騎頓時策馬奔騰隨$N衝鋒而去！\n"NOR);
	
	write(HIG"你焚化一張將軍令，裊裊雲煙將你團團圍住！\n"NOR); 
	
	destruct(ob); 
	return 1;
} 


