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
	if(me->is_ghost()) return notify_fail("�A�٬O���a�C\n");
        if(me->query_spell("god-benison") < 20) return notify_fail("�A�������N�u����ë�g�v�m���~��ϥΥl��N�C\n");
        if(me->is_busy() ) return notify_fail("�A�{�b�����ۡA�S���ŧa�C\n");
	if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("�A�ثe�����骬�A�L�k�ϥΡu���F�l��v�C\n");
        if(me->is_fighting()) return notify_fail("�A�{�b�����ۡA�S���ŧa�C\n");
        if(sk < 20) return notify_fail("�A���u���F�l��v�٥������J�A�|�L��O�ϥΡC\n");
	  else if(sk < 50) max_ghost=1;
	  else if(sk < 90) max_ghost=2;
	  else max_ghost=3;
	
	if(me->query_temp("ghost_summoned")) return notify_fail("�A�����𮧤@�|��~��A���l�갭��C\n");;
	if(check_ghost(me) >= max_ghost) return notify_fail("�H�A�ثe�u���F�l��v����O, �u��l��o��h����C\n");
                
                message_vision(HIG
                "$N�q��u����ë�g�v���u�C��v�Z�G\n\n" NOR
                +HIM"      �u�����b�W�A���^�B��C���f�f�A�N�y�y�C�v\n" NOR
                +HIM"      �u�Y�o���H�ޡA�ܤƳ��s�X�j�W�C�v\n" NOR
                +HIB"\n\n�n��$N���|�P���v�����A�����}�}....\n" NOR
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
     ob->set("name",me->query("name")+"���t���");
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
     ob->set_temp("no_combine",1);	//���}���
     ob->set("creater",me);		//�аO�D�H
     ob->set_leader(me);
     me->add_temp("summon_ghost",({ ob }));

     message_vision(HIW "\n�u��$N���Ǫ������@�_�A�����۰��S��ڡA�������E���@�ѤH��.....\n"NOR
     ,me);
   }
   else 
   {
   	message_vision(HIW "\n�u��$N�|�P���v���q�A�S��_�F���`���ˤl�A�ݨӤ���Ƥ]�S���o�͡C\n"NOR,me);
   	return 1;
   }
   
   me->improve_spell("summon_ghost",random(2+level/5)+inn/10);
   if(random(sk + inn + me->query_spell("god-benison")/2 +level) < random(level*2)) //�l�ꥢ�ѫ~
   {
    ob->set("name",HIM+"���Ҩ���"+NOR);
    ob->set("attitude", "aggressive");
    ob->delete("creater");
    ob->set("no_creater",1);
    ob->set_leader(0);
   }

   ob->move( env );
   tell_room(env,"�A�����M�X�{�F�@��"+ob->name()+"�C\n");
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