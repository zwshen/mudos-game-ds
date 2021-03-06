// 報紙
// Luky @DS 1999.9.2
#include <localtime.h>
#include <ansi.h>
#define NEWS_DIR "/example/news/"
inherit ITEM;

void create()
{
        set_name("夢幻凍酸新聞報",({"ettoday paper","paper"}) );
        set("long",@LONG
一份印刷精美的報紙，上面登了今日各類時事新聞頭條。
LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",15);
                set("unit","份");
        }
        setup();
}

string short()
{
        mixed *local;
        string str;
        local = localtime(time());
                str=sprintf("夢幻凍酸新聞報(ettody paper) [中華民國%d年%d月%d日]",
                local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY] );
        return str;
}

string news_title() {
        int idx;
        string *titles = NEWS_D->getTitles();
        string str = NOR+YEL"\n\t\t\t\t\t【 "HIW"凍酸 ETToday 新聞頭條"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        if(sizeof(titles)<1) return str + "\n";
        for(idx=0;idx<sizeof(titles);idx++) {
                str +=  CYN"" + sprintf("%4d: %s\n", idx+1, titles[idx] );

        }
        str += "\n" NOR;
        return str;
}


string long()
{
        string str;
        str = short();

        str += news_title();
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        str += "\t□ Tmr 編撰，請多多指教。\n創報日 2007/01/25。\n\n";
        return str;
}


