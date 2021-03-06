/* 疾風門 ： 殘月心法(moon_force) 由 Cominging 於 1999/5/29 日所創 */

#include <ansi.h>
inherit SKILL;
void delay(object me);

int exert(object me,object target, string arg)
{
        int heal,reheal,sk,lv,times;
        
        if( arg=="off" )
        {
                if( me->query_skill_mapped("force")!="moon_force" )
                        return notify_fail("你並沒有在運功\。\n");
                me->delete_temp("is_busy/moon_force");
                message_vision(HIY"$N閉起的兩眼慢慢睜開，內息又流回經脈中了。\n"NOR,me);
                me->map_skill("force");
                return 1;
        }
        if( arg=="recover" )
        {
        	if( me->query("ap") < 20 )
                	return notify_fail("你目前的狀況不佳，無法使用殘月心法。\n");
                if( me->query_skill("moon_force") < 10 )
                        return notify_fail("你的殘月心法基礎不夠！\n");
                heal= (int)me->query("max_hp");
        	if( me->query("hp") >= heal )
                	return notify_fail("你目前的生命狀況已經是極限了。\n");
		if(heal>4000) heal = 4000 + ((heal-4000)/8);
                sk = (int)me->query_skill("moon_force");
                lv = (int)me->query("level");
                if ( sk > 50 ) sk = 50 + ((sk-50)/2);
                reheal = (heal / 20) + ((sk/5)*3) + random(9) + (lv/2);
                me->receive_heal("hp",reheal);
                me->receive_damage("ap",27 + reheal/7 + random(4));
                me->start_busy(2);
                message_vision(HIR"$N一時間靜下心來，運氣點了身上各傷口旁的大穴。\n"NOR,me);
                return 1;
        }
	if( arg=="addtimes" )
	{
		if( me->is_busy() )
			return notify_fail("你正在忙。\n");
		if( me->is_ghost() )
			return notify_fail("你是鬼喔。\n");
		if( me->query("ap") < 80 )
			return notify_fail("你的內力不足，無法將內力貫於臂上。\n");
		if( me->query("dex") < 15 || me->query_skill("fogseven") < 50 )
			return notify_fail("你的身形還不夠敏捷。\n");
		if( me->query_skill("moon_force") < 40 )
			return notify_fail("你的殘月心法還不夠熟練。\n");
		times = me->query("max_ap")/150;
		if(times>10) times=10;
		if(times<1) times=1;
		if( me->query_temp("sorgitimes") >= 3+times )
			return notify_fail("你的手臂已經無法再承受更大的壓力了。\n");
		message_vision(HIW"$N手臂微微顫動，顯然有一股功\力被凝聚在手臂之上。\n"NOR,me);
		if(!me->query_temp("sorgitimes")) me->set_temp("sorgitimes",me->query_skill("moon_force")/22);
		else if((3+times)-me->query_temp("sorgitimes") < me->query_skill("moon_force")/22)
			me->add_temp("sorgitimes",(3+times)-me->query_temp("sorgitimes"));
		else me->add_temp("sorgitimes",me->query_skill("moon_force")/22);
		if((times-3)<1) times=1;
		if((times-3)>5) times=5;
		me->receive_damage("ap",(30*(me->query_skill("moon_force")/22))-random(me->query_skill("moon_force")/2));
		me->start_busy(1+random(2));
		return 1;
	}
        if( me->is_ghost() )
                return notify_fail("你一提氣上來，結果因為四肢百駭之氣皆無，因而失敗了！\n");
        if( me->is_busy() )
                return notify_fail("你現在正在做別的事，難到你可以一心多用？\n");
        if( me->is_fighting() )
                return notify_fail("你現在正忙著打架, 沒空練功\。\n");
        if( me->query_skill_mapped("force")=="moon_force" )
                return notify_fail("你現在還在修煉殘月心法中。\n");
        if( me->query("hp") < 20 || me->query("ap") < 20 )
                return notify_fail("你目前的狀況不佳，無法修煉心法。\n");
        
        if(!me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3))
          return notify_fail("你結束運功\的動作還沒完成。\n");


        message_vision(HIC"$N隨地盤腳坐下，氣運百骸，聚檀中而養息。\n"NOR,me);
        me->map_skill("force","moon_force");

        me->receive_damage("ap", 5);
        me->receive_damage("hp", 2);
        me->set_temp("is_busy/moon_force","你正在膳養內息，暫時不能移動。");
        me->start_busy(2);
	//me->start_call_out( (: call_other, __FILE__, "delay", me :), 2);
        return 1;
}

void delay(object me)
{
        int sk_level,lv,i;
        
        sk_level = me->query_skill("moon_force");
        lv = me->query("level");
        i = me->query_int();

        if( !me ) return;

        if( me->query_skill_mapped("force")!="moon_force" )return;

        if( me->query("ap") < 13 || me->query("hp") < 13 )
        {
                message_vision(HIR"$N心神如一道光劃過，瞿然停止了運功\。\n"NOR,me);
                me->delete_temp("is_busy/moon_force");
                me->map_skill("force");
                return;
        }
	else
        if ( sk_level < 50 )
        {
                me->receive_damage("ap",8);
                me->receive_damage("hp",5);
        }
        else
        if ( sk_level > 49 )
        {
                me->receive_damage("ap",12);
                me->receive_damage("hp",7);
        }
        me->improve_skill("force",1+random(2)+random(1+lv/3));
        me->improve_skill("moon_force",1+random(3)+random(1+lv/3));
 	//me->start_call_out( (: call_other, __FILE__, "delay", me  :), 3);
 	me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3);
}

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return 1;
}

void skill_improved(object me)
{
        int b,c;
        b = me->query_skill("moon_force",1);
	c = me->query("skill/moon_force");//luky
	
        if( b % 20==19 && b > c)
        {
                tell_object(me, HIR "你的敏捷和體質由於領悟殘月心法有道，因而上升了。\n" NOR);
                me->add("addition/dex", 1);
                me->add("addition/con", 1);
                me->set("skill/moon_force",b);
        }
        me->save();
}
int improve_limite(object ob)
{
        int a;
        a=(ob->query("level")*3)+(ob->query_int()/2);
        if(a > 90 && ob->query("level")<26 ) a=90;
        else if(a>100) a =100;
        return a; 
}
