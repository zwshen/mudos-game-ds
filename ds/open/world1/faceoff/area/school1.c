#include <path.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"騰空書院"NOR);

 set("long",@LONG
你對於空中有這種地方感到驚奇, 你環顧了你的四周,發現這裡除了幾本古書(books)
和一個鐵製的告示牌(sign)以外只有一些籐製桌椅, 你仔細看了一看, 顯然這裡是給初出
茅廬的新手教學用的也許你可以看看(look或l)告示牌或古書, 相信你會有所發現的....
LONG
    );
 set("exits",([
                "east":__DIR__"school2.c",
    ]));
 set("item_desc",([
        "books":"你看了看這些塵封已久的書, 發現它們照著編號排列, 你想應該從第一
本(book_1)開始看起.\n",
        "sign":"這面鐵製的告示牌寫著:!! 歡迎使用新手教室 !!.\n",
        "book_1":"這二本書主要是要告訴你一些新手應該知道的常識, 首先, Ds跟其它的
mud一樣, 新手務必要先看一看我們的規則(help rules), 因為你所玩的mud可以的
事項可能Ds不可以, 所以讀規則可以避免你無形中犯錯, 看到這裡, 你應該已經知
道這本書是要教你如何使用help, 你可以在普通情況下直接鍵入help, 接下來會出
現一些help主題, 你可以打help xxx再多知道一些詳情, 好了..這一本書教你如何
用help, 就到這裡, 接下來你就可以看第二本書(book_2)了.祝你一路順風....\n",
        "book_2":"好了, 這一本書是要教你如何和其它的玩家交談, 首先你可以使用chat
跟其它所有玩家交談, 也就你是你說的話所有玩家都會看到, 接著你也可以使用say 來跟跟
你在同一格的人交談, 只有你這格的人才看的到, tell <玩家名>可以使你的訊息只被這個
人看到, shout 的使用基本上和chat 差不多, 不太建議新手使用.... ok! 這本書就到此結
束....希望對你有所幫助....\n",
        ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
void init() { this_player()->set("not_newbie",1); }
