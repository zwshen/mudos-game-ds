inherit ROOM;
void create ()
{
        set ("short", "第十二宮雙魚座");
        set ("long",             @LONG

   ~?$$$$W:                x$$$$#
      ?$$$$u :           :$$$$#
        "$$$W           :$$$#~
          #$$$:        W$$$~
           #$$$       !$$$!                                             
            $$$X      $$$!   維納斯和丘比特有一次被巨人泰峰（ Typhon）所
            M$$$:: ::H$$$  追逐，雙雙跳入幼發拉底河中，化身為魚逃走。蜜妮
            !$$$$$$$$$$$$  華（ Mineave，雅典娜的別名）將魚化為星辰置於天
            !$$$"#"""$$$8  上，以紀念這件事。
            H$$$     ?$$$
            $$$?     ~$$$!
           W$$$       M$$$:
          W$$$~        #$$$:
        :$$$#           ?$$$x:
      xW$$$?             "$$$$u
    !R$$$#                 "*$$$!
LONG);
        set("exits", ([
      //  "northup"    :       __DIR__"topalace1",
        "east"  :       __DIR__"room24",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
           //     __DIR__"npc/pisces" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

