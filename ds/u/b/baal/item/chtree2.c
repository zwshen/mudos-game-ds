#include <ansi.h>
inherit ITEM;

void delay();

void create()
{
        set_name(HIC"聖"+HIG+"誕"+HIY+"樹"NOR,({"christmas tree","tree"}) );
        set("long","
一棵掛滿了七彩燈飾、塑膠小玩具的聖誕樹，不停的旋轉著，一陣陣悅
耳的樂聲不停的演奏著，讓整個房間都充滿了聖誕節的氣氛...: )
搖搖聖誕樹(shake 聖誕樹)，會唱歌ㄡ！！
(樹上掛著一個牌子：黑玫瑰小騎士股份有限公司生產)\n"
        );
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
/*      set("chat_chance",15);  // 這是 ITEM 不會用到 chat_chane 的.
        set("chat_msg",({       // 只有 NPC 會動.
        "「And a happy new year.」\n", 
        }));*/
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
        if( arg != "聖誕樹" && arg != "christmas tree" && arg != "tree" ) return 0;
        if( query_temp("ch_used") )
                return notify_fail("看起來聖誕樹還在搖，似乎是音樂尚未響完喔∼！\n");
message_vision(HIC"$N輕輕的搖兩下聖誕樹，一陣清翠悅耳的樂聲傳了出來∼∼\n\n"NOR,me);
message_vision(HIG"「We  wish  you  a  Merry  Christmas∼∼」\n\n"NOR,me);
message_vision(HIG"「We  wish  you  a  Merry  Christmas∼∼」\n\n"NOR,me);
message_vision(HIG"「We  wish  you  a  Merry  Christmas∼∼」\n\n"NOR,me);
message_vision(HIY"「And a happy new year∼∼」\n\n"NOR,me);
message_vision(HIC"「Good  tidings  we  bring∼∼」\n\n"NOR,me);
message_vision(HIC"「To  you  and  your  friends∼∼」\n\n"NOR,me);
message_vision(HIG"「We  wish  you  a  Merry  Christmas∼∼」\n\n"NOR,me);
message_vision(HIY"「And a happy new year∼∼」\n\n"NOR,me);
message_vision(HIG"「We  wish  you  a  Merry  Christmas∼∼」\n\n"NOR,me);
message_vision(HIG"「We  wish  you  a  Merry  Christmas∼∼」\n\n"NOR,me);
message_vision(HIG"「We  wish  you  a  Merry  Christmas∼∼」\n\n"NOR,me);
message_vision(HIY"「And a happy new year∼∼」\n\n"NOR,me);
        set_temp("ch_used", 1);
        call_out("delay", 30);
        return 1;
}

void delay()
{
        delete_temp("ch_used");
}

