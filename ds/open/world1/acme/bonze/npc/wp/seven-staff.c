#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIR"七七嬰杖"NOR,({"seven staff","staff","_SEVEN_STAFF_"}));
        set("long",
          "一把令正道聞之氣奪的魔杖，此杖為利用無辜嬰孩提煉而成，卻仍活生\n"
        "生不得轉生投胎，看著杖上蠕動的血腥嬰頭，你不禁為之心寒。\n"
        );
          set_weight(12000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "把");
         set("value",5000);
        set("material","copper");
          set("volume",3);
            set("limit_level",10);
        }
        set("weapon_prop/int",2);
        init_staff(32);
        setup();
} 

void attack(object me,object target)
{
        object ob;
        ob=this_object();
    if(!me) return;
        if(random(10)>7 && me->query_skill("staff") > 40)
        {
                message_vision(HIR"\n$N"+HIR"上頭的嬰靈陡著發出一聲淒癘哭聲∼∼∼\n"NOR,ob);
                ob->add("staff-use",1);
                if(random(3)==2) {
                        if(random(me->query_int() ) < random(10) ) return;
                        tell_object(target,CYN "你只覺得腦中一陣昏胘....\n" NOR);
                        target->start_busy(1);
                }
                else  {
                if( random(me->query_int()) < random(30)  ) return;
                        tell_object(me,GRN "你只覺得一股寒流從手中的七七嬰杖傳到體內！！\n" NOR);
                        me->receive_heal("ap",1 + me->query_int()*2 );
                        me->receive_heal("mp",1 + me->query_int()*2 );
                }

              if( ob->add("staff-use") > me->query("level")*3 )
              { 
                        message_vision(GRN"\n$N手中的$n"+GRN"化成一陣經煙，消失不見了..\n"NOR,me,ob);
                        ob->unequip();
                        destruct(ob);
                }
      }
        return;
}

