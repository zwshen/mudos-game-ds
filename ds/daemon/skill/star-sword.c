// Tmr refactoring/�վ�j�� 2006/11/25
// �[�W�����C�}���v�T - tmr

#include <ansi2.h>
#define SKILL_NAME "�_��C�P�C�Z"

inherit SKILL;
inherit SSERVER;

void delay_0(object me);
void stop_delay(object me);

mapping *action = ({
    ([
    "action": "$N�}�C�@���A���O��i�C���A�ϥX�u"HIC"�ѼϦ�"NOR"�v�C�ۡA�C�۬������檽���i",
    "damage":   25,  //�o�ӬO�ˮ`�j�ƪ��ʤ��� , ���O�ˮ`�I��
    "attack":   10,
    "attact_type":  "bio",  // �]�w�ޯ઺�������� // �ͪ�(bio) �~��(bar) �]�k(wit)���F(sou)���(tec)
    "damage_type":  "���",
    ]),
    ([
    "action": "$N���C���I�C�U�C�~�A�����_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u��梦�"NOR"�v�W�V$n��$l",
    "damage":   15,
    "dodge":    -5,
    "delay":    1,
    "attack_type":      "bio",
    "damage_type":      "���",
    ]),
    ([
    "action": "$N������i�A��M�X�{�b$n���ǡA��$n$l��X�@�C�u"HIC"�ѿY��"NOR"�v",
    "damage":   18,
    "delay":    2,
    "attack_type":      "bio",
    "damage_type":      "���",
    ]),
    ([
    "action": "$N�ϥX�C�۫i�r���u"HIC"���v��"NOR"�v�A��$n��$l�s��X�T�C�A�@�C��@�C�ٱj",
    "damage":   25,
    "delay":    2,
    "attack_type":      "bio",
    "damage_type":      "���",
    ]),
    ([
    "action": "$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n��$l�ϥX�@�ۡu"HIC"�ɿŦ�"NOR"�v"NOR,
    "damage":   30,
    "attack_type":      "bio",
    "damage_type":      "���",
    ]),
    ([
    "action": "$N�ϥX�u"HIC"�}����"NOR"�v�A�⤤$w"NOR"�ɥX�C�B�A�ɼC�B���ϷӡA�f��$n�������A���۹�$n��$l��X�@�C",
    "damage":   30,
    "attack_type":      "bio",
    "damage_type":      "���",
    ]),
    ([
    "action": "$N�u"HIC"�n����"NOR"�v�@�X�A�⤤$w"NOR"�ɰ_�@�Υ��B�A�E�g�����A��$n���������D�o�@�C�|�Ѧ����",
    "damage":   30,
    "attack_type":      "bio",
    "damage_type":      "���",
    ]) ,
});

