#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",BLU"燈塔二樓"NOR);
        set("long",@LONG
二樓天花板的正中央，一個巨大的齒輪在中央，旁邊還有一些較小的
奇怪機械，看起來像是金屬做的，但是在這之前有如此發達的金屬工藝技
術嗎？看著那精巧的組合，你不禁懷疑這個燈塔其實是矮人族的作品。房
間一角有一個通往三樓的階梯，看起來似乎是最近才放置於此。
LONG 
);      
        set("light",0);
        set("exits",([
            "up":__DIR__"port_a3",
            "down":__DIR__"port_a1",
                ]));
        set("objects",([
             __DIR__"npc/bat":3,
                ]));
        set("world","world1");

        setup();
        replace_program(ROOM);

}

