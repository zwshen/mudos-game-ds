#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城南走道");
        set("long", @LONG
一陣陣清新的空氣緩緩的吹過來，漫步在這裡好比快樂天堂，你不禁
心想：【這裡的人還真會享受，沒被開發的城市果然適合休閒！】附近的
居民，不知道跑去哪裡了，諾大的街道竟然看不到一個人影，難不成都得
了[ 失心工作症 ]嗎。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
    "south":__DIR__"sec2.c",
    "north":__DIR__"sec4.c",
    "east":__DIR__"shop.c",
]) );
        set("light",1);

        setup();
        replace_program(ROOM);

}


