#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"新手教室空中庭院"NOR);

 set("long",@LONG
 
       ┌┬┐          ┌┬┐                  ▏
       ├┼┤          ├┤│                  ▏
       └┴┘          └┴┘[1;32m﹏[m   ˍˍ         ▏
ˍ                         [1;32m∫[1;31m＊[1;32m��[m ◣  ╲       ▏
◢ˍ    ┌───┐          [1;32m/_|_*[m █◣  ╲___O_▏
◤◢ˍ￣│[1;33m請上樓[m│￣￣￣￣￣ \_/￣◥█◣  ╲/Y\╲
￣◤◢ˍ└─┬─┘                  ◥█◣  ￣￣￣￣╲
  ￣◤◢    ┴                        ◥███████
    ￣◤                                ◥██████
￣￣￣
  你走進了另一間房間, 發現這裡是一處空中庭院, 到處鳥語花香, 
你看到的花卉顯然花期不同, 由此可以看出這裡似乎沒有四季之分,
你再仔細一看, 發現在花叢(flowers)間一根突起的木頭(wood)上面
寫了些字, 你一想了想.... 算了, 先看看吧....

LONG
    );
 set("exits",([ "west":__DIR__"school1.c",
                "up":__DIR__"school3.c",
    ]));
 set("item_desc",([
 	"flowers":"你看到花叢中有一根木頭(wood)..\n",
        "wood":@WOOD
        
  你看了看這根木頭, 發現背面是平的, 上面寫著: 戰鬥技巧, ....
哇! 後面的字看不清了....怎麼辦呢? 試試看仔細檢查(search wood)
一下吧!
        
WOOD
,
        "book":@BOOK
        
  這本書是要教你如何戰鬥, 也是天神被你誠心感動而掉下的書..希
望你好好看一下. 首先下 search flowers 這個指令. 會跑出一隻蝴
蝶, 對它下kill指令, 那就是戰鬥的實況, 戰鬥前應先用consider鑑
定一下敵人, 再開戰, 那萬一不幸陣亡怎麼辦呢? 你死後會到一個有
兩個雕像的地方....其中一個是生命之神, 一個是死亡之神, 聰明如
你, 應該知道要拜哪一個吧!?反正錯了再試嘛...., 對了, 殺死敵人
後不要忘記奉獻(sac)他的屍體(corpse)喔!但可別搶別人殺死的人的
屍體喔...

[提示: 開戰前先輸入<wimpy 50>來設定自動逃跑是比較安全的做法]
[提示: 遇到可疑的地方不妨使用 search here 仔細的搜查一下吧!]

BOOK
,
    ]));
    
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

int do_search(object me,string arg)
{
        object butterfly;
	if(arg == "flowers" && !present("butterfly", this_object()))
        {
                if(me->query("find_butter"))   //change by Kkeenn because Legand放search robot黑exp
                {
                        message_vision("$N仔細的在花叢中尋找東西, 花叢間突然飛出一隻被神力強化蝴蝶。\n\n",me);
                        butterfly=new(__DIR__"npc/butterfly2.c");
                        butterfly->move(__DIR__"school2.c");
                        me->set("find_butter",1);
                        return 1;
                }
                if(!me->query("find_butter"))
		{
        		message_vision("$N仔細的在花叢中尋找東西, 花叢間突然飛出一隻小蝴蝶。\n\n",me);
			butterfly=new(__DIR__"npc/butterfly.c");
			butterfly->move(__DIR__"school2.c");
                        me->set("find_butter",1);
			return 1;
		}
	}
	if( arg == "wood")
	{
		tell_object(me,"就在你正要仔細檢查木頭時..忽然, 啪! 的一聲, 一本書(book)掉了下來..\n看看上面寫些什麼吧(look book).\n");
		return 1;
	}
	return 0;
}
