#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
漫長的路段，另你感到無限的疲憊，這麼長的一段路走下來，你
的腳也起了許多的水泡，在前方的不遠處，不時傳來陣陣的獅吼，這
巨大的吼聲，恐怕就是獅子宮守護者所發出的。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h9",
 "westup" : HOLY+"h11",
        ]) );
        set("light",1);
        setup();
}
