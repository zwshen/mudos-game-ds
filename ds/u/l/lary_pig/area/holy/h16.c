#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
前進、不斷的前進，腳底踏的，依然是無盡的階梯，你的身體，
因疲憊，已不存在任何的知覺，能夠支持你走到這裡的，是無比的堅
定意志，及強大的好奇心。
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h17",
 "westdown" : HOLY+"h15",
        ]) );
        set("light",1);
        setup();
}
