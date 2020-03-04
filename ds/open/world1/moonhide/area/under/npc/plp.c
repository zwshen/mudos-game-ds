#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR"�]"NOR, ({ "devil" }) );
        set("long",@LONG
���~����b�a���U�A�P�ѧ��D�P�X�@��A�ͩʦn�j�A��ÿB
�����ͪ��A�u���u���v�o�ӿ�k�C 
LONG
);  
        set("gender", "�k��");  
        set("race", "�H��");
        set("attitude","aggressive");
        set("level",45+random(10));
        set("age",200+random(100));
        set("evil",-20);
        set("title",HIC"��"NOR); 
        set_skill("unarmed",120);
        set_skill("dodge",150); 
        set_skill("parry",100);       
        set_skill("combat",100);
        set("combat_exp",200000);
        set("max_exp",80000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/evil-armor-only")->wear();
     carry_object(__DIR__"obj/evil-spear")->wield();  
     //carry_object(__DIR__"obj/evil-eye");   
     carry_object(__DIR__"obj/evil-pants")->wear();
     carry_object(__DIR__"obj/evil-cloak")->wear();   
     //carry_object(__DIR__"obj/fire-fruit"); 
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        object me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0: 
                        message_vision(HIR"\n���]��������$N���ݤf��F�U�h�I\n"+NOR,me);
                        me->receive_damage("hp",300);
                        this_object()->kill_object(environment(me));
                        break;
                case 1: 
                        this_object()->kill_object(environment(me));
                        break;
        }
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision(HIR"\n$N"+HIW"�i�}����A�������E�@�Ѯ�l�E�E\n"     
                    +HIC"���X�I�I�y"+HIB"�����]�y"+HIC"�z�����a\n"
                    +HIC"���V$n�A�y��"+HIR"�I�������ˡI\n"+NOR,me,target);
      target->receive_damage("hp",400+random(150), this_object());
      return 1; 
    }
    else
    {
      message_vision(HIR"\n$N"+HIW"��M����"+HIG"�C��"+HIW"�A�f�������E���@�ѯ�q�E�E\n" 
                    +HIW"�Q�X�I�����ʪ�"+HIR"���V"+HIW"�L�����N�V$n�A\n"
                    +HIW"�y��"+HIR"�Y�����N�ˡI\n"+NOR ,me,target);      
      target->receive_damage("hp",300+random(100), this_object());
      return 1;
    }
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
HIG"\n\n\t\t"+ob->name(1)+""+HIY"�j��"+HIR"���]"+HIY"�Ʀʦ^�X�I\n\n" 
HIY"\n\n\t\t�b"+HIR"���]"+HIY"���g�N�������Iŧ�V��I�V�I\n\n"
MAG"\n\n\t\t���⪺����j�q«�X�I"+HIW"�}���ӳu���\n\n"+NOR,ob);
   //HIG"\n\t\t\t\t\t �����b�V���F�t�a�w�w�m��ù��n\n\n"+NOR
        ob->add("popularity",5);      
        if( random(8) ) 
                eqp=new(__DIR__"obj/fire-fruit");   
       else  if( random(2) )
                eqp=new(__DIR__"obj/devil-book");
        eqp->move(this_object()); 
            ::die();
        return;
}
