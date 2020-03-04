#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", HIC"花園"HIW"密室"NOR);
        set ("long", @LONG
你來到一間小小的花室，裡面栽種著各種不同的花朵
，香氣滿盈，令你心曠神怡，寵辱偕忘，把酒臨風，頓時
有即為歡樂與幸福的感覺。此時，一陣悠揚的歌聲從你前
方的小房間中傳來，你忍不住走了過去...
LONG);   
        set("light",1);
        set("exits", ([
        "south": __DIR__"flower_road1",
        "north": __DIR__"flower_room2",
                  ]) );
       
        setup();
        replace_program(ROOM);
}


