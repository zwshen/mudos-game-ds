#include "path.h"
inherit ROOM;

void create()
{
        set("short", "處女宮");
        set("long", @LONG
這裡是黃道十二宮的第六宮 ─ 處女宮，在你眼前，是一位有如
天使般的美麗少女，難道，她就是此宮的守護者！？
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h12",
 "eastup" : HOLY+"h14",
        ]) );
        set("light",1);
        setup();
}
