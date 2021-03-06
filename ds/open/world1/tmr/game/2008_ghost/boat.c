#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( "普渡王船", ({ "pudu boat","boat" }) );
    set_weight(600);
        set("long",@LONG
王船是中元節普渡最重要的儀式，你可以在王船上放置祭品及香燭，
當放置夠多的祭品之後，就能找個河湖地帶，焚燒(burn)王船進行醮
典，以普渡受難的孤魂野鬼。

你可以使用「inspect」指令來檢視王船上已經放了多少東西。
你可以打「 help 中元節」獲取更詳細的資訊。
LONG
);
    set_max_capacity(2000);
    set_max_encumbrance(2000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "個");
        set("value", 99);
    }
    setup();
}

void init()
{
    add_action("do_light","burn");
    add_action("do_oil","inspect");
}

int ghost_stock = 0;      // 祭品
int ghost_xiang = 0;     // 香燭


void countWeight() {
        int i;
        object* inv;
        
        ghost_stock = 0;
        ghost_xiang = 0;
        
    inv = all_inventory(this_object());
    if( !sizeof(inv) )
        return;

    for(i=0; i<sizeof(inv); i++)
    {
        if( inv[i]->id("_GHOST_STOCK_") )
                ghost_stock += inv[i]->query("time");
        else if( inv[i]->id("_GHOST_XIANG_") )
                ghost_xiang += inv[i]->query("time");
    }   
}




int dest_all() {
    object *inv;
    int i;
    inv = all_inventory(this_object() );
    for(i=0; i<sizeof(inv); i++)
    {
destruct(inv[i]);
    }
}
int getSize(string type) {
    object *inv;
    int i, total;
    inv = all_inventory(this_object() );
    if( !sizeof(inv) )
        return 0;

    total = 0;
    for(i=0; i<sizeof(inv); i++)
    {
        if( !inv[i]->id(type) ) continue;
        total ++;
    }

    return total;
}

int do_oil()
{
     countWeight();
    return notify_fail( sprintf("王船有%3d份共%4d誠意、%3d份香燭共%4d香火、%2d鍋佛跳牆。\n",
                                                                getSize("_GHOST_STOCK_"), ghost_stock, 
                                                                getSize("_GHOST_XIANG_"),       ghost_xiang, 
                                                                getSize("_GHOST_STOCK2_")
                               ));
}

// 由系統來計算數量
int getAmount() {
        int am = ghost_stock;
        // 祭品得是香火的10倍
    if( ghost_stock/10 > ghost_xiang)
                am = ghost_xiang;
        
        // 祭品越多，衰減越少
        if(am>1000000)  // 百萬
                am /= 45;
        else if(am>500000)      // 50萬
                am /= 65;
        else if(am>100000)      // 10萬
                am /= 85;
        else if(am>10000)       // 1 萬
                am /= 95;
        else
                am /= (90+random(30));
        am = am/2 + random(am);
        
        if(am<1 && random(100) < 50 )   
                am = 1; // 有 50% 機率至少普渡1隻
                
        return am;
}

string BOARD_D = "/open/world1/tmr/game/2008_ghost/board.c";
void light2(object me) {
    string msg;
    object paper;
        int amount, cb;
        
        amount = getAmount();
        
        if(amount>0) {
                cb = getSize("_GHOST_EXTRA_");
                if(cb>30) cb = 30;
                // 加倍成功
                if( random(100) < cb ) {
                        amount *= 2;// 2倍
                    msg = sprintf(HIW"\n\t%s(%s)"HIW"所進行的"HIR"王船醮典"HIW"忽見"HIM"五彩霞雲"HIW"，諸方孤魂野鬼共"HIM"%4d隻"HIW"在醮典中減輕罪惡，實在是功\德無量！！\n"NOR,
                        me->name(), me->query("id"), amount );
                } else {
                    msg = sprintf(HIW"\n\t%s(%s)"HIW"所進行的"HIR"王船醮典"HIW"，諸方孤魂野鬼共"HIM"%4d隻"HIW"在醮典中減輕罪惡，實在是功\德無量！！\n"NOR,
                        me->name(), me->query("id"), amount );
                }
                
                
                // 冥紙
            paper = new("/open/world1/tmr/game/2008_ghost/paper.c");
            paper->set("amount", amount );
            paper->set("name", "冥紙(面額" + amount + "圓)");
            paper->set("long", paper->query("long") + "面額為" + amount + "圓");
            paper->move(me);
                BOARD_D->addScore(me, amount);
                
        // 特別獎：doll，每鍋佛跳牆有5%機率
        if( getSize("_GHOST_STOCK2_")*5 > random(100) ) {
            new("/open/world1/tmr/game/2008_ghost/ghost_doll.c")->move(me);
            msg += HIG"\n\t\t半空中乍開一扇鬼門，蹦出個豹\頭環眼的鍾馗娃娃，落到"+me->name()+HIG"的手上。\n"NOR;
        }
    } else {
            msg = HBK"\n\t忽見陰風吹過，"+me->name()+HBK"的王船上的火苗長不起來，沒幾下就沉入水底，不見蹤影。\n"NOR;
        }
        
        message("system",  msg, users() );
    dest_all();
    destruct( this_object() );
}

string PLACE = "/open/world1/wilfred/sand/room42";

int do_light(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg != "boat" )
        return notify_fail("你想要焚燒什麼？\n");
    if(me->is_busy() || me->is_fighting() )
        return notify_fail("你正忙著。。\n");
    if( query("ignite") )
        return notify_fail("這王船已經焚燒了。\n");
    if( base_name(environment(me)) != PLACE)
        return notify_fail("你得在磐龍險灘才能舉行王船醮典。\n");

    countWeight();
    if( ghost_xiang < 1 )
        return notify_fail("王船上沒有任何香燭，無法焚燒。\n");

    message_vision(HIC"$N點火焚燒$n"HIC"後，放入水中，只見$n"HIC"上的各式祭品跟香燭都漸漸起火了...\n"NOR, me, this_object() );
    me->start_busy(2);
    set("ignite", 1);
    call_out("light2", 2 + random(8), me );
    return 1;
}

