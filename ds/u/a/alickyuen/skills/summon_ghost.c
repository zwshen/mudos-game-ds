#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int summon_ghost(object me,int sk,int inn);
int check_ghost(object me);
void delay(object me);
int cast(object me, object target)
{
        int sk,inn,max_ghost;
        object ob;
	string ghost_num;
        sk=me->query_spell("summon_ghost");
        inn=me->query_int();
	if(me->is_ghost()) return notify_fail("你還是鬼吧。\n");
        if(me->query_spell("god-benison") < 20) return notify_fail("你必須先將「神祝禱篇」練熟才能使用召喚術。\n");
        if(me->is_busy() ) return notify_fail("你現在正忙著，沒有空吧。\n");
	if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("你目前的身體狀態無法使用「幽靈召喚」。\n");
        if(me->is_fighting()) return notify_fail("你現在正忙著，沒有空吧。\n");
        if(sk < 20) return notify_fail("你的「幽靈召喚」還未成火侯，尚無能力使用。\n");
	  else if(sk < 50) max_ghost=1;
	  else if(sk < 90) max_ghost=2;
	  else max_ghost=3;
	
	if(me->query_temp("ghost_summoned")) return notify_fail("你必須休息一會兒才能再次召喚鬼魂。\n");;
	if(check_ghost(me) >= max_ghost) return notify_fail("以你目前「幽靈召喚」的能力, 只能召喚這麼多鬼魂。\n");
                
                message_vision(HIG
                "$N默唸「神祝禱篇」之「遊魂」訣：\n\n" NOR
                +HIM"      「重陰在上，鬼氛浮游。神黯黯，意悠悠。」\n" NOR
                +HIM"      「若得陰人引，變化魚龍出大淵。」\n" NOR
                +HIB"\n\n登時$N的四周鬼影重重，陰風陣陣....\n" NOR
                ,me);
	
		me->start_busy(3);
		call_out("summon_ghost",3,me,sk,inn);
	        me->receive_damage("mp",(sk/2)+(inn/2)+random(inn/3));
        return 1;
}

int summon_ghost(object me,int sk,int inn)
{
   object ob,env;
   int level;
   if(!me) return 0;
   if(me->is_ghost()) return 0;
   env=environment(me);
   if(!env) return 0;
   level=me->query("level");
   if(me->query_temp("call_ghost")<=2 && (sk+me->query_int() ) >random(40) )
   {
     ob=new(__DIR__"npc/ghost");
     ob->set("name",me->query("name")+"的孤魂野鬼");
     ob->set("level",(sk/6)+(level/3)+random(4));
     ob->set("str",(sk/6)+(me->query_str()/3)+random(4));
     ob->set("con",(sk/5)+(me->query_con()/3)+random(4));
     ob->set("int",(sk/6)+(me->query_int()/3)+random(4));
     ob->set("dex",(sk/6)+(me->query_dex()/3)+random(4));
     ob->set("max_hp",ob->query_con()*33);
     ob->set("max_mp",(ob->query_int()*25+ob->query_con()*5));
     ob->set("max_ap",(ob->query_int()*5+ob->query_con()*25));
     ob->set("hp",ob->query("max_hp"));
     ob->set("ap",ob->query("max_ap"));
     ob->set("mp",ob->query("max_mp"));
     ob->setup();
     ob->set_temp("no_combine",1);	//分開顯示
     ob->set("creater",me);		//標記主人
     ob->set_leader(me);
     me->add_temp("summon_ghost",({ ob }));

     message_vision(HIW "\n只見$N身旁的煙霧一起，伴雜著鬼嘯魂啼，漸漸凝聚成一股人形.....\n"NOR
     ,me);
   }
   else 
   {
   	message_vision(HIW "\n只見$N四周鬼影隱默，又恢復了平常的樣子，看來什麼事也沒有發生。\n"NOR,me);
   	return 1;
   }
   
   me->improve_spell("summon_ghost",random(2+level/5)+inn/10);
   if(random(sk + inn + me->query_spell("god-benison")/2 +level) < random(level*2)) //召喚失敗品
   {
    ob->set("name",HIM+"赤煉邪鬼"+NOR);
    ob->set("attitude", "aggressive");
    ob->delete("creater");
    ob->set("no_creater",1);
    ob->set_leader(0);
   }

   ob->move( env );
   tell_room(env,"你身邊突然出現了一個"+ob->name()+"。\n");
   me->set_temp("ghost_summoned",1);
   call_out("delay",30,me);
   return 1;
}

void delay(object me)
{
  if(!me) return;
  if(me->query_temp("ghost_summoned")) me->delete_temp("ghost_summoned");
  return;
}

int check_ghost(object me)
{
 object *ghost=({});
 if(!me) return 0;
 if(!ghost = me->query_temp("summon_ghost")) return 0;
 ghost -= ({0});
 return sizeof(ghost);
}

int improve_limite(object ob)
{
	if(!ob) return 0;
	if(ob->query("adv_class")==1) return (ob->query_int()+30); 
        else return 90;
}
