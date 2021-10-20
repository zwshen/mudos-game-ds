#include <ansi.h> 
inherit NPC;    

void create()
{
  set_name(HIR"�P�V�u"NOR, ({"fire ball","ball"}) );
  set("long","���Q�S�ҦR�X���������y�C\n");
  set("unit","��");
  set("level",40); 
  set("age",0);
  set("max_hp",30000);
  setup(); 
  call_out("dest_ball", 2+random(3));
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me,object target,int hitchance)
{
  object *inv;
  int damage,dex_r,block_r,i;
  inv = all_inventory(environment(me));
  if(!me || !inv) return 0;
  message_vision("\n$N"HIW"�e�t���b�|�P��Ī����A�n�g�X�L�Ƥ��P�I\n"+NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      damage = random(100)+450-(inv[i]->query_shield())-(inv[i]->query_armor()/2);
      if(damage < 0) damage=0;
      dex_r=random(inv[i]->query_dex());
      block_r=random(inv[i]->query_skill("block"));
      if( dex_r > 50 )
      {
        message_vision(HIG"$N�����}�֡A���L�P�V�u�������C\n"NOR,inv[i]);
      }
      else if( block_r > 70 && inv[i]->query_temp("armor/shield") )
      {
        message_vision(HIG"$N�ήɥH�޵P�w�O�צ�P�V�u�������A�P�V�u�P�޵P�����E�X���P�|�q�C\n"NOR,inv[i]);
      }
      else
      {
        message_vision(HIR"$N�Q�P�V�u���������A�y�� ("+damage+") �I�����ˤΨ`�ˡI\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        COMBAT_D->report_status(inv[i]);
      }
    }
  }
  return 1; 
}    

void dest_ball()
{
  destruct(this_object());
}