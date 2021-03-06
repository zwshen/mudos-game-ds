#include <ansi.h>.
#include <command.h>
#include <path.h>
#include <weapon.h>
inherit WAND;
inherit SSERVER;
inherit F_CLEAN_UP;
void create()
{
set_name("水晶十字架",({"crystal cross","cross","wand"}));
set_weight(21000);
 if( clonep() )
                set_default_object(__FILE__);
	else {
		set("unit", "把");
set("long",@LONG
這是一把施法者專用的十字架,�媕Y附有神奇的魔法,可以解除封印(invoke 目標)
,當十字架沒法力時可以輸入法力(recharge)到十字架(cross)中。\n
LONG
);
set("oldlong","這是一把施法者專用的十字架,�媕Y附有神奇的魔法,可以解除封印(invoke 目標)"
+",當十字架沒法力時可以輸入法力(recharge)到十字架(cross)中。\n");
set("value",9800);
set("wand",200);
		set("material", "crystal");
	}
init_wand(500);

// These properties are optional, if you don't set them, it will use the
// default values.

 set("wield_msg", "$N從腰間抽出一把$n握在手中。\n");
 set("unwield_msg", "$N將手中的$n放回腰間去。\n");

// The setup() is required.

	setup();
}

int fail_eq(object me)
{
  if(!me=this_player()) return 0;

  if(me->query("class")!="caster") 
  {
     write("這是施法者專用的十字架\n");
     return 1;
  }
  return 0;
}

void init()
{
 add_action("do_invoke","invoke");
 add_action("do_recharge","recharge");
}

int do_invoke(object target)
{                                           
	object me, ob, ob2;
	int damage, lv, in, time;
	string arg;
        
if(!this_player())
return 0;
me=this_player();
 in=me->query("int");  
arg="cross";

if (!target) return notify_fail(HIW"你要對何人用十字架攻擊\n"NOR);

ob=present(arg,me);

if(!ob) return notify_fail("你找不到目標!!\n");

if(me->query_skill("invoke",1)<100)
	return notify_fail(HIW"你的解除封印要100以上才能使用\n");

if(! me->is_fighting() )  return notify_fail("只有在戰鬥中才能invoke\n");

if (me->query_temp("invoke")==1)
	return notify_fail(HIW"你正在解除封印中\n"NOR);

if( (string)ob->query("equipped")!="wielded" )
	return notify_fail("你並沒有裝備這樣東西作為武器。\n");

if (ob->query_temp("time")==0)
	return notify_fail(HIW"你的十字架已經沒有法力了\n"NOR);

if( ob->query("bad")==10)
 {
	ob2=new(LUKY+"pearl/npc/wp/badcross");
	ob2->move(me);
	ob2->wield();
	destruct(ob);
	return notify_fail(HIW"你的十字架已經壞了。\n");
 }
 
if(ob->query("bad")==11)
	return notify_fail("你的十字架已損毀無法再使用\n");

if(me->query_skill("invoke",1)<random(130))
{
 ob->add("bad",1);
 ob->set("long",sprintf("%s\n"HIW"(十字架尚餘%2d發能量, 而且上面有%2d道明顯的裂痕.)\n\n",
 ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );
 return notify_fail(HIW"你的十字架產生裂縫\n"NOR);
}

if(!target) return notify_fail("你要對誰施展這個法術﹖\n");

if(target==me) return notify_fail("你不能對自己使用\n");

else if(!objectp(target = present(target, environment(me))) )
             return notify_fail("你要對誰施展這個法術﹖\n");

if(!living(target) ) return notify_fail(HIY"這不是生物喔\n"NOR);

ob->add_temp("time",-1);
ob->set("long",sprintf("%s\n"HIW"(十字架尚餘%2d發能量, 而且上面有%2d道明顯的裂痕.)\n\n",
ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );

damage=900+random(in*8);

message_vision(HIY"$N靜下心來注視魔法杖,慢慢解除十字架的封印\n\n"+
HIW"$N"HIW"的手心的光芒慢慢成一顆小型的聖光彈..\n\n"+"咻∼∼∼一聲向$n擊去\n\n"
+"造成$n"+damage+"傷害力\n\n",me,target);
target->receive_damage("hp",damage, me);
if( me->is_fighting() )
{
 me->kill_ob(target);
}
else if(target) target->kill_ob(me);

me->add_temp("invoke",1);
call_out("delay",3,me);
return 1;
}

int do_recharge(string arg)                     
{                                           
object me,ob,ob2;
int time;
me = this_player();              
if(!me) return 0;
if(!arg) return 0;
if(arg=="wand" || arg=="cross")
{
ob = present(arg, me);
if(!ob) return 0;
if( me->is_fighting() )
	return notify_fail(HIW"戰鬥中不能封印法術\n"NOR);
if(me->query_skill("recharge",1)<120)
	return notify_fail(HIW"你的魔法封印要學到120以上才能使用\n");
if (me->query_temp("delay")==1)
	return notify_fail(HIW"你正在灌法力給十字架\n"NOR);
if( (string)ob->query("equipped")!="wielded" )
	return notify_fail("你並沒有裝備這樣東西作為武器。\n");
if (ob->query("bad")==11)
	return notify_fail("你的十字架已損毀無法再使用\n");
if( ob->query("bad")==10)
 {
	ob2=new(LUKY+"pearl/npc/wp/badcross");
	ob2->move(me);
	ob2->wield();
	destruct(ob);
	return notify_fail(HIW"你的十字架已經壞了。\n");
 }

if (ob->query_temp("time")==10)
	return notify_fail(HIW"你的十字架無法再輸入法力了\n"NOR);
if(me->query("mp")<100)
	return notify_fail(HIW"你沒有足夠的法力灌入十字架中\n"NOR);
me->add("mp",-100);
ob->add_temp("time",1);
ob->set("long",sprintf("%s\n"HIW"(十字架尚餘%2d發能量, 而且上面有%2d道明顯的裂痕.)\n\n",
ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );
write(HIY"你的法力徐徐的慢慢灌入十字架之中\n"NOR);
if(me->query_skill("recharge")<random(130))
 {
	ob->add("bad",1);
	ob->set("long",sprintf("%s\n"HIW"(十字架尚餘%2d發能量, 而且上面有%2d道明顯的裂痕.)\n\n",
	ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );
	return notify_fail(HIW"你的十字架產生裂縫\n"NOR);
 }
write(HIW"十字架慢慢吸收你輸入的法力\n"NOR);
me->start_busy(2);
me->set_temp("delay",1);
call_out("delay",3,me);
}
else 
 {
 write(HIW"你要 recharge 什麼??\n"NOR);
 }
return 1;                        
}                                

int delay(object me)
{
	if(!me) return 0;
	me->delete_temp("delay");
	me->delete_temp("invoke");
	return 1;
}
