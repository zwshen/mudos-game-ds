#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�s��k",({"sky master","master"}));
  set("long",@LONG
�A�o�{���H���W���o�X�@�ص±�����, ��ӥL�N�O�ѱ��T�t���@,
�s��k! �ǻ����H���\\�w��ǩ_���Ҭ�, �Ӥ@���ѼS�P�k��O��
�V�L��, �G�Q�G�����~�N���g�@�H�W�����R����, �q���ФU�¦W
, �M�Ӧb�T�Q�������~�]���ѱ������ӤߦǷN�N, �����ӯ�Ф�
����Z�@��....

LONG
    );
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","�k��");
 set("level",35);
 set("title",HIR"�ѱ��T�t"NOR);
 set_skill("unarmed",55);
 set_skill("blade",65);
 set_skill("force",85);
 set_skill("parry",70);
 set_skill("sky-dagger",100);
 map_skill("dagger","sky-dagger");
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say ��! ":),
 }));
 setup();
 carry_object(__DIR__"eq/dragon_dagger")->wield();
 carry_object(__DIR__"eq/sky_cloth")->wear();
 carry_object(__DIR__"eq/sky_boots")->wear();
 carry_object(__DIR__"eq/sky_helm")->wear();
}