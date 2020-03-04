// pray_bridge.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"神殿之橋"NOR);
        set("long",@LONG
  這條猶羅村的神殿之橋路從這裡向西走是神殿。
你正站在一個橋上，向下望去是個湖，原來神殿是
建在湖的正中央。湖水清澈有如自來水一般，裡面
有著幾隻金魚在游泳，湖面上還有許多小水鴨在游
水自由自在的樣子令人神往。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"pray_st2",
                "west"    : __DIR__"pray_bd1",
                ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
