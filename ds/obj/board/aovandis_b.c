#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name("奧凡迪斯公佈欄",({"board"}));
        set("location","/open/world2/shengsan/aovandis/room079");
        set("board_id", "aovandis_b");
        set("long",
        "一個很大的黑板，上面還有一些粉筆。任何人有事都能在上面留言的。\n");
        setup();
        set("capacity",70);
 
}

