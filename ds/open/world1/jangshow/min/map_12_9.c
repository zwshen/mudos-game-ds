inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG

LONG
);
        set("exits",([
       "out":"/open/world1/jangshow/flame_area/room",
        "east" : __DIR__"map_12_10",
        "north" : __DIR__"map_11_9",
        "west" : __DIR__"map_12_8",
        ]));
        setup();
        set("map_long",1);     //show map as long
}

int valid_leave(object me, string dir)
{
       if( dir == "out" && me->query("id") == "magma man" || me->query("id") == "afflated" && dir == "out" )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}


