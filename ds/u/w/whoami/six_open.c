/*
   Editor-Js@DS
   SK : �K���������j�}
   �γ~: �s�y�C�ʶˮ`
*/
#include <ansi.h>
#define SKILL_NAME "�K�����j�}-��"   
inherit SKILL;
inherit SSERVER;    

string *actions=({
"�E�����y","�ꥴ���y","��L","�㥴","½���p��","��L"
});  
int exert(string arg)
{
                object me=this_player(),target;
                //weapon=me->query_temp("weapon");
                int sk=me->query_skill("six_open"),damage,c,bpower;
                string act=actions[random(sizeof(actions))];
                bpower=random(me->query("level"));                if(!target) target = offensive_target(me);  // �ĤH
                if(!me) return 0;
                if(!target) return 0;
                if(me->is_busy() ) return 0; 
                if(me->query_temp("do_six_open") ) return 0;   
                //if(weapon->query("skill_type")!="fist") 
                  //return notify_fail("�ϥ�"+SKILL_NAME+"�����ϥλP���k�۲ŦX���Z���Τ��ϥΪZ���C\n");
                if(me->query("ap")<50) return notify_fail("�A�����l�����ϥX"+SKILL_NAME+"\n");
                if( !target ) return notify_fail("�A�n��֨ϥX"+SKILL_NAME+"?\n");    
                if(!me->is_fighting()) return notify_fail(SKILL_NAME+"�O�@�ؾ԰��ޯ�!\n");
                if(me->query_skill("bagi_fist")<100)
                  return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn��T���K�����k�C\n"); 
                if(me->query_skill("horse-steps")<100)
                  return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�`�p���K���㰨�C\n"); 
                if(me->query_skill("parry")<70)
                  return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���m���Z���۬[�C\n");
                if(me->query_skill("unarmed")<100)
                  return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���m���Ť�i���ޥ��C\n");     

                c=target->query_armor()*2;
                damage=me->query("str")*2
                      +me->query_Merits("bar")*8
                      +me->query_skill("six_open")*3
                      -c+random(50);
                if(me->query_temp("exert_mark/bagi-power") > 0 ){
                damage=damage+me->query_temp("exert_mark/bagi-power")*2;                }
                // str->130 bar->15 sk->60 bagi-power->120 => max = 800
                message_vision(HIG "\n$N�ϥX�u���j�}�v�j�P���l�A�@�ѱj�l�������������l�|���ӥX...\n" NOR,me,target);
                message_vision(HIG "$N�@��"+ HIB "�u"+ act + "�v"+HIG"�A²��Ө��t�a���������l�������V$n�ݫe�n�`�I�I\n"NOR,me,target);              
        // �����R��
                if(  random(100) < COMBAT_D->attack_factor(me,"unarmed")*10/15 
                  || random(100) > -COMBAT_D->dodge_factor(target,"dodge")  ) {
                                message_vision(HIR "$n�{�����ΡA�����Q$N�����ݤf�A�ذդ@�n�A���O�ذ��H�����n���I�I\n"  
NOR,me,target); 
                                target->receive_damage("hp",damage,me);
                                target->start_busy(2); 
                                me->start_busy(1);   
                                me->receive_damage("ap",40+random(5),me);                                 
                                me->add_temp("do_six_open",1);
                                if(me->query_temp("exert_mark/bagi-power") > bpower ){
                                me->add_temp("exert_mark/bagi-power",-bpower);
                                } 
                                tell_object(me,HIR"["+damage+"]���ˮ`��\n"NOR);
                                //target->add_temp("do_six_open",1); 
                                call_out("do_six_opened",random(15),target);  
                                me->improve_skill("six_open",10+random(me->query_int()/6+sk/8));   
                } else {
                        switch(random(3))
                        {
                        case 0:
                                message_vision(HIW ""+target->query("name")+"�b�d���@�v���ڡA�{�}�F"+me->query("name")+"�r�P������....\n" NOR,target,me); 
                                me->start_busy(2);
                                break;
                        case 1:
                                message_vision(HIW ""+target->query("name")+"�������a���F�}�h�A���}�F�o�@�������....\n" NOR,target,me); 
                                me->start_busy(2);
                                break;
                        case 2:
                                message_vision(HIW ""+target->query("name")+"�u�z�v�@�n�y�s�A����Y½���u�F�}�h�A���}�F�o�����I�ǭP�R������...\n" NOR,target,me); 
                                me->start_busy(2);
                                break;
                        }
               }  
            return 1;
}  
/*
int do_six_opened(string arg)
{ 
     object target,me;  
     me=this_player();
     target = offensive_target(me);  
     int damage;
     //int sk=me->query_skill("six_open");
     if(!me->query_temp("do_six_open") ) return 0;  
     { 
     damage = me->query_damage()*3+me->query_str()*3;
     damage = COMBAT_D->Merits_damage(me,target,damage,"bar"); 
     message_vision(HIR""+target->query("name")+"���Y�@�K�I�򴤦��ݽ��A�r�M�a�R�F�f�A��I\n"NOR,target);  
     target->receive_damage("hp",damage,target);   
     target->delete_temp("do_six_opened",1);
     }
     return 1;
} 
*/ 
int do_six_opened(string arg)
{ 
    object me=this_player(); 
    if(!me) return 0;
    me->delete_temp("do_six_open",1);
    return 1;
}
int improve_limite(object ob)
{
  return 60;
}
