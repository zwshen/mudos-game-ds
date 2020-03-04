#include <ansi.h>
#include <combat.h>

inherit NPC;
void create()
{
        set_name(MAG"����"NOR"��",({"amethyst python","python"}));
        set("race", "���~");
        set("age", 500+random(1000));
        set("long", "�@�����~�ۤƦ��P���������A�u�����һ{�i���H�~�����|�ݨ쥦�E\n");
        set("limbs", ({ "�Y��", "����", }) );
        set("verbs", ({ "bite", "hoof", "crash"}) ); 
        set_skill("unarmed",100+random(100));
        set_skill("dodge",100+random(100));
        set_skill("parry",100+random(100)); 
        set("no_kill",1);

        setup();
}

void init()
{
        call_out("check",2,this_object());
        ::init();
}

void check()
{
        object me,ob,wp;
        int durable;

        me = this_player();
        ob = this_object();
        durable = ob->query_temp("durable");
        wp = new(__DIR__"dagger3");
       
        if(!ob->is_fighting())           
        {
        message_vision("\n$N����l���F�_�ӡA�A���ܦ��F�@��P���E\n",ob);
        wp->set_durable(durable);
        wp->move(environment(me));  
        destruct(ob);        
        } else {
        call_out("check",10,ob);
        }
}

void die()
{
        object ob,wp;
        int durable = this_object()->query_temp("durable");
        wp=new(__DIR__"dagger3");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        message_vision("\n$N����l���F�_�ӡA�A���ܦ��F�@��P���E\n",this_object());
        wp->set_durable(durable-random(10));
        wp->move(environment(this_object()));
        destruct(this_object()); 
        return;
}

int special_attack(object me, object target, int hitchance)
{
  int tdex,tdodge,damage; 
  tdex = target->query("dex");
  tdodge = target->query_skill("dodge");  if(!me) return 0;
  if(me->is_busy()) return 0;
 switch( random(5) ){
  case 0: 
  message_vision("\n$N���W��"MAG"���������"NOR"�{�X�@�}"HIW"�벴�����~"NOR"�K\n"NOR,me); 
  if( random(tdex + tdodge) < 130 && !target->is_busy() )  {
  message_vision(HIC"$N�Q�o�j�P�����~�g���A�ʧ@�ܱo�ǳ\\��w�E\n\n"NOR,target);
  target->start_busy(1+random(3)); 
  return 1;  } else {
  message_vision("$N�����@���A�׶}�F�oģ�����j���E\n\n",target);
  return 1;
  }
  break;
  case 1:
  message_vision("\n$N�i��j�f��$n���F�L�h�K\n",me,target);
  if( random(tdex + tdodge) < 150 )  { 
  message_vision(GRN"$N�������ΡA���W�d�U�F�@�ӥ��j�����D�r���E\n\n"NOR,target);
  me->attack();  
  target->receive_damage("hp",random(500));
  target->receive_wound("head",random(2)); 
  target->receive_wound("body",random(2));
  target->apply_condition("blooding", random(10));  
  return 1;
  } else {
  message_vision("$N�����@�D�A�C�b���l�����L�F�o���������E\n\n",target);
  return 1;
  }
  break; 
  case 2:
  COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
  COMBAT_D->report_statue(target); 
  break;
 }
  return 0;
}