int cast_skill(object me,string a, object target, string arg)
{
    int sk, force, w_force;
    int total_damage;
    int target_armor, me_damage, target_dodge, me_dex, sum_damage, g,damage;
    object weapon, *attack_targets;
    object field; // �C�}
    string msg;

    if ( arg=="off" )
    {
        if ( me->query_skill_mapped("sword")!="star-sword" )
            return notify_fail("�A�èS���b��"SKILL_NAME"��I\n");
        me->map_skill("sword");
        me->reset_action();
        write("�A����ϥ�"SKILL_NAME"�F�C\n");
        return 1;
    }

    if ( me->query("ap") < 30 )
        return notify_fail("�A���骺���p�٤���ϥ�"SKILL_NAME"�C\n");

    if ( me->query_skill("sorgi_sword") < 70 ) return notify_fail("�A�������C�k�٤����¼��A�����"SKILL_NAME"�A�_�h�N�������J�]�I\n");

    weapon = me->query_temp("weapon");
    if ( !weapon ) return notify_fail("�A�����n���C�~��ϥΡC\n");
    if ( weapon->query("skill_type")!="sword" )
        return notify_fail("�A�����n���C�~��ϥΡC\n");

    if ( arg == "?" || arg == "help" ) {
        tell_object(me, SKILL_NAME + "���\\�঳ �C�B(rain) �C��(vigor) �C�߳q��(brightly_heart)�C\n" NOR);
        return 1;
    }

    if ( me->query_skill_mapped("sword") == "star-sword" )
    {
        if ( !target ) target = offensive_target(me);
        if ( !target ) return notify_fail("�A�S���i�H�������ؼСC\n"); // �� by cominging
        if ( !me->can_fight(target) ) return me->can_fight(target);

        sk = me->query_skill("star-sword");
        force = me->query_skill("force");
        w_force = me->query_skill("moon_force");

        target_armor = target->query_armor();
        target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);

        me_dex = me->query_dex() * 3;
        me_damage = me->query_damage() + w_force/4 + sk/3;
        me_damage = me_damage + random(me_damage/4);

        sum_damage = me_damage - target_armor/2 - random(target_armor/2);
        // qc section
        // if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
        // end of qc section

        if ( arg == "rain" )
        {
            if ( !me->is_fighting(target) ) me->kill_ob(target);
            if ( !target->is_fighting(me) ) target->kill_ob(me);
            if ( me->is_busy() ) return notify_fail("�A�����ۡA�S���ŧ����C\n");
            if ( me->query_skill("star-sword") < 30 )
                return notify_fail("�A��"SKILL_NAME"�ݭn30�Ť~��ϥΡu�C�B(rain)�v�C\n");

            message_vision( HIC "\n$N�ʰʼC��A�C�B�ߧY���d�d�U�U���ä��ΡA�Φ��O�������멹$n"HIC"���ֹL�h�I�I\n" NOR, me, target);
            me->receive_damage("ap", 50);
            me->start_busy(1);
            if ( random(me_dex) > random(target_dodge) )
            {
                sum_damage = me->query_damage()*2 + sk/3 - random(target_armor/2) - target_armor/2;
                if ( sum_damage < 1 ) sum_damage = 10;
                sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage, "bio");

                target->receive_damage("hp", sum_damage, me);
                message_vision(HIR"$n"HIR"�����}���Ѽ��Ӫ��C�k�A���W�ƳB�n�`���C�A�Q�X�Ƥf�A��C"NOR, me, target);

                me->improve_skill("star-sword", random(me->query_int()) );
                me->improve_skill("sword", random(me->query_int()) );
                weapon->attack(); // wp �l�a�v add by wilfred
            }
            else
            {
                message_vision(CYN"�i�O$n"CYN"�P����F$N���U�ۦU���A�@�@�Ƹѱ��F�C"NOR, me, target);
                sum_damage = 0;
            }
            if ( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
            else message_vision("\n\n", me);
            COMBAT_D->report_status(target);
            return 1;
        }

        if ( arg == "vigor" )
        {
            if ( !me->is_fighting(target) ) me->kill_ob(target);
            if ( !target->is_fighting(me) ) target->kill_ob(me);
            message_vision(HIY "\n$N�⤤"+weapon->query("name") + HIY "�o�X��l��ۮɿW�������E�T�A�����b�����C�@�o�Ŷ��̡C\n\n"NOR, me, target);
            message_vision(HIG "$n"HIG"�ͥX��ı�A�N�Y$N"HIG"�ˤU�F�䥦�H�A���O�V�ۤv��ӡC\n"NOR, me, target);

            if ( random(target->query_dex()) < random(me->query_dex()*3/2) )
            {
                message_vision(CYN"$N"CYN"�@�ɤ������������D�p������C\n"NOR, target);
                weapon->attack(); // wp �l�a�v add by wilfred
                if ( sk < 30 ) target->start_busy( 1) ;
                if ( sk > 30 && sk < 60 ) target->start_busy( 2 );
                if ( sk > 60 && sk < 90 ) target->start_busy( 3 );
                if ( sk >= 90 ) {
                    target->receive_damage("hp", me->query_damage()/3, me);
                    message_vision(HIR"$N"HIR"���ߨ��СA�����F���������ˡI"NOR, target);
                    target->start_busy(3);
                }
                if ( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                    message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                else message_vision("\n", me);
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision(CYN "���O$N"CYN"����ı�N�L�Ԧ^�{��A���}�F�o���������C\n"NOR,target);
                me->add_busy(random(2));
            }
            me->receive_damage("ap", 60);
            me->start_busy(1);
            return 1;
        }

        if ( arg == "brightly_heart" )
        {
            if ( me->query("level") < 35 )
                return notify_fail("�A���⪺���Żݭn�����šC\n");
            if ( me->query_skill("moon_force") < 90 )
                return notify_fail("�A���ݤ�ߪk�ݭn�����šC\n");
            if ( me->query_skill("star-sword") < 90 )
                return notify_fail("�A��"SKILL_NAME"�ݭn�����šC\n");
            if ( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
            if ( !me->is_fighting() )
                return notify_fail("�A�S�b���[, �ҥH����μC��I\n");
            if ( !arrayp(attack_targets = me->query_enemy()) )
                return notify_fail("�A�S���i�H��������H�C\n");
            if ( me->query("ap") < 200 )
                return notify_fail("�A�����l�����A�L�k�ϥμC�߳q���C\n");
            if ( me->query_temp("wind_brightly_heart") )
                return notify_fail("�A�u�ɶ����ٵL�k�ϥμC�߳q���C\n");
            msg =  HIW "\n$N"HIW"�C�߳q���������X�C�C�A�u����v�n�����p�\\���������A���L�שλ��έ��A\n"
                   "�C�@�C����$n"HIW"���l��ۡA��$n"HIW"�L�k�⨭��h�I�I�I\n\n" NOR;
            message_vision( msg, me, target);
            if ( objectp(field = present("_INDICATE_KNACK_FIELD_", environment(me))) ) {
                // �C�} - �C�C�X�@�C
                message_vision( HIG"$n"HIG"�t�X$N"HIG"���C�߳q���A�o�X���p"HIY"�s�u��S"HIG"�몺���T�C\n"NOR, me, field);
                total_damage = 0;
                for (g=0;g<7;g++) {
                    if (  target->is_busy() || random( target->query_dex() ) < random( me->query_dex()*2 ) + 15 ) {
                        damage = me->query_damage()*2/3 + field->query("damage") * field->query("power")/100;  // �C�}�B�~�����O
                        damage = COMBAT_D->Merits_damage(me, target, damage , "bio");
                        total_damage += damage;
                        message_vision(HIC"$N"HIC"��פ����Q�����뤤�n�`�A�����Q�G���g�߳����쭫�C�I\n"NOR,target);
                    } else {
                        message_vision(YEL"$N"YEL"���L�F�o�@�C�I\n"NOR,target );
                        target->start_busy(1);
                    }
                }
                if (total_damage>0) { // �y���ˮ`
                    message_vision(HIR"�L�μC��b$N"HIR"�餺�g�߬y«�A�y���Y��������(" + total_damage +")�I\n"NOR,target);
                    target->receive_damage("hp", total_damage , me);
                    COMBAT_D->report_status(target);
                }
            } else {
                // �L�C�} - �C�C���}��
                for (g=0;g<7;g++) {
                    if (  target->is_busy() || random( target->query_dex() ) < random( me->query_dex()*2 ) + 15 ) {
                        damage = me->query_damage()/2 + random(w_force/4);
                        damage = COMBAT_D->Merits_damage(me, target, damage , "bio");
                        if ( random( target->query_skill("force")/2 ) > random(force) ) {
                            damage /= 2;
                            message_vision(CYN"$N"CYN"�ĤO�����A�w�O���U�F�o�@�C�I"HIR" ("HIW+damage+HIR")"NOR,target);
                            target->receive_damage("hp", damage, me);
                            COMBAT_D->report_status(target);
                        } else {
                            target->receive_damage("hp", damage , me);
                            message_vision(HIC"$N"HIC"���Ω�סA�Q�o�@�C�뤤�n�`�I"HIR" ("HIW+damage+HIR")"NOR,target);
                            COMBAT_D->report_status(target);
                        }
                    } else {
                        message_vision(YEL"$N"YEL"���L�F�o�@�C�I\n"NOR,target );
                        target->start_busy(1);
                    }
                }
            }
            me->start_busy(2);
            me->receive_damage("ap", 60);
            weapon->attack(); // wp �l�a�v
            target->start_busy(1);
            message_vision("\n",me);
            me->set_temp("wind_brightly_heart", 1);
            call_out("stop_delay", 12 , me);
            return 1;
        }
    }
if ( !me->skill_active( "star-sword",(: call_other, __FILE__, "delay_0", me :), 6) )
        return notify_fail("�A����"SKILL_NAME"���ʧ@�٨S�����I\n");

    message_vision(HIY"$N���[�|��M��ť�K��M�߾��N�b�M������|"SKILL_NAME"�I\n"NOR,me);
    me->map_skill("sword", "star-sword");
    me->receive_damage("ap", 10);
    me->reset_action();
    me->start_busy(1);
    return 1;
}

void delay_0(object me)
{
    object me_weapon;

    if ( !me ) return;

    me_weapon=me->query_temp( "weapon" );

    if ( !me_weapon || me_weapon->query("skill_type") != "sword" )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }

    if ( me->query_skill_mapped("sword")!="star-sword" ) return;

    if ( me->query("ap") < 10 )
    {
        me->map_skill("sword");
        me->reset_action();
        tell_object(me, "�A����O�����A�L�k�~��ϥ�"SKILL_NAME"�F�C\n");
        return ;
    }

    if ( me->is_fighting() ) me->receive_damage("ap", 7);

me->skill_active( "star-sword",(: call_other, __FILE__, "delay_0", me :), 6);
}

