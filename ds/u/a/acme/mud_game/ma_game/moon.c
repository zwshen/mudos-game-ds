#include <ansi.h>
#include <room.h>
//#define START_ROOM "/open/dragon_wine/inn_hall.c"     //At 用
#define START_ROOM "/open/world1/tmr/area/hotel.c"        //Ds 用

inherit F_SAVE;
inherit ROOM;
mapping game_record;
mapping game_no;

int do_del(string arg);
int do_leave();
int do_list();
int do_sign();
float sort_list(string ob1, string ob2);

void create()
{
        seteuid(getuid()); 
        set("short", "月宮[月球]");
        set("long", @LONG
一望無際的月球，四週坑坑洞洞的，十分荒涼，遠方傳來「喀∼
喀∼」之聲，應該是吳剛在砍桂樹吧，後方又傳來陣陣「咚咚∼」聲
，也許是玉兔在搗藥，眼前一顆黑色大石，上頭刻著許多密密麻麻的
字。當然你也可以離開(leave)這裡。
LONG
        );
//        set("detail", ([      // At 用
        set("item_desc", ([     // Ds 用
                "黑色大石" : "你可以在上面刻下(sign)自已的紀錄，也可以觀看紀錄(list)。\n",
        ]));
        set("no_fight",1);
        set("no_recall",1);
        setup();
        if( !restore() )
        {
                game_record=([]);
                game_no=([]);
                this_object()->save();
        }
}

void init()
{
        add_action("do_list","list");
        add_action("do_sign","sign");
        add_action("do_leave","leave");
        add_action("do_del","del");
}

int do_del(string arg)
{
        if( wiz_level(getuid(this_player())) < wiz_level("(arch)") )
                return 0;
        if( !arg ) return notify_fail("你想刪除誰的記錄？\n");

        if( undefinedp(game_record[arg]) && arg!="-a" )
                return notify_fail("這個人並沒有奔月紀錄哦！\n");

        if( arg=="-a")
                write("你確定要刪除全部的奔月紀錄嗎？(y/n)");
        else write("你確定要刪除["+arg+"]的奔月紀錄嗎？(y/n)");
        
        input_to("check_del", arg);

        return 1;
}

private void check_del(string check,string arg)
{
        if( check != "y" && check !="Y" )
        {
                write("取消刪除！\n");
                return;
        }
        if( arg== "-a" )
        {
                write("你將全部的奔月紀錄刪除了！\n");
                game_record=([]);
                game_no=([]);
        }
        else
        {
                write("你將["+arg+"]的奔月紀錄刪除了！\n");
                map_delete(game_record,arg);
                map_delete(game_no,arg);
        }
        this_object()->save();
        return;
}

int do_leave()
{
        message_vision(HIW"$N說了一句「罷了∼神仙難為∼還是回去當凡夫俗子吧∼」隨即往下墜落！\n"NOR,this_player());
        this_player()->delete_temp("fly_speed");
        this_player()->delete_temp("fly_long");
        this_player()->delete_temp("fly_time");
        this_player()->move(START_ROOM);
        message_vision(HIW"$N從天上掉了下來！！\n"NOR,this_player());
        return 1;
}

int do_list()
{
        float *speed,swap;
        int i,j,x;
        string *ppl,msg,user;
        if( !mapp(game_record) ) return notify_fail("目前還沒有任何紀錄！\n");
        ppl=keys(game_record);
        speed=values(game_record);

        i=sizeof(speed);

        for(j=i-1;j>0;j--)
        {
                for(x=1;x<=j;x++)
                {
                        if( speed[x-1] < speed[x] )
                        {
                                swap=speed[x-1];
                                speed[x-1]=speed[x];
                                speed[x]=swap;
                                user=ppl[x-1];
                                ppl[x-1]=ppl[x];
                                ppl[x]=user;
                        }
                }
        }
        i=sizeof(ppl);
        j=1;
        msg ="\t\t\t  ◎中秋奔月活動◎\n";
        msg+="======================================================================\n";
        while( i-- )
        {
                if( i<sizeof(ppl)-1 )
                        if( game_record[ppl[i]] != game_record[ppl[i+1]] )
                                j++;

                  if( j <= 3 ) {
                          msg+=HIC;
                  } else if( j <= 10 ) {
                          msg+=HIY;
                  } else msg+=YEL;


                  if( ppl[i]==getuid(this_player()) ) msg+= HIW;

                msg+=sprintf("第%3d名 ---- %13s 共花%10.3f秒",
                        j,ppl[i],game_record[ppl[i]]);

                if(i==0) {
                        msg+= HIC"  (save eq一件)\n"NOR;


                } else {
                        switch( j )
                        {
                                  case 1: msg+= HIC"  (自訂save eq一件)\n"NOR; break;
                                   case 2..3: msg+= HIC"  (save eq一件)\n"NOR; break;
                                  case 4..10: msg+= HIB"  (doll一個)\n"NOR; break;
                                  default: msg+=CYN"  (參加獎)\n"NOR; break;

                        }
                }
        

                msg+=NOR;
        }       
        msg+="======================================================================\n";
//          msg+="註：活動結束後，前五名者請洽 流影(Acme) 領取獎品…\n";
//          msg+="    其它的找嫦娥要參加獎吧..:D~\n";

        this_player()->start_more(msg);
        return 1;
}

int do_sign()
{
        string id;
        object me=this_player();
        id=getuid(me);
        if( !mapp(game_record) ) game_record=([]);
        if( !me->query_temp("fly_time") )
                return notify_fail("你並沒有奔月速度！\n");
        if( !undefinedp(game_record[id]) )
        {
                write("你的舊紀錄為["+game_record[id]+"]秒，這次的速度為["+me->query_temp("fly_time")+"]你確定要更新紀錄嗎？(y/n)");
                input_to("check_sign");
                return 1;
        }
        write("你在黑色大石上刻下了自已的大名和奔月速度！\n");
        game_record[id]=me->query_temp("fly_time");
        me->delete_temp("fly_time");
        this_object()->save();
        return 1;
}

private void check_sign(string check)
{
        object me=this_player();
        if( check!="y" && check!="Y" )
        {
                write("取消更新紀錄。\n");
                return;
        }
        game_record[getuid(me)]=me->query_temp("fly_time");
        me->delete_temp("fly_time");
        write("你在黑色大石上刻下了自已的大名和奔月速度！\n");
        this_object()->save();
}
string query_save_file() { return DATA_DIR + "game/ma_game"; }

