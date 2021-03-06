// 報紙
// Luky @DS 1999.9.2
// Comigning @DS 1999.9.25

#include <localtime.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("報紙架",({ "paper shelf","shelf"}) );
        set("long",@LONG

一架用來擺放報紙專用的架子，上面只有著一份報紙，
應該就是夢幻日報社所發行的夢幻日報了，你可以用
[ read_paper {第幾版} ] 來閱讀這一份報紙！

1.夢幻日報                     夢幻日報社榮譽發行。

LONG
        );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",15);
                set("unit","架");
        }
        setup();
}

string short()
{
        mixed *local;
        string str;
        local = localtime(time());
        str = sprintf( HIC"報紙架"NOR"(paper shelf) "HIG"[ 日期: 中華民國%d年%d月%d日 ]"NOR,
                local[LT_YEAR]-1911,
                local[LT_MON]+1,
                local[LT_MDAY] );
        return str;
}

void init()
{
        if( environment(this_object()) == this_player() )
                this_object()->move(environment(this_player()));
        add_action("do_setup","setup");
        add_action("do_read","read_paper");
}

int do_read(string arg)
{
        object me;
        int chose, *numbers;
        string str;

        numbers = LOTTERY_D->query_number();
        me = this_player();

        if( !arg || sscanf(arg,"%d edition",chose)!=1 )
                return notify_fail("你要讀第幾版呀？(read {版數} edition). \n");
        if( chose > 6 || chose < 1 )
                return notify_fail("你翻了翻報紙, 似乎沒有這一版的樣子！\n");
        switch(chose)
        {
                case 1: // 第一版
                        str = YEL"\n\t\t\t\t\t【第一版 "HIY"夢幻名人榜"NOR+YEL"】\n";
                        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
                        str += RECORD_D->query_popularity_rec();
                        str += "\n";
                        str += RECORD_D->query_past_money_rec();
                        str += "\n";
                        str += RECORD_D->query_now_money_rec();
                        str += "\n";
                        str += RECORD_D->query_mk_rec();
                        str += "\n";
                        str += RECORD_D->query_pk_rec();
                        str += "\n";
                break;
                //---------------------------------------------------------
                case 2: // 第二版
                        str = NOR+YEL"\n\t\t\t\t\t【第二版 "HIW"本日大事"NOR+YEL"】\n";
                        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
                        str += RECORD_D->query_temp_rec();
                        str += "\n";
                break;
                //---------------------------------------------------------
                case 3: // 第三版
                        str = NOR+YEL"\n\t\t\t\t\t【第三版 "HIG"重要消息"NOR+YEL"】\n";
                        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
                        if( file_size("/open/always/news_3.txt") < 1 ) str +="\n 徵求廣告中 \n\n";
                        else str += read_file("/open/always/news_3.txt");
                break;
                //---------------------------------------------------------
                case 4:
                        str = NOR+YEL"\n\t\t\t\t\t【第四版 "HIC"分類廣告"NOR+YEL"】\n";
                        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
                        if( file_size("/open/always/news_4.txt") < 1 ) str +="\n 徵求廣告中 \n\n";
                        else str += read_file("/open/always/news_4.txt");               
                break;
                //---------------------------------------------------------
                case 5:
                        str = NOR+YEL"\n\t\t\t\t\t【第五版 "HIC"全民開獎"NOR+YEL"】\n";
//                      str = NOR+YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
                        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
                        if(sizeof(numbers))
                        str += sprintf("夢幻彩卷 [第%d期] <超級特獎已累積至:%d>\n中獎號碼: \n\t超級特獎: %d\n"
                                "\t頭獎: %d\n\t二獎: %d\n\t三獎: %d\n\t四獎: %d\n\t五獎: %d\n\t六獎: %d\n\t七獎: %d\n\t八獎: %d\n\n\n"
                                "  目前第 %d 期彩卷正在瘋狂熱賣中!! 搶購人潮不斷, \n  根據最新調查資料, 至目前為止已賣出 %d 張了!!\n\n",
                        LOTTERY_D->query_times(),
                        LOTTERY_D->query_super_jack_pot(),
                        LOTTERY_D->query_super_jack(),
                        numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],numbers[5],numbers[6],numbers[7],
                        LOTTERY_D->query_times()+1,
                        LOTTERY_D->query_ticket_amount() );             
                break;
                
                case 6:
                        str = NOR+WHT"\n\t\t\t\t\t【特別增加版"HIY"－"HIC"每日一詩詞"NOR+WHT"】\n";
                        str += HIW"██████████████████████████████████\n"NOR;
                        if( file_size("/u/c/cominging/song.txt") < 1 ) str +="\n 尚未更新 \n\n";
                        else
                        {
                                str += HIC+read_file("/u/c/cominging/song.txt")+NOR;
                        }
        }
//      str += "\t□ 龍蝦主編: 以後將會陸續增加專欄, 敬請期待。\n\n";
        write(str);
        return 1;
}

int do_setup()
{
        object me;
        me = this_player();
        this_object()->move(environment(me));
        return 1;
}
