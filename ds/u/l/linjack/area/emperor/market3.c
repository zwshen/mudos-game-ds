#include <room.h>
inherit ROOM;
void create()
{
 set("short","武器鋪聚集地");
 set("long",@LONG
原來這邊是皇城東北方十分出名的武器集散地, 城裡許多商店
的物品來源都是由此地而來, 你也能看到許多旅客或江湖人士在這
邊挑東挑西的. 這邊雖然沒有賣什麼高級的寶刀寶劍, 可是貨品齊
全, 普通江湖人會用的武器在這邊大都可以找到.
LONG
    );
 set("exits",([ "southwest":__DIR__"road8",
                "southeast":__DIR__"market2",
                "northeast":__DIR__"market1",
                "east":__DIR__"center"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}