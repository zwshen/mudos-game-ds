/* 
2008 鼠來寶 集點活動
Tmr 2006/12/14 
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
        seteuid(getuid()); 
        set_name( HIW "鼠來寶積點排行榜" NOR,({"record board","board"}) );
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

string query_save_file() { return DATA_DIR + "game/2008_mouse"; }

void init()
{
        object me = this_player();

        if( !me ) return;
        if( !userp(me) ) return;
        
        add_action("do_look", "look");
//        add_action("do_receive", "receive");
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
        msg += HIG"\t\t\t【２００８年 【鼠來寶】積點排行榜】\n";
        msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        while( i-- )
        {
                j++;

                if( ppl[i]==getuid(this_player()) ) msg+= HIC;
                                else if( game_gift[ppl[i]] == 1 ) msg += HBK;

                else msg += CYN;

                if( game_record[ppl[i]] > 0 ) {
                            msg += sprintf( "第%4s名 ---- %13s 目前積分 %8d 點",
                                chinese_number(j),ppl[i], game_record[ppl[i]] );
                }

                  msg += "\n" NOR;
        }       
        msg += HIW"\n--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        msg += "請打「help 鼠來寶」了解活動內容\n";

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

/*
void give_doll(object me, int num) {
        int i;
        object doll;
        if(num<1) return;
        tell_object(me, HIG"恭喜你可獲得"+num+"隻聖誕娃娃。\n"NOR);
        for(i=0;i<num;i++) {
                doll = new("/open/always/christmas_doll");
                doll->move(me);
        }
}

void receive_doll(object me) {
        int bonus = 0;
        string id = getuid(me);
        if( game_record[id] < 10000 ) return;
        switch(id) {
                case "bluerex" : //  第一名
                bonus = 10;
                break;
                case "paper" : //  2
                bonus = 10;
                break;
                case "ayumi" : //  3
                bonus = 10;
                break;
                case "afar" : // 積分十萬 
                bonus = 10;
                break;
                case "bowie" : // 積分十萬 
                bonus = 10;
                break;
                case "opek" : // 積分十萬 
                bonus = 10;
                break;
                case "miriam" : // 積分十萬 
                bonus = 10;
                break;
                case "jawei" : // 8 名
                case "belle" : // 9 名
                case "andygi" : // 10 名
                bonus = 1;
                break;
        }
        if(bonus>1) 
                give_doll(me, bonus);
        else    // 一萬分一隻
                give_doll(me, game_record[id]/10000 + bonus);
}

// 參加獎
void receive_joingift(object me) {
        object ring;
        ring = new("/open/world1/tmr/game/2006_c/ring");
        ring->move(me);
        tell_object(me, HIG"恭喜你已領得參加獎。\n"NOR);
}

void receive_gift(object me) {
        // 領 doll
        receive_doll(me);
        // 領參加獎
        receive_joingift(me);
}

int do_receive()
{
        object gift;
                object me = this_player();
        if ( !me || !userp(me) ) return 0;
                init_record();        

        if (game_gift[ getuid(me) ]==1)
                        return notify_fail("你已經領過禮物了喔！\n");
                if( game_record[ getuid(me) ] < 1 ) 
                        return notify_fail("沒有你的參加記錄喔！\n");

                // 領獎         
                receive_gift(me);

                // 記錄已領過獎了
        game_gift[getuid(me)] = 1;
                save();
        return 1;
}


*/
