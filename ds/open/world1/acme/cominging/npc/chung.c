#include <ansi.h>
#include <path.h>
inherit NPC;
void do_jail();
void create()
{
        set_name("�L�R", ({ "lin chung","lin","chung" }) );
        set("level", 40);
        set("race","�H��");
        set("gender","�k��");
        set("title",HIG"�T�x"+HIR+"�j����"NOR);
        set("age",50);
        set("long",
            "�L�N�O�W�D�ѤU���T�x�j�ΫӡA�@�ܤj���B��x���p�Z���몺�ʤj�A\n"
            "�������ӡA�Q�������Y�A���\\�O�T�x�j���ӡC\n");
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
                (:do_jail:),
        }) );   
        set("chat_chance", 8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("sky_city_war", 1);
        setup();
        set_living_name("skycitywar");
        carry_object(__DIR__"eq/armor2")->wear();
        carry_object(__DIR__"eq/ring")->wear();
        carry_object(__DIR__"wp/risword")->wield();
}
void init()
{
        ::init();
        if(!this_object()->visible(this_player())) return;
        if(this_player()->query("level") > 9 && userp(this_player()) )
        {
          this_object()->kill_ob(this_player());
        }
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
        ob->add("popularity",2); //�n��
        tell_object(ob,HIW"(�]���A�����F�L�R�A�ҥH�o��F 2 �I�n��)"NOR);
        ::die();
        //destruct(this_object());
        return;

}
void do_jail()
{
        int i,which;
        object *ppl;
        ppl = all_inventory(environment(this_object()));
        which = random(sizeof(ppl));
        switch(random(4)) {
                case 0: command("say ����I�I����N��a�I�I"); break;
                case 1: command("say �ϤF�ϤF�I�S�̡̭M���U�o�ӭ�{�I"); break;
                case 2: command("say �c��I�I���ڳo�ۡI�I"); break;
                case 3: command("say �j��̡I���U���ӥi�ê��å�I"); break;
        }
        if( !living(ppl[which]) ) which = random(sizeof(ppl));
        if( !userp(ppl[which]) ) return;
        i = ppl[which]->query_skill("dodge");
        if( i > random(120))
        {
                message_vision(HIW"\n$N�F�����סA�n���e�����L�F�L�R���e���A�o�]�y�F�����j���C\n"NOR,ppl[which]);
        }
        else {
                message_vision(HIW"\n$N�@�L�dı���L�R���Ө�A�L�R�N$N�����⦩���A$N�רs�Q�L�R�Ү��C\n"NOR,ppl[which]);
message("world:world1:vision",HIR"\n  "+ppl[which]->name_id(1)+"�j�s�G��}�ڡI�A�̧���H�աI�I\n\n"+NOR,users(),ppl[which]);
                message_vision(HIW"\n$N���|�P���X�F�G�өx�L�A�N$N��i�j�c�̤F�C\n"NOR,ppl[which]);
                ppl[which]->move(ACME_PAST+"cominging/superjail");
        }
}