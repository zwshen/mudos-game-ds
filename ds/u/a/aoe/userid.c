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

        if( !obj ) return notify_fail("沒有這個玩家。\n");
        if( !socket ) return notify_fail("找尋玩家 address 失敗﹗\n");
        if( sscanf(socket, "%s %d", address, port) != 2)
                return notify_fail("傳回 address 值有誤﹗\n");
        remote_port = port;
        socket_port = socket_create(STREAM, "none");

        if( socket_port < 0 ) return notify_fail("建立 socket失敗﹗\n");

        tmp = socket_connect(socket_port, address + " 113", "read_callback", "write_callback");
        write(tmp + "\n");

        if( tmp < 0 ) {
                socket_close(socket_port);
                return notify_fail("連結 socket 失敗﹗\n" + socket_error(tmp) + "\n");
        }
        return 1;
}
void write_callback(int socket_port)
{
        int error;
        error = socket_write(socket_port, remote_port + "," + MUD_PORT +"\n");
        if( error < 0 ) {
                socket_close(socket_port);
                tell_object(temp, "socket 傳送資料有誤﹗\n" + socket_error(error) + "\n");
        }
}
void read_callback(int socket_port, mixed info)
{
        string tmp, machine, name, userid;

        if( !info || sscanf(info,"%s : USERID : %s :%s\r\n", tmp, machine, name) != 3 ) {
                socket_close(socket_port);
                tell_object(temp,  "socket 接收資料有誤﹗\n" + info + "\n");
                return;
        }
        tell_object(temp, obj->name() + "(" + capitalize(obj->query("id")) + ")在" + query_ip_name(obj) + "的帳號為﹕" + name + "\n");
        socket_close(socket_port);
}
int help()
{
        write(@HELP
指令格式﹕userid [使用者姓名]
查詢在線上使用者其來源所使用的帳號為何。 (僅用在工作站上)

HELP );
        return 1;
}

