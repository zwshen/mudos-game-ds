#include <ansi.h>
#include <combat.h>
inherit NPC;

// �S�˪Z���ɪ�����
void do_combat_attack();
mapping *combat_action = ({
  ([  "action":       "$N���ʱa�ۺ����P�V���k��A�H�p�^�U�v�������V$n",
      "attact_type":  "bio",
      "damage_type":  "����",
  ]),
  ([  "action":       "$N�i�}�a�ۺ����P�V������A�p�P�j���@��n�V$n",
      "attact_type":  "bio",
      "damage_type":  "����",
  ]),
  ([  "action":       "$N��۵J�g���a���B��A�{�p�U�N���p���s�������V$n",
      "attact_type":  "bio",
      "damage_type":  "����",
  ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void heal();
void create()
{
  set_name(HIR"���Q�S"NOR, ({"ifrit","_IFRIT_"}) );
  set("long",@LONG
���æb�a���`�B���]���A�ר�`�X�{�b�����s���a�������B�A�S�H��
�D�O���Q�S�y�����s�����A�٬O���s�����l�ޥ��Q�S�X�{�A����
�������|�Q�`�A�ѩ�������Q�����������V�]��A�u��ݨ쥨�j���H
�Τ��K�ª����l�C
LONG
);
  set("gender", "����");  
  set("race", "beast");
  set("unit","��");
  set("age",3260);
  set("level",80);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",RED"���]��"NOR); 
  set("limbs", ({ "�Y��","����","�ݳ�","����","�k��","����","���l","�k�}","���}"}) );
  set("verbs", ({ "bite","crash","claw" }) );
  set("Merits/bar",14);
  set("Merits/bio",14);
  set("Merits/wit",11);
  set("Merits/sou",8);
  set("Merits/tec",11);
  add("addition_damage",100);
  add("addition_armor",230);
  add("addition_shield",100);
  set_temp("apply/hit",30);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: heal :),
     }));
  set("chat_chance_combat",30);
  set("chat_msg_combat", ({
     (:do_combat_attack():),
     }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_IFRIT_");
}

// auto kill �ι�W���������ĤH���e����
void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(�w������)"NOR"$N�N�@�κ������V���V$n���e�A$n�@�ɷW�F��}�I�I\n"NOR,this_object(),this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

// �S���԰��ɫ�_hp
void heal()
{
  if( query("hp")+500 < query("max_hp") )
  {
    message_vision(HIR"$N�}�U�����������E����$N�����W�C\n"NOR,this_object());
    add("hp",300+random(300));
    return;
  }
  return;
}

//�԰��ɨϦP�@�檱�a�N��
void do_combat_attack()
{
  object *inv,me,z;
  int i,damage;
  me=this_object();
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  if( !me->query_temp("weapon") && objectp(z=present("flame sword",me)) )
    command("wield sword");
  message_vision("\n$N"HIR"���W�������z�o�A�¥|�P���N�I\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      damage = random(50)+150-( inv[i]->query_shield() );
      if( damage > 0 )
      {
        message_vision(HIR"$N�Q���Ť��V�N�ӥ��ۡC\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        // �N��(burn)�g�n��,�N blooding ���� burn
        inv[i]->apply_condition("blooding", inv[i]->query_condition("blooding")+1);
      }
    }
  }
  return;
}

// �԰��ɪ��S��
int special_attack(object me, object target, int hitchance)
{
  object z;
  int ball,j;
  ball=random(4)+1; // �s�y 1~4 ���P�V�u
  if(!me) return 0;
  if( !me->query_temp("weapon") && objectp(z=present("flame sword",me)) )
    command("wield sword");
  if(me->is_busy()) return 0;

  if( !me->query_temp("weapon") ) //�S�Z���ɻs�y�����C
  {
    me->start_busy(2);
    message_vision("\n$N�k�⾮�E"HIR"�����P�V"NOR"�A�Φ��@��G����"HIR"�����C"NOR"�I\n"NOR,me);
    new(__DIR__"eq/flame-sword")->move(me);
    return 1;
  }
  else if(!random(5)) //�ϥΤ��V�@�����Ҧ��ͪ�
  {
    me->start_busy(2);
    message_vision("\n$N���⾮�E"HIR"�����P�V"NOR"�A�Φ��@�����Q�X����"HIR"���V�@"NOR"�I\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  else if(!random(5)) //�s�y�P�V�u
  {
    me->start_busy(2);
    message_vision(HIR"\n$N�g�q�@�n�A�i�f�R�X"+ball+"���P�V�u�I\n"NOR,me);
    for(j=0;j<ball;j++)
    {
      new(__DIR__"fire-ball")->move(environment(me));
    }
    return 1;
  }
  return 0;
}

// �S��--���V�@
void do_super(object me)
{
  object *inv;
  int i,damage,dex_r,block_r,parry_r;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision("\n$N"HIR"���ʤ⤤�����V�@�V�|�P�g���I�I\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      damage = random(200)+550-(inv[i]->query_shield())-(inv[i]->query_armor());
      if(damage < 0) damage=0;
      dex_r=random(inv[i]->query_dex());
      parry_r=random(inv[i]->query_skill("parry"));
      block_r=random(inv[i]->query_skill("block"));
      if( parry_r > 80 && inv[i]->query_temp("weapon") )
      {
        message_vision(HIG"$N�Τ⤤���Z���N���V�@������@�a�A�I�ǳQ���V�N��C"NOR,inv[i]);
      }
      else if( block_r > 80 && inv[i]->query_temp("armor/shield"))
      {
        message_vision(HIG"$N�ήɥH�޵P�w�O�צ���V�@�������A���V�@�P�޵P�����E�X���P�|�q�C"NOR,inv[i]);
      }
      else if( dex_r > 50 )
      {
        message_vision(HIR"$N�Q���V�@�y�L����A�y�� ("+damage/2+") �I���@�ˡI"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage/2, me);
        COMBAT_D->report_status(inv[i]);
      }
      else
      {
        message_vision(HIR"$N�Q���V�@���������A�y�� ("+damage+") �I���@�ˡI"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        COMBAT_D->report_status(inv[i]);
      }
    }
    else
    {
      message_vision(HIR"\n$N�b�@�����N�����u .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(2);
  return;
}

int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();
  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
    HIR"\n\t�i���s�q�|�j"HIW"�Ǩ���H�����G"+RED"���]��  "HIR"���Q�S"HIW"  ���Q "HIY""+ob->name(1)+HIW" ���h�F�I\n\n"+NOR
    ,users());
  ob->add("popularity",10);      
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);
  ::die();
  return;
}