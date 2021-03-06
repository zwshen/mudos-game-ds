// 報紙
// Luky @DS 1999.9.2
#include <localtime.h>
#include <ansi.h>
#define NEWS_DIR "/example/news/"
inherit ITEM;

void create()
{
         set_name("卷軸小報",({"scroll note", "note"}) );
        set("long",@LONG
一份印刷精美的卷軸小報，上面刊登著強化卷軸的出產量及
其他人使用的情形。這上面的消息，每到半夜12點即會清空。
LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",15);
                set("unit","份");   //luky
        }
        setup();
}

string short()
{
        mixed *local;
        string str;
        local = localtime(time());
                str=sprintf("卷軸小報(scroll note) [中華民國%d年%d月%d日]",
                local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY] );
        return str;
}


// 卷軸消息
string scroll_news() {
        string str = NOR+YEL"\n\t\t\t\t\t【"HIW"卷軸消息"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
         str += HIY"共產出有"+ RECORD_D->getTotalScroll()+ "張強化卷軸。\n"NOR;
       str += RECORD_D->query_scroll_record();
        str += "\n";
        return str;
}

string long()
{
        string str;
        str = short();

        str += scroll_news();
        str += "\t□ Luky主編，Tmr副編: 以後將會陸續增加專欄, 敬請期待。\n\n";

        return str;
}

