#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"小當舖"NOR);
        set("long",@LONG
這是一家當舖, 在當舖的裡邊, 你可以看到在門口的兩側, 寫著『公平交
易』, 旁邊還有一個小小的木門，裡面似乎是放著一些貴重的物品, 只見掌櫃的
正細心的算著帳冊.
LONG
        );
        set("objects",([
  __DIR__"sellman":1,
]));
        set("exits",([
  "west" :__DIR__"road_11.c",
]));
        set("no_clean_up",0);
        set("light",1);
        setup();

}
