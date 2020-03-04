#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIC"古文觀止－"HIY"捕蛇說。"NOR);
        set("long", @long

永州之也產異蛇，黑質而白章，觸草木盡死，以齧人，無禦之者。
然得而腊之以為餌，可以已大風、攣腕、瘺、癘，去死肌，殺三蟲。
其始太醫以王命聚之，歲賦其二。募有能捕之者，當其租入。永之人爭奔走焉。

long    );
        set("exits", ([
  "baal": "/u/b/baal/workroom.c",
  "wiz": "/d/wiz/hall1.c",
  "c_hotel": "/open/world1/tmr/area/hotel.c",
  "q": "/u/u/uchimaha/workroom.c",
  "luky": "/u/l/luky/workroom.c",
  "alick": "/u/a/alickyuen/workroom.c",
]));
  set("objects", ([ __DIR__"coming_b.c": 1, ]));
        setup();
//        call_other("/obj/board/coming_b.c", "???");
}

void init()
{
        if( userp(this_player()) )
                call_out("delay", 0, this_player());
}

void delay(object me)
{
        string str;
        if( str = read_file(__DIR__"qlist") )
                write(HIG"\t:::: Incoming "HIY"Quest List "HIG"::::\n\n"NOR+
                        str+ NOR +"\n");
}

void w(string a)
{ write_file(__DIR__"translate_log", a); }

