#include <ansi.h>

inherit NPC;
inherit __DIR__"zombiekill";

void create()
{
        set_name(CYN "���" NOR ,({"lost zombie","zombie"}) );
        set("long",@LONG
��ͷPı�ˤl�Q���N�šA�ʧ@�D�`�F���A���W�u�a�ۥ����ʡC���
���L�ͤ��@�ѵ����ͭx��������Ԫ�����A�]����~���쭫���A����
�����A�԰���O�]�ܱj�C
LONG
);
        set("age",60);
        set("race","�H��");
        set("title","�ͱN");
        set("level",35);
        set("attitude", "peaceful");
        add("addition_armor",80);
        set("gender", "�k��" );
        set("chat_chance",5);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (: zombie_heal,this_object() :),
                (: zombie_bite,this_object() :), 
        }));                 set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",100);
        set_skill("staff",100);
        setup();
       carry_object(__DIR__"../wp/lost_staff")->wield();
       set_living_name("zombie-war-mob");
       set("actions", (: call_other, __FILE__, "query_action" :));
}

 mapping query_action()
{
        return s_action[random(sizeof(s_action))];
}
void init()
{
        ::init();

if(this_player()->query("level") > 20 && userp(this_player() ) && this_object()->visible(this_player()))
        {
    message_vision("\n$N"+NOR+"�@�ݨ�$n�K���X���������I�I\n" NOR,this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
        return;
}
void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }

        ob->add("zombie_kill_war",1);
          if(ob->query("zombie_kill_war") > 2 )
        {
                tell_object(ob,HIG"�A�o��@�I�n��C\n" NOR);
                ob->add("popularity",1); //�n��
                ob->set("zombie_kill_war",0);
        }
        ::die();
        return;
}





