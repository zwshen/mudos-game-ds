#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
這是由金牛宮通往雙子宮的路上，你眼望前方有如無窮無盡的階
梯，你真感到有點後悔，為什麼你要來這鬼地方。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h5",
 "westup" : HOLY+"h7",
        ]) );
        set("light",1);
        setup();
}
