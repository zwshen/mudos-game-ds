#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "水果小舖");
        set("long", @LONG
一個以幾根木頭及麻布搭起來的簡易棚子，底下擺了一
箱箱的水果圍成了一圈，不要懷疑，這是一個道道地地的水
果舖，這些水果大多是當日從城外農民的田裡採收下來的新
鮮貨品。
LONG
        );
        set("exits", ([ 
                        "west" : __DIR__"wn1av1",
            ]));
           set("item_desc",([
"空紙箱" : "
一個空蕩蕩的紙箱，裡面有幾撮狗毛...\n",
                 ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
int room_effect(object me)
{

         switch(random(6))
        {
         case 0:
         write("一隻果蠅飛∼過來∼再飛∼過去∼，最後停在你的鼻子上...\n");
         return 1;
         default:       return 1;
        }
}


