// �����Ū��Z�� update by Tmr 2006/06/07
// fixed bug update by whoami 2007/03/22
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void sword_check();
void create()
{
    set_name(HIC"��"HIR"��"HIW"���C"NOR,({"yin-yang longsword","sword","longsword"}));
    set("power", 1);
    set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A�C�b���a�観�۵�\n"
            "�����H��A�H�𪺥~��o�S�]��F�@�h�x��A�J�⤧��A�O�H��\n"
            "���@�_�C\n");
    set("wield_msg","$N�q�I���X�@��$n�A�u��$N���ǳ�¶�ۤ@�ѳ����թM����C\n");
    set("unwield_msg","$N��U�⤤��$n�A�N$n���J�I�᪺�C�T���C\n");

    set_weight(17000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value",5000);
        set("material","blacksteel");
    }
        set("limit_str",40);
        set("limit_int",40);
        set("limit_dex",60);
        set("limit_level",47);
        set("weapon_prop/bar", -1);
        set("weapon_prop/bio", -1);
        set("weapon_prop/wit", 1);
        set("weapon_prop/int", 2 );
        set("weapon_prop/dex", -2);
        set("weapon_prop/hit",15);
    init_sword(40);
    setup();
}

void attack(object me,object victim)
{
        object ob =this_object();
    int ap;

    ::attack();
    if(!me) return;
    if(!victim) return;
    if( me->is_busy() ) return;
    if( random(100) > 10 ) return;


        ap = random(me->query("max_ap")*11/50);
    message_vision(HIG"\n$N"HIG"�⤤��$n"HIG"�o�X�@�ѷŷx���𮧡A��$N"HIG"�����l�b�c�����������ϤɡC\n\n"NOR,me,ob);
    me->receive_heal("ap",ap);

    return;
}
