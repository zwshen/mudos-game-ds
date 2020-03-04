// �������ɤ��N -Luky-
//

#define WALLNAME "��������"

#include <ansi.h>
#include <obj.h>
inherit SKILL;

int cast(object me, object target,string dir)
{
    int delay,sk;
    if( !target ) return notify_fail("�A�������w�@�Ӥ�V�~��I�i�����ɳN�C\n");

    if( !target->is_room())
        return notify_fail("���k�N�u��Ω�ж��C\n");
    if( living (target) )
        return notify_fail("���k�N����Ω�ͪ��W�I\n");
    if( environment(me)->query("no_magic") )
        return notify_fail("�o�Ӧa�褣�i�H�I�k�I\n");
    if( environment(me)->query_temp("wall/"+dir))
        return notify_fail("�o�Ӥ�V�w�g�����ɤF�I\n");
    if((int)me->query("mp") < 50 )
        return notify_fail("�A���k�O�����T\n");

    if( me->is_busy() )
        return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
    sk=me->query_spell("lightwall");
    if(sk>70) delay=2+random(3);
    else if(sk>35) delay=3+random(3);
    else delay=4+random(3);
    me->add("mp", -50);
    me->start_busy(delay);
    message_vision("\n[1;35m$N���V"+to_chinese(dir)+"���|����... �}�l�I�i�������N...[0m\n\n",me);
    call_out("do_wall",delay,me,target,dir);
    return 1;
}

int do_wall(object me, object target,string dir)
{
    object env,wall1,wall2;
    string msg,other_dir,*exit,*dirs,file;
    mapping exits;
    int i,time,sk;

    if(!me) return 0;
    if(!env = environment(me) ) return 1;
    if( env->query("no_magic") )
    {
        tell_object(me,"�o�Ӧa�褣�i�H�I�k�I\n");
        return 1;
    }
    if( env->query_temp("wall/"+dir))
    {
        tell_object(me,"�o�Ӥ�V�w�g�����ɤF�I\n");
        message_vision("$N���������ɳN�I�i�ŧi���ѡC\n",me);
        return 1;
    }
    sk=me->query_spell("lightwall");
    if( random(30+sk/2+me->query_int()) < 30 || random(10)==1)
    {
        message_vision("$N���������ɳN�I�i���ѤF�C\n",me);
        me->improve_spell("lightwall",1+random(me->query_int()/4));
        return 1;
    }
    time = sk*2+me->query_int()*5;
    if(time>300) time=300;
    wall1 = new(WALL_LIGHT);
    wall1->set("level",random(sk/2));
    wall1->move(env);
    wall1->set("dir",dir);
    call_out("break_wall",time,wall1);
    env->set_temp("wall/"+dir,wall1);
    tell_room(env,"��M���@�}�j��, �A�ݨ줭�D�����ʦ��F"+to_chinese(dir)+"���X�f�I\n");
    exits = target->query("exits");
    if(mapp(exits))
    {
        file = base_name(env);
        dirs = keys(exits);
        exit = values(exits);
        for(i=0;i<sizeof(exit);i++)
        {
            if(exit[i]==file)
            {
                wall2 = new(WALL_LIGHT);
                wall2->set("level",random(sk/2));
                wall2->move(target);
                wall2->set("dir",dirs[i]);
                call_out("break_wall",time,wall2);
                target->set_temp("wall/"+dirs[i],wall2);
                tell_room(target,"��M���@�}�j��, �A�ݨ줭�D�����ʦ��F"+to_chinese(dirs[i])+"���X�f�I\n");
            }
        }
    }
    wall1->set("link_wall",wall2);
    wall2->set("link_wall",wall1);
    me->improve_spell("lightwall",1+random(me->query_int()/4));
    return 1;
}

int break_wall(object wall)
{
    if(!wall) return 0;
    if(environment(wall))
    {
        tell_room(environment(wall),"�������ɶ}�l�ܱo�z���ӳv�������F�I\n");
        environment(wall)->delete_temp("wall/"+wall->query("dir"));
        destruct(wall);
    }
    return 1;
}