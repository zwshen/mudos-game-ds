#include <room.h>
inherit ROOM;
void create()
{
 set("short","登山陡徑");
 set("long",@LONG
你大約走了一刻鐘之後, 發覺自己的雙腳有點酸了, 因為
這個山路實在是太陡了, 而且路又寬, 往四周一望, 發覺大地
已經盡收你眼底, 而你上面不遠處正有大片的雲層籠罩著, 到
底還要走多久才能到山頂呢?
LONG
    );
 set("exits",([
               "eastdown":__DIR__"mount9",
               "southup":__DIR__"mount7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
