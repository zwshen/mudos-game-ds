#include <ansi.h>
inherit ROOM;

void create()
{
set("short", HIY"星空"NOR);
        set("long",

     HIB"微風吹過，心曠神怡••來到這裡，坐在綠油油的草地上，
抬頭凝望這片美麗又皎潔的星空，有成千上萬數不完的星星正對
你眨著眼。那一邊的天空，又有一群美麗的流星雨，朝著你衝過
來。這樣的美景讓你舒服的睡著了•••\n"
HIY" •           .             .                    .               •
   •          •            .               •         •               .
.     .       •                     .                .         .\n"

        NOR);
        set("exits", ([
"out": "/d/wiz/hall1",
"start": "/open/world1/tmr/area/hotel",
        ]));
        set("light",1);
          set("objects",([
        ]));
        setup();
}

