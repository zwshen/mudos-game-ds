#include <ansi.h>

inherit NPC;

void create()
{
    set_name(HIY "�p�s�k" NOR,({"dragon girl","girl"}) );
    set
        ("title",HIC "�j��" NOR);
    set
        ("long",
                "�p�s�k�O�׫n�s�����H�ӥD�H���@�A�������p�P�k�U�Z�A���A�u���C\n"
                "�~���ɴN�P���L�s�{�\\�h�W���A�o�[�`�o�̩��������N���¡A�ۻP���L����\n"
                "�ҩd����A�Y�`�~�j�Ӧܤ��C"
        );
    set
        ("race", "human");
    set
        ("unit","��");
    set
        ("age",45);
    set
        ("level",40);
    set
        ("gender","�k��");
    set
        ("max_ap",4100);
    set
        ("combat_exp", 500000);
    set
        ("attitude", "heroism");
    set
        ("limbs", (
                    { "�Y��", "����","�ݳ�","�ⳡ","�}��"
                    }
                ) );
    add
        ("addition_armor",250);
    add
        ("addition_damage",200);
    set
        ("chat_chance_combat", 50);
    set
        ("chat_msg_combat", (
                    {
		                (: command("exert girl-sword") :),
		                (: command("exert girl-sword") :),
                                (: command("exert girl-sword") :),
                                (: command("wield sword") :),
                            }
                        ));
    set_skill("girl-sword",100);

    setup();
    carry_object(__DIR__"sword3")->wield();
      carry_object("/open/world1/moonhide/area/under/npc/obj/fire-fruit.c");
    carry_object(__DIR__"key2");
}

int special_attack(object me,object target,int hitchance)
{
    int tdex, dmg;
    if(!me || !target)
        return 0;
    if(random(10)<6)
        return 0;
    tdex = target->query_dex();
    if(random(hitchance*20) > tdex )
    {
        dmg=query_damage()/2 + random(query_damage());
        message_vision(HIW"\n$N"+HIW"���X�ɸ��ߡA�B�_���O�G�X�}�}�����A����V�ѪŤ񹺤F�ƤU�C\n"
                       +HIY"��M�ƤQ���ɸ��q�����䭸�ӡI�I\n"
                       +HIM"$nݳ���Y�����}�ɸ��������A�o�X�@�}�G�s�n�A���Y���O�]�A�ʩR���~�I�I�I("+ dmg +")\n" NOR,me,target);
        
          target->receive_damage("hp", dmg, this_object());
        return 1;
    }
    return 0;
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
    message("world:world1:vision",
              HIR"\n�i�����H�ӡj"HIY "�u�ڡ���v�p�s�k�b�{�����e��"+ob->name(1)+HIY"�o�X�F�X�n�s�z�C\n\n"+NOR
            ,users());
    ob->add
    ("popularity",2); //�n��
    // �P�H�C�R
    if(ob->query_temp("gumu_sword")==1) {
        "/open/world1/tmr/gumu/xuanya.c"->open_sword();
        ob->delete_temp("gumu_sword");
        message_vision("�A�n��ı�o�N������_�����Ʊ��n�o�ͤF�C\n",ob);
    } else {
        ob->set_temp("gumu_sword", 2);
        }
    ::die();
    return;
}
