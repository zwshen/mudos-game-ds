#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIC"ｑｕｓｒ"NOR, ({"test"}));
    set("unit", "個");
    set("long",@LONG
    用來玩的一個東西
LONG);

    set_weight(1);
    set("value",1);
  setup();
}

void init()
{
add_action("do_qusr","qusr");
    }
int do_qusr(string str, string arg)
{
        int i,j=0,n,idle;
        int k;
        int z;
        object where, me;
        object *user_list,user_location;
        object *ob;
        string status1, status2, status3, status4; 
        string msg;
        me = this_player();
        user_list=users();
        n=sizeof(user_list);
     write(sprintf("目前"+ MUD_NAME +"線上共有 %d 名玩家，名單如下﹕\n",n));
        for(i=0;i<n;i++)
        {
                if(user_list[i])
                {
                        ob = users();
                        j++;
                        user_location = environment(user_list[i]);
/*
                        if (!user_location) return notify_fail("他在虛無飄藐間。\n");
*/

                        idle=query_idle(user_list[i]);
                if (in_input(user_list[i])) status1=HIC"(輸入文字中)"NOR;
                        else status1="";
                if ((in_edit(user_list[i]))) status2=HIY"(編輯檔案中)"NOR;
                        else status2="";
                if (idle>180) status3=sprintf(HIR"(發呆了 %d 分鐘)"NOR,idle/60);
                        else status3="";
                if (idle>3600) status4=sprintf(HIB"(發呆了 %d 小時 %d 分鐘)"NOR,idle/3600,(idle-3600)/60);
                        else status4="";
                if (!user_location)
{
write(sprintf("%2d %12s %s(%s) 位於 %s(?????????)\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
//                        (string)user_location->query("short"),
                        "他在虛無飄藐間" ));
                        if ((status1!="")||(status2!="")||(status3!="")||(status4=""))
write(sprintf("                狀態  : %s%s%s\n",status1,status2,status3,status4));
write(sprintf("                從 %s 來到此處。\n",query_ip_name(ob[i])));
}
                else
{
write(sprintf("%2d %12s %s(%s) 位於 %s(%s)\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)user_location->query("short"),
                        (string)file_name(user_location) ));
                        if ((status1!="")||(status2!="")||(status3!="")||(status4!=""))
write(sprintf("                狀態  : %s%s%s\n",status1,status2,status3,status4));
write(sprintf("                從 %s 來到此處。\n",query_ip_name(ob[i])));
}
                }
        }
        z = j ;
        return 1;
}


