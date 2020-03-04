#include <room.h>
inherit ROOM;
void create()
{
 set("short","花崗迴廊");
 set("long",@LONG
花崗迴廊四周都是遍佈的花崗岩, 地上有擺了一些小盆栽,
你偶爾可以看到幾隻小蝴蝶在這邊穿縮著. 你轉了一個彎來到
這個迴廊的轉角, 這邊有個婦人正在照料他的小盆景.
LONG
    );
 set("exits",([
               "north":__DIR__"hall2",
               "east":__DIR__"hall4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
