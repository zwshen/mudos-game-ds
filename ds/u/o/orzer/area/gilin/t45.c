inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
你慢慢的朝向森林深處走去，人型生物也越來越多，從他們看來雖
然不太有意識，卻還是會攻擊來往的人，彷彿在保衛著什麼東西一般，
似乎也就是這股執念，讓他們繼續行動下去。
LONG
        );
        set("exits", ([
        "northwest" : __DIR__"t41", 
        "southwest" : __DIR__"t46",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














