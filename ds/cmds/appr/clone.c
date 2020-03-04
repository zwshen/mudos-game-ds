// clone.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
        object obj;
        string err, msg;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("�A�n�ƻs���򪫥�S\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("�S���o���ɮ�(" + file + ")�C\n");

        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("���J���ѡR" + err + "\n");
                        return 1;
                }
        }

        err = catch(obj = new(file));
        if (err) {
                write("�ƻs���ѡR" + err + "\n");
                return 1;
        }

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "�u��$N�����Ť@���M�ܥX�F$n�C\n";

        if( !obj->is_character() && !obj->is_house() && obj->move(me) ) {
                write(obj->query("name") + "�ƻs���\\�M��b�A�����~��C\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
        if( wiz_level(me)<4 && obj->is_character() ) // ���M���ηN�A�令 open can't clone only.. �`�N random �]���۳N..
        {
                if( sscanf(base_name(environment(me)),"/open/%*s") == 1 )
                {
                        write("�A����b�}��ϰ��m�Ǫ��C\n");
                        destruct(obj);
                        return 1;
                }
        
        }

        if( obj->move(environment(me)) ) {
                write(obj->query("name") + "�ƻs���\\�M��b�o�өж��C\n");
                message_vision(msg + "\n", me, obj);
                return 1;
        }

        destruct(obj);
        return notify_fail("�L�k�ƻs���ಾ�ʪ�����(" + file + ")�C\n");
}

int help(object me)
{
  write(@HELP
���O�榡 : clone <�ɦW>

�Q�Φ����O�i�ƻs����ಾ�ʤ�����(�t�Ǫ�)�C
HELP
    );
    return 1;
}
