#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me);

int query_pan();

void create()
{
        set_name(HBK"牧神石像" NOR ,({"pan's statue","statue"}) );
        set_weight(200000);
        set("long",@LONG
    羊畸角，羊腿，羊蹄，牧神石像還留存著太多獸的殘留，祂的肉體
似乎尚未取得人的或神的認證。祂被放逐在神或人的領域之外，祂猶疑
徬徨在神或人的邊緣，帶著獸的貪婪、慾望、情慾、官能的亢奮，喘息
著，試圖侵犯褻瀆神或人的領域。你注意到這座石像上缺了一隻眼(eye)
，臉上就這樣留著這處缺塊。
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","尊");
                set("no_get",1);
                set("no_sac",1);
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_install","install");
}

int do_install(string arg)
{
        object me, eye;
        me = this_player();
        if(!arg || arg!="eye") return notify_fail("你想要安裝什麼東西？\n");
		// 牧神之眼
        if(!objectp(eye=present("_PAN_EYE_",me) ) )
                return notify_fail("你身上沒有這個東西。\n");
		if( query_temp("call") || query_pan() )
				return notify_fail("你發現石像上的兩隻石眼完好無缺，你不需要再安裝這個石眼了。\n");

        destruct(eye);
        message_vision("$N細心地將牧神之眼裝回石像臉上。\n",me);
        message_vision( CYN "牧神石像的兩眼忽然靈活地轉了圈...\n"NOR, me);
		set_temp("call",1);
        call_out("open_war",3 ,me);
        return 1;
}

void open_war(object me)
{
        object g;

		set_temp("call", 0);

        // 牧神潘恩
        g = new( __DIR__ + "pan.c" );
        g->move(TMR_PAST + "goat_maze/stairway4" );

		if( !objectp(g) ) return;

        message("world:world1:vision",
HIW"\n\n    "+me->query("name") +HIW "觸動了留存上千年的古老封印，一道皎白的月光直射到神祕的地底廣場...\n\n"
HIY"        放逐在曠野、廢墟、叢林、草澤間的"HIG"牧神潘恩"HIY"，帶著刺鼻的羊的騷味，回到了羊男的迷宮。\n\n" NOR
,users() );
}

int query_pan()
{
        object pan;

		// 判斷是否已經叫出牧神
        while( objectp(pan=find_living("bariour_pan")) )
        {
			// 找到牧神
			if( environment(pan) ) break;
			
			destruct(pan);
            pan = 0;
        }

        if( objectp(pan) )
			return 1;

		return 0;
}
