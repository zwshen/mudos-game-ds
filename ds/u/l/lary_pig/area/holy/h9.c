#include "path.h"
inherit ROOM;

void create()
{
        set("short", "巨蟹宮");
        set("long", @LONG
這裡是黃道十二宮的第四宮 ─ 巨蟹宮。抬頭仰望天空，你發現
，巨蟹座，在整個遼闊的宇宙中，算是十分暗淡的星座，但，相對的
，它所散發出的光芒，卻讓人感到無限的溫暖。
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h8",
 "westup" : HOLY+"h10",
        ]) );
        set("light",1);
        setup();
}
