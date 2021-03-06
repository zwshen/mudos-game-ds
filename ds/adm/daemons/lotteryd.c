// 四星彩 公益彩卷 
// -Tmr 2007/01/24
#include <ansi.h>
#define MAX_TICKET 9999
inherit F_SAVE;
inherit F_DBASE;

int times;                      //第幾期
int jack1;      // 特獎
int jack2;      // 一般獎
int amount;             //售出幾張
int flag;               //控制是否可以對獎

void generate_num();

void create()
{
        seteuid(getuid());
                set("name", "四星彩摸彩精靈");
                set("id", "lotteryd");
        if( !restore() )
        {
                times=0;
                jack1 = jack2 = 0;
                        amount=0;
                        flag=0;
        }
}
string query_save_file() { return DATA_DIR + "lottery2"; }

int set_flag(int arg)
{
        if(arg>0) flag=1;
        else flag=0;
        return flag;
}

int query_max_ticket()
{
        return MAX_TICKET;
}

int find_ticket_num()
{
        return random(MAX_TICKET);
}

void generate_num()
{
        jack1 = random(MAX_TICKET); // 0 ~ MAX_TICKET
        jack2 = random(MAX_TICKET); // 0 ~ MAX_TICKET
        while(jack2 == jack1)
                jack2 = random(MAX_TICKET); // 0 ~ MAX_TICKET

        times += 1;
        amount = 0;
        save();
        flag = 1;
        return;
}

// 購買一張ticket
object createTicket() {
        object ob;
        ob = new("/open/always/ticket.c");
        ob->set("time", LOTTERY_D->query_times() + 1 );
        ob->set("number", LOTTERY_D->find_ticket_num() );
        // 確定賣出一張
        LOTTERY_D->release_ticket();
 
        return ob;
}
int query_ticket_amount()
{
        return amount;
}

int release_ticket()
{
        amount++;
        return amount;
}

int can_buy_ticket()
{
        return 1;       // 總是可以買，不限張數，因為可以買重覆的數字
//      return (amount<MAX_TICKET);
}


//查詢超級大獎獎點
int query_jack1()
{
        return jack1;
}

//查詢超級大獎獎點
int query_jack2()
{
        return jack2;
}

//查詢第幾期
int query_times()
{
        return times;
}

// 判斷是否中獎 回應值=中第幾獎(-2~10)
// 傳回值> -2:尚未開獎, -1:過期了, 0:沒中
// 99:超級獎
// 其它兩位數：十位數代表A的數量、個位數代表B的數量，4A即為「40」
int query_lottery(int num, int time)
{
        int na,nb;
        int p1,p2,p3,p4;
        int q1,q2,q3,q4;
        int k1,k2,k3,k4;
        int j1,j2,j3,j4;
        int temp;
        if( time < times) return -1;
        if(!flag || time>times) return -2;

        if(num==jack1)
                return 99;      // super jack
        if(num==jack2)
                return 40;      // 4A

        // 判斷幾A幾B
        na = nb = 0;
        k1 = k2 = k3 = k4 = 0;
        j1 = j2 = j3 = j4 = 0;

        temp = num;
        p1 = temp % 10;
        temp/=10;
        p2 = temp % 10;
        temp/=10;
        p3 = temp % 10;
        temp/=10;
        p4 = temp;

        temp = jack2;
        q1 = temp % 10;
        temp/=10;
        q2 = temp % 10;
        temp/=10;
        q3 = temp % 10;
        temp/=10;
        q4 = temp;
        
        if(p1==q1) {j1=k1=1; na++;}
        if(p2==q2) {j2=k2=1; na++;}
        if(p3==q3) {j3=k3=1; na++;}
        if(p4==q4) {j4=k4=1; na++;}


        if( p1 == q2 && k1 == 0 && j2 ==0) { k1=1;j2=1; nb++;}
        if( p1 == q3 && k1 == 0 && j3 ==0) { k1=1;j3=1; nb++;}
        if( p1 == q4 && k1 == 0 && j4 ==0) { k1=1;j4=1; nb++;}

        if( p2 == q1 && k2 == 0 && j1 ==0) { k2=1;j1 =1; nb++;}
        if( p2 == q3 && k2 == 0 && j3 ==0) { k2=1;j3 =1; nb++;}
        if( p2 == q4 && k2 == 0 && j4 ==0) { k2=1;j4 =1; nb++;}

        if( p3 == q1 && k3 == 0 && j1 ==0) { k3=1;j1 =1; nb++;}
        if( p3 == q2 && k3 == 0 && j2 ==0) { k3=1;j2 =1; nb++;}
        if( p3 == q4 && k3 == 0 && j4 ==0) { k3=1;j4 =1; nb++;}

        if( p4 == q1 && k4 == 0 && j1 ==0) { k4=1;j1 =1; nb++;}
        if( p4 == q2 && k4 == 0 && j2 ==0) { k4=1;j2 =1; nb++;}
        if( p4 == q3 && k4 == 0 && j3 ==0) { k4=1;j3 =1; nb++;}

        return na*10 + nb;
}

//清除所有紀錄
int clean_lottery()
{

        times=0;
        jack1 = -1;
        jack2 = -1;
        flag=0;
        save();
        return 1;
}
