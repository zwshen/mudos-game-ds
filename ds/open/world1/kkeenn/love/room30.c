#include <ansi.h>;
inherit ROOM;
// 自然奇觀：牛郎織女
void open_star2() {
    "/adm/daemons/event/2star.c"->trigger_event();
}

void open_star() {
    call_out("open_star2",90+random(30));
}
void create()
{
        set("short", HIC"情城池"HIR"禁地"NOR);
        set("long", @LONG
一入禁地，前方掛著一白金盤龍橫匾，上頭寫著斗大的四個字『七夕
情意』。大廳中擺著一張大紅桌子，一邊是檀木架子大理石屏風，一邊是
三尺多高的青綠古銅鼎，壁上一塊烏木牌寫著『情城風名千百載』。地下
兩溜十六張楠木圈椅，上頭搭著五彩刻絲石青椅袱。右邊的牆上掛有由王
羲之親筆所題的蘭亭序，左邊則是一塊木板，上面刻有情城弟子的排行榜
，可用(load)來看排行榜。
LONG
        );
        set("exits", ([ 
  "down"  : __DIR__"room27",
  ]));
	set("no_recall", 1);
        set("objects", ([
 __DIR__"npc/master_2" : 1,
]));
        set("light",1);
        setup();
}
void init() {
        add_action("do_billing","load");
}

int do_billing(string str) {
        object *user,me;
int i,j;

        user = users();
        me = this_player();

        for(i=j=0; i<sizeof(user); i++)
           if(user[i]->query("class1") == "情城池" && !wizardp(user[i]))
              user[j++] = user[i];
        if(str == "combat_exp") {
           call_out("do_exp",0,user,j);
           return 1;
        }
        else if(str == "run_cloud") {
           call_out("do_steps",0,user,j);
           return 1;
        }
        else if(str == "masen_whip") {
           call_out("do_whip",0,user,j);
           return 1;
        }
        else
           return notify_fail("使用格式: load <種類>\n"
                              "經驗值(combat_exp)\n"+
                              "追雲流步(run_cloud)\n"+
                              "滅神鞭法(masen_whip)\n\n");
}
int do_exp(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if(user[k]->query("combat_exp") > user[i]->query("combat_exp")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\n\t\t情城池經驗值排行榜:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t第%2d名       %-18s %s(%s) \n"NOR,i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));
        printf("\n");
}
int do_steps(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if((int)user[k]->query_skill("run_cloud") > (int)user[i]->query_skill("run_cloud")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

  printf(HIG"\n\t\t情城池輕功\排行榜:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t第%2d名       %-18s %s(%s) \n"NOR,
                      i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));

        printf("\n");
}

int do_whip(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if((int)user[k]->query_skill("masen_whip") > (int)user[i]->query_skill("masen_whip")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\n\t\t情城池滅神鞭法排行榜:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t第%2d名       %-18s %s(%s) \n"NOR,
                      i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));
        printf("\n");
}

