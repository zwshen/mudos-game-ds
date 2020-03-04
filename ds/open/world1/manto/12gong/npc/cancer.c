inherit NPC;
#include <ansi2.h>;

void haltbusy()
{
       if( random(3) ) return;
       message_vision("$N�B�W�������o�X�}�}���~�X���}�ӡC\n",this_object());
       message_vision("$N�����߱q���w��_�F�L�ӡC\n",this_object());
       this_object()->add_busy(-5);
       return;
}

void powerup()
{
        if( !this_object()->query_temp("pill") ) return;
        if( this_object()->query("hp") >  this_object()->query("max_hp")/2 ) return;
        if( random(2) ) message_vision("$N�j�ܡG����R�A�礩�ڤO�q�a�I\n", this_object());
        else message_vision("$N�j�ܡG�p�t�z�I�z�o�a�I\n", this_object());
        this_object()->receive_heal("hp",query("max_hp")/2);
        this_object()->receive_heal("mp",query("max_mp")/2);
        this_object()->receive_heal("ap",query("max_ap")/2);
        this_object()->clean_condition();
        COMBAT_D->report_status(this_object());
        this_object()->add_temp("pill",-1);
        return;
}

void create()
{
        set_name(HIG"�����S����"NOR, ({"artemis"}));
        set("long", "�ǻ��������y�k���Ъ����S�����A�u�@�ۥ��ɮy�C\n");
        set("gender","�k��");
        set("title", HIG"�i���y�k���j"NOR);
        set("level", 55);
        set("age",26);
        set("attitude", "friendly");
        set("race","nightelf");

        set("chat_chance_combat",80);
        set("chat_msg_combat",({
            //(: command("do wield sword,exert xxx"):),
            //(: command("exert xxx"):),
            (: powerup :),
        }));
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("bow", 200);
        set_skill("doubleshoot", 100);
        
        map_skill("bow","doubleshoot");

        set("max_hp", 28000);
        set("max_mp", 7000);
        set("max_ap", 5500);
        
        set_temp("pill", 3);
        set_temp("fly",1);
        set_temp("apply/damage",200);
        set_temp("apply/shield",50);
        set_temp("apply/armor", 290);
        set_temp("apply/hit", 70);
        set_temp("apply/dodge", 50);
        set("addition_armor", 50);

        setup();
        set_temp("apply/bio", 7+random(3));
        set_temp("apply/bar", -1);
        set_temp("apply/wit", -3);
        set_temp("apply/sou", -4);
        carry_object(__DIR__"wp/typhon_bane")->wield();
}

int special_attack(object me, object target, int hitchance)
{
    if(!me) return 0;

     switch(random(4))
     {
        case 0:
        {
        message_vision(HIC"$N���X���I��F�X�n�A�|�P���O�L���X�{�F�j�峥�~��$n�ĥh�I\n",me,target);
        if(random(2))
                {
              message_vision(HIC"$N�Q���F�ӱ��⤣�ΡA���ηn�̱��Y�I"HIR"("+query("max_mp")/10+")\n"NOR,target,me);
              target->receive_damage("mp",query("max_mp")/10);
            COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
               me->start_busy(1);
                }
        else
        message_vision(HIG"$N�@�n�����A���}�F�o�j���~��I\n"NOR,target);
        }
        break;
        case 1:
        {
         message_vision(HIC"$N����ѪšA�@����멿�M�X�{�b$n�����e�I\n",me,target);
        if(random(2))
                {
                message_vision(HIC"�o���Ȥ볺�W�Q�L��A$N�����W�Q���F�@�j��f�I"HIR"("+query("max_ap")/10+")\n"NOR,target);
                target->receive_damage("ap",query("max_ap")/10);
                COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
               me->start_busy(1);
                }
        else
        message_vision(HIC"$N���פήɡA�Ȥ�b�a�W�Y�X�F�@�D�����C\n"NOR,target);
        }
        break;
        case 2:
        {
        message_vision(HIR"$N�ֳt�a��$n�g�X�X���ë����b�I\n",me,target);
                if(random(2)==0)
                {
                message_vision(HIR"$N���פ���A�Q�ë����b�������}��ӹL�I"HIR"("+3*query("max_ap")/20+")\n"NOR,target);
                target->receive_damage("mp",3*query("max_mp")/20);
                target->receive_damage("ap",3*query("max_ap")/20);
                COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
               me->start_busy(1);
                }
        else
        message_vision(HIR"$N�⦣�}�ëj�j���}�F�b�ڡI\n"NOR,target);
        }
        break;
  }
        return 0;
}
// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
        object sw;

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( !objectp(who) ) return damage;
        if( environment(this_object()) != environment(who) ) return 0;
        if( objectp(who) && type=="hp")
        set_temp("last_damage_from", who);
        sw=who->query_temp("weapon");
        
        haltbusy();
        
        if(random(100)<45)
        {
            damage=1;
            if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 30 ) 
            {
                sw->unequip();
                message_vision(HIY"\n�����S�����j�ܤ@�n�A$N"HIY"�y�ɳQ�媺�⤤�@Ÿ�A�ȴ����p�����խ���$n�C\n" NOR,who,sw);
                message_vision(CYN "($N�渨�F��W���Z���F�C)\n" NOR,who,sw);
            } if(random(100) < 60 ) {
                message_vision(HIY "\n�����S�������W���Ҫx�X����_���]���A$N"HIY"���e�@��A�w�Q�������h���C\n" NOR,who);
                who->start_busy(1);
            } else {
                message_vision(HIM "\n$n"HIM"�J�M�o�{�A��~��⪺���M�O�]�k�ۼv�C\n" NOR,this_object(),who);
            }
        }

        if(objectp(who) )
                ::receive_damage(type,damage,who);
        else
                ::receive_damage(type,damage,who);
        return damage;
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
        ob->start_busy(3);
        message("channel:chat",HIY+"�i�����Q�G�c�j"HIC"����R(Athena)�G"+ob->name()+
        "���L�F"+environment(this_object())->query("short")+"\n"NOR,users());
        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        //ob->set("12gong/libra","done");
        //ob->add("12gong/libra",1);
        //ob->set("title",HIW"�ѩW�y�Ԥh"NOR);
        //ob->save();
        }
        if( !ob->query_temp("kill_12gong") ) ob->set_temp("kill_12gong", 1);
        ::die();
        return;
}