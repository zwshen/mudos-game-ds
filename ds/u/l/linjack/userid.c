// #pragma save_binary
#define MUD_PORT __PORT__
#include <net/socket.h>
inherit F_CLEAN_UP;
static int remote_port;
object obj, temp;
int help();
void create()
{
        seteuid(getuid(this_object()));
}
int main(object me, string str)
{
        string socket, address;
        int port, socket_port, tmp;

        if( !str ) return help();

        obj = find_player(str);
        temp = previous_object();        socket = socket_address(obj);

        if( !obj ) return notify_fail("�S���o�Ӫ��a�C\n");
        if( !socket ) return notify_fail("��M���a address ���ѡT\n");
        if( sscanf(socket, "%s %d", address, port) != 2)
                return notify_fail("�Ǧ^ address �Ȧ��~�T\n");
        remote_port = port;
        socket_port = socket_create(STREAM, "none");

        if( socket_port < 0 ) return notify_fail("�إ� socket���ѡT\n");

        tmp = socket_connect(socket_port, address + " 113", "read_callback", "write_callback");
        write(tmp + "\n");

        if( tmp < 0 ) {
                socket_close(socket_port);
                return notify_fail("�s�� socket ���ѡT\n" + socket_error(tmp) + "\n");
        }
        return 1;
}
void write_callback(int socket_port)
{
        int error;
        error = socket_write(socket_port, remote_port + "," + MUD_PORT +"\n");
        if( error < 0 ) {
                socket_close(socket_port);
                tell_object(temp, "socket �ǰe��Ʀ��~�T\n" + socket_error(error) + "\n");
        }
}
void read_callback(int socket_port, mixed info)
{
        string tmp, machine, name, userid;

        if( !info || sscanf(info,"%s : USERID : %s :%s\r\n", tmp, machine, name) != 3 ) {
                socket_close(socket_port);
                tell_object(temp,  "socket ������Ʀ��~�T\n" + info + "\n");
                return;
        }
        tell_object(temp, obj->name() + "(" + capitalize(obj->query("id")) + ")�b" + query_ip_name(obj) + "���b�����R" + name + "\n");
        socket_close(socket_port);
}
int help()
{
        write(@HELP
���O�榡�Ruserid [�ϥΪ̩m�W]
�d�ߦb�u�W�ϥΪ̨�ӷ��ҨϥΪ��b������C (�ȥΦb�u�@���W)

HELP );
        return 1;
}

