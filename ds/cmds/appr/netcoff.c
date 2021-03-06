// 格式: netcoff -a <ip> <name> 增加 -d <ip> 刪除 -l 列表 (-q 查驗線上使用者 not ok)
// created by Cominging 2000.11.15
#include <ansi.h>

int help(object me);

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        string hname, ip, i1, i2, i3, i4;
        int flag;

        if( !arg ) help(me);
        else if( sscanf(arg, "-a %s %s", ip, hname) == 2 )
        {
                if( sscanf(ip, "%s.%s.%s.%s", i1, i2, i3, i4) != 4 )
                        return notify_fail("網路咖啡廳 ip 位置錯誤！\n");
                if( !hname )
                        return notify_fail("請在 ip 位址後加入此網站名稱！！\n");
                flag = IP_D->add_ip(ip,hname);
                if( flag == 1 ) return notify_fail("已有此 ip 或者是網咖名字, 如果是名字重覆, 試著在後加 #1 #2 #3....\n");
                else if( flag == 2 )
                {
                        write(HIC"※ "+ip+" "+ hname + "增加成功\ ！\n"NOR);
                        return 1;
                }
                else return notify_fail("指令格式錯誤！\n");
        }
        else if( sscanf(arg, "-d %s", ip) == 1 )
        {
                if( sscanf(ip, "%s.%s.%s.%s", i1, i2, i3, i4) != 4 )
                        return notify_fail("所要刪除網路咖啡廳 ip 位置錯誤！\n");
                flag = IP_D->delete_ip(ip);
                if( flag == 1 ) return notify_fail("資料中並無此 ip 紀錄! \n");
                else if( flag == 2 )
                {
                        write(HIY"※ "+ ip + " 刪除成功\ ！\n"NOR);
                        return 1;
                }
                else return notify_fail("指令格式錯誤！\n");
        }
        else if( arg == "-l" )
        {
                write(IP_D->list_ip());
                return 1;
        }
        else help(me);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式:
netcoff -a < ip 位址 > <代號> 增加一筆新的網咖資料
        -d < ip 位址 >        刪除網咖資料
        -l 查看紀錄的 servers
        -q 查驗線上的使用者那些在使用有紀錄的網咖

這是用來方便巫師管理網咖的指令，因台灣有越來越多網咖的趨勢，
而有些 multi-login 紛爭，而設此指令。

HELP
);
        return 1;
}
