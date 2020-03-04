#include <ansi.h>
inherit ROOM;

void create()
{
set("short","愛門村小路");
        set("long", @LONG
這是一條經過小麥田的泥土小徑，這附近的農舍比起北邊就稍微少了一
些。在路邊有著幾隻蚯蚓正在爬動，勤勞地翻著土壤。還有幾個木藤編成的
籃子就放在那裡，看來是採收杏果時用的工具。
LONG
        );
        set("exits", ([
     "east":__DIR__"al5",
     "west":__DIR__"al7",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
