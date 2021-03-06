/* 
2008 中元節活動
Tmr 2008/08/14
*/

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

mapping game_record;
mapping game_gift;
int reset_record();
string do_list();

int addScore(object killer, int cnt);

void init_record()
{
        if( !restore() ) {
                game_gift=([]);
                game_record=([]);
                save();
        }

        if( !mapp(game_gift) ) 
        {
                game_gift=([]);
                game_record=([]);
        }
}

void create()
{
        seteuid(geteuid()); 
        
        set_name( HIC "王船醮典排行榜" NOR,({"pudu board","board"}) );
        set("long"," ");
        set_weight(200000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
        init_record();
}

string query_save_file() { return DATA_DIR + "game/2008_ghost"; }

void init()
{
        object me = this_player();

        if( !me ) return;
        if( !userp(me) ) return;
        
        add_action("do_look", "look");
        add_action("do_receive", "receive");
}
int do_look(string arg)
{
        if ( arg == "board" ) {
                        this_player()->start_more( do_list() );
            return 1;
        }

        return 0;
}

string do_list()
{
        float *score, swap;
        int i, j, x;
        string *ppl, msg, user;

        if( !restore() )  game_record=([]);
        if( !game_record ) return "目前還沒有任何紀錄！\n";
        if( !mapp(game_record) ) return "目前還沒有任何紀錄！\n";

        ppl=keys(game_record);
        score=values(game_record);

        i=sizeof(score);
        for(j=i-1;j>0;j--)
        {
                for(x=1;x<=j;x++)
                {
                        if( score[x-1] > score[x] )
                        {
                                swap=score[x-1];
                                score[x-1]=score[x];
                                score[x]=swap;
                                user=ppl[x-1];
                                ppl[x-1]=ppl[x];
                                ppl[x]=user;
                        }
                }
        }
        i=sizeof(ppl);
        j=0;
        msg= HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        msg += HIG"\t\t\t【２００８年 【王船醮典】積點排行榜】\n";
        msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        while( i-- )
        {
                j++;

                if( ppl[i]==getuid(this_player()) ) msg+= HIC;
                                else if( game_gift[ppl[i]] == 1 ) msg += HBK;
                else msg += CYN;
                if( game_record[ppl[i]] > 0 ) {
                            msg += sprintf( "第%4s名 ---- %13s 目前已普渡亡魂 %8d 位",
                                chinese_number(j),ppl[i], game_record[ppl[i]] );
                }
                 msg += "\n" NOR;
        }       
        msg += HIW"\n--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        msg += "請打「help 中元節」了解活動內容\n";

        return msg;
}

int reset_record()
{
        game_record=([]);
        this_object()->save();

        write("積分已經清除！\n");

        return 1;
}

void addScore2(string id, int cnt) {
        if( !restore() ) game_record=([]);
        if( !mapp(game_record) ) game_record=([]);

        game_record[id] += cnt;
        save();
}

int addScore(object killer, int cnt)
{
        if (!killer) return 0;
        if ( cnt < 1) return 0;
        addScore2( getuid(killer), cnt);
        return 1;
}

///*
void give_scroll(object me, string type, int num) {
        int i;
        object scroll;
        if(num<1) return;
        for(i=0;i<num;i++) {
                scroll = new("/open/enhance/100_"+type+".c");
                scroll->move(me);
        }
        tell_object(me, HIG"恭喜你獲得"+num+"張" + type +"卷軸。\n"NOR);
}

void receive_gift(object me, string type) {
        int bonus = 0;
        string id = getuid(me);
        if( game_record[id] < 10000 ) return;
        switch(id) {
                case "bluerex" : case "lestat" : case "deaon" :
                bonus = 200;    // 前三名
                break;
                case "bowie" : case "vicliu" : case "christine" :
                case "watermoon" : case "glemtwo" : case "paper" :
                case "godfire" :
                bonus = 50;     // 4~10名
                break;
                default:
                bonus = 10;     //參加獎
                break;
        }
       give_scroll(me, type, bonus);
}


int do_receive(string arg)
{
                object me = this_player();
        if ( !me || !userp(me) ) return 0;

        if (game_gift[ getuid(me) ]==1)
                        return notify_fail("你已經領過禮物了喔！\n");
                if( game_record[ getuid(me) ] < 1 ) 
            return notify_fail("沒有你的參加記錄喔！\n");
        if( game_record[getuid(me)] < 10000 )
            return notify_fail("你的積分沒有到達一萬，無法領獎。\n");
        if(!arg) 
                return notify_fail("你想要領取那一種卷軸(bar,bio,wit,sou,tec)？\n");
                if( arg!="bar" && arg!="wit" && arg!="tec" && arg!="sou" && arg!="bio" )
                return notify_fail("你想要領取那一種卷軸(bar,bio,wit,sou,tec)？\n");
        // 領獎         
        receive_gift(me, arg);
        // 記錄已領過獎了
        game_gift[getuid(me)] = 1;
        save();
        return 1;
}
//*/
