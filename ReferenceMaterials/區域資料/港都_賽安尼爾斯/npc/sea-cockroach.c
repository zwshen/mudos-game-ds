inherit NPC;

void create()
{
  set_name("�p����",({"small crab","crab"}) );
  set("long","�@������@�b�x�ߤj�p�����ɡA���b���ۤW�V���C\n");
  set("race", "���~");    
  set("unit","��");
  set("age",1);
  set("level",3);
  set("attitude", "heroism");  
  set("limbs", ({ "�Y��", "����", "�k�g", "���g" }) ); 
  set("verbs", ({ "bite" }) );         
  set("chat_chance", 5);
  set("chat_msg", ({
      "�����䴧�R���g�@��R�۪w�j�C\n",
     }));              
  setup();
}