#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"情城池側廳"NOR);
        set("long", @LONG
這裡是情城的初級練功場，這兒地域廣大，一眼望去，盡是練
功場，練功場上有許多的情城池弟子在練鞭或者練內功，抑或在研
究感情，其中也包含了武林中人來請教，但是奇怪的就是沒有男性
的武林人士，練功場旁邊都有一個放著一條條的鞭子，上面放著許
多斷掉或壞掉的鞭類武器。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"room11", 
]));
set("light",1);
        set("objects", ([
 __DIR__"npc/app2" : 2,
]));
         set("no_recall",1);
        setup();
        replace_program(ROOM);
}
