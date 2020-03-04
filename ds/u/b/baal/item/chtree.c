#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"聖"+HIG+"誕"+HIY+"樹"NOR,({"christmas tree","tree"}) );
        set("long","
一棵掛滿了七彩燈飾、塑膠小玩具的聖誕樹，不停的旋轉著，一陣陣悅
耳的樂聲不停的演奏著，讓整個房間都充滿了聖誕節的氣氛...: )
搖搖聖誕樹(shake 聖誕樹)，會唱歌ㄡ！！
p.s.聖誕樹使用規則視同channel用法,洗螢幕者視同違反rules...
(樹上掛著一個牌子：黑玫瑰小騎士股份有限公司生產)\n"
        );
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set("chat_chance",15);
        set("chat_msg",({
        "「叮叮噹，叮叮噹，鈴聲多響亮∼∼」\n",
        "「你看他，不避風霜，面容多麼慈祥∼∼」\n",        
        }) );
        setup();                

}
void init()
{
       add_action("typeshake","shake");
}
     int typeshake(string arg)
{
        object me;
        me=this_player();
        if(arg != "聖誕樹") return 0;
        message_vision(HIC"$N輕輕的搖兩下聖誕樹，一陣清翠悅耳的樂聲傳了出來∼∼\n\n"NOR,me);
        message_vision(HIY"「叮叮噹，叮叮噹，鈴聲多響亮∼∼」\n\n"NOR,me);
        message_vision(HIG"「你看他，不避風霜，面容多麼慈祥∼∼」\n\n"NOR,me);
        return 1;
}