void stop_delay(object me)
{
    if ( !me ) return;
    me->delete_temp("wind_brightly_heart");
    tell_object(me, "�A�S��_�C�߳q���F�C\n");
}

int valid_learn(object me)
{
    return 1;
}

/*
mapping query_action(object me, object weapon)
{
        if( me->query_skill("star-sword") == 100 && !me->query_skill("sevenstar-sword"))
        {
                if( random(me->query("level")) == random(me->query_skill("star-sword")) )
                {
                        me->set_skill("sevenstar-sword", 1);
                        tell_object(me, HIW+BEEP"\n�A����F�ҵo�A�m���F�s�ޯ�-[���C�P�C�q (sevenstar-sword)]�C\n\n"NOR);
                }
        }
        return action[random(sizeof(action))];
}
*/

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object ob)
{

    return 100;
}
/*
void skill_improved(object me)
{
        if( me->query_skill("sevenstar-sword") )
        if( me->query_skill("sevenstar-sword") )
        {
                me->set_skill("sevenstar-sword", me->query_skill("sevenstar-sword")-1 );
              tell_object(me, HIW"�]���A�m�^"SKILL_NAME"�A�ҥH�A���p�ߧѰO�F�@���������C�P�C�q�C\n\n"NOR);
        }
}
*/
mapping query_action(object me, object weapon)
{
    /*
        if( me->query_skill("star-sword") == 100 && !me->query_skill("sorsin_force"))
        {
            if( random(me->query("level")) == random(me->query_skill("star-sword")) )
            {
                me->set_skill("sorsin_force", 1);
                tell_object(me, HIW"�A��M�⮩��"SKILL_NAME"�������A�P�����C�k�δݤ�ߪk�ķ|�e�q�A�гy�X�s���Z��[���P���q(Sorsin_force)]�C\n\n"NOR);
            }
        }
    */

    return action[random(sizeof(action))];
}

