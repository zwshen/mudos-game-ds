// caoyuan6.c 草原
inherit ROOM;
void create()
{
        set("short", "大草原");
        set("long", @LONG
你走進了這遍綿綿不絕的大草原，腳下是寸厚的青草，軟綿綿的還真
不好走，看來買匹馬來代步到是的好主意。
LONG);
        set("exits", ([
           "northeast" : __DIR__"road2",
//            "north" : __DIR__"room-ji",
            "east" : __DIR__"caoyuan5",
        ]));
        set("outdoors", "land");
        setup();
        replace_program(ROOM);
}
