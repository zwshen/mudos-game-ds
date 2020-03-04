
// 紫陽山第四層_秘密

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石間");
        set("long", @LONG
這裡是一間小小的石間，當你從另一端翻轉過來時，就感覺到這裡
的陰暗潮溼，這裡四周都是石頭，可見是一個人工所做的一個石間，旁
邊的牆上還有刻著些圖形，旁邊有一個柱子，上面安放著一顆石頭，不
知有何用處。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
]));
        set("item_desc", ([
//  "圖形" : "一些奇怪的圖形，看起來像是一種武功\的樣子，你可以嘗試去學學看。\n",
  "石頭" : "這是一顆形狀奇怪的石頭，不過摸起來卻令人有點精神振奮的感覺，你會想要拿拿看(get)。\n",
]));
        set("world", "past");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_get", "get");
}

int do_push(string arg)
{
        object me = this_player();

        if( arg != "石壁" && arg != "stone" )
                return 0;
        message_vision(HIW"$N使勁推動石壁，只見石壁旁煙霧一起，整個人都翻了過去。\n"NOR,me);
        me->move(__DIR__"hole8.c");
        tell_room(environment(me), "只見石壁一陣晃動，"+me->name()+"突然出現在這裡！\n", ({ me }));
        me->start_busy(1);
        return 1;
}

/*int do_try(string arg)
{
        object me = this_player();
        if( !me->query("study_redblade") )
                return notify_fail("你照著壁上的姿態去做，結果沒有領悟到什麼東西。\n");
        if( !present("tai-gei graph", me) )
                return notify_fail("你沒有彖絕圖表，看不太懂上面的東西．．\n");
        if( me->query_skill("redblade") )
                return notify_fail("你已經會墨紅刀法了！\n");
        message_vision("$N照著石壁上的動作依樣劃葫蘆的做了起來．．\n", me);
        me->add("study_redblade",1);
        if( me->query("study_redblade") > 50 )
        {
                me->set_skill("redblade",1);
                tell_object(me, HIY"你領悟了墨紅刀法的刀意了！\n"NOR);
        }
        return 1;
}*/

void close_get();
int do_get(string arg)
{
        object me = this_player(),
                  d_stone = new(__DIR__"npc/obj/d_stone.c");
        if( arg != "stone" && arg != "石頭" )
                return 0;
        if( query_temp("use_get") )
                return 0;
        message_vision(HIG"$N從柱上取下了一顆石頭！\n"NOR, me);
        d_stone->move(me);
        set_temp("use_get", 1);
        me->set_temp("got_stone",1);
        close_get( );
        return 1;
}

void close_get()
{
        set("long",@LONG
這裡是一間小小的石間，當你從另一端翻轉過來時，就感覺到這裡
的陰暗潮溼，這裡四周都是石頭，可見是一個人工所做的一個石間，旁
邊的牆上還有刻著些圖形，旁邊有一個柱子，上面沒有什麼小東西，不
知有何用處。
LONG
        );
        delete("item_desc/石頭");
          call_out("delay", 600 + (600) );
        set_temp("use_get", 1);

}

void delay( )
{
        set("long", @LONG
這裡是一間小小的石間，當你從另一端翻轉過來時，就感覺到這裡
的陰暗潮溼，這裡四周都是石頭，可見是一個人工所做的一個石間，旁
邊的牆上還有刻著些圖形，旁邊有一個柱子，上面安放著一顆石頭，不
知有何用處。
LONG
        );
        set("item_desc/石頭" ,"這是一顆形狀奇怪的石頭，不過摸起來卻令人有點精神振奮的感覺，你會想要拿拿看(get)。\n");
        delete_temp("use_get");
}

