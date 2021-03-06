#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("雲笈七籤-道德部",({"morality book", "book"}) );
        set_weight(80);
        set("long",@long
這是道派道藏中最有名「雲笈七籤」中的道德部。裡頭開宗
明義寫著「太上之象，莫高乎道德；其次莫大乎神明；其次莫大
乎太和；其次莫崇乎天地；其次莫著乎陰陽；其次莫明乎大聖。
夫道德，所以可道而不可原也」。
封面旁用硃砂寫著一行符文，不知道跟著念(read)會發生什麼事。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","本");
                set("value",0);
        }
        setup();
}

void init() 
{
        add_action("summon_book", "read");
}

int summon_book(string arg)
{
        object me, ob, env;
        if(arg != "符文")
                return notify_fail("你想要念什麼？\n");

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
    env = environment(me);
    if(!env) return 0;
 
        if(me->query("hp") < 300 )
                return notify_fail("你的身體狀況不佳，不能念出經文。\n");

    message_vision(CYN "$N拿起雲笈七籤-道德部念出一段誰都聽不懂的經文...\n"NOR ,me);
    if( objectp(me->query_temp("summon_book")) ) {
            message_vision("但是什麼事也沒有發生...\n"NOR ,me);
            return 1;
     }
     
     ob = new_ob(__DIR__"book1_npc.c");
     if( !objectp(ob) ) {
            message_vision(HIR"\t只見天下傳來一個聲音：出大問題了，請通知巫師處理。\n"NOR ,me);
            return 1;
     }
     
     me->receive_damage("hp", 100);
     ob->set("name", me->query("name")+"的道德部");
     ob->set_temp("no_combine",1);   //分開顯示
     ob->set("owner",me);          //標記主人
     ob->set_leader(me);
     me->set_temp("summon_book", ob);
    ob->move( env );
    message_vision(HIW "只見$N手中的雲笈七籤-道德部像有生命般地浮起，在$N身旁打轉不停。\n"NOR ,me);
    destruct( this_object() );
    return 1;
}

