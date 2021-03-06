#include <ansi.h>
inherit ITEM;
string check_ip(object ob, object *user);
void create()

{
        set_name(HIW"IP偵測器[2003年版本]"NOR, ({"ip machine", "machine"}));
        set_weight(1000);
        set("unit", "顆");
        set("long", @LONG偵測IP用的
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_checkip","cip");
}

int do_checkip(string arg)
{
        int i, num;
        string msg, result;
        object *user;

        user = users();

        for(i = 0;i < sizeof(user);i++)
                user[i]->set_temp("pending/ipcheck", 0);

        msg = HIG"\n麻蒼"HIC"輸入了指令，只見"HIW"IP偵測器"HIC"口畢口畢兩聲！！
"HIY"偵測出來了，偵測"HIR"結果"HIY"如下：\n\n"NOR;
        num = 0;
        for(i = 0;i < sizeof(user);i++) {
          if(user[i]->query_temp("pending/ipcheck") )     continue;
           reset_eval_cost();

                if( result = check_ip(user[i], user) ) {
msg += NOR + result + HIC"目前正從"HIR + query_ip_name(user[i]) + NOR"連線至"HIB"夢幻七域。\n"NOR;
                        num++;
                }
        }
        if(num == 0)    msg += HIR"\n偵測結果回報：沒有"HIY"重複IP"HIR"在線上。\n"NOR;

   if(num > 0)     msg += sprintf(HIY"\n偵測結果回報：有"HIR"重複IP"HIY"並且"HIB"數量"HIY"為"HIW"[ "HIM"%d 組"HIW" ] 。\n"NOR,num);
        write(msg);
        return 1;
}

string check_ip(object ob, object *user)
{
        int i, find = 0;
        string result, ip, id;

        id = ob->query("id");
        ip = query_ip_name(ob);
        result = ob->query("name") + "(" + ob->query("id") + ")  ";
  for(i = 0;i < sizeof(user);i++) {
     if(user[i]->query("id") != id && query_ip_name(user[i]) == ip) {
     result += user[i]->query("name") + "(" + user[i]->query("id") + ")  ";
                        user[i]->set_temp("pending/ipcheck", 1);
                        if(id && user[i]->query("id") )
                                find++;
                }
        }

        if( find )      return result;

        return 0;
}

int help(object me)
{
        write(@HELP
指令格式: checkip

檢查線上相同IP的玩家。

HELP
        );
        return 1;
}

