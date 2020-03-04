#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","薩爾薩斯紀念碑");
        set("long",@LONG
那塊紀念碑，不知道在多久以前就崩毀了，也沒人知道上面是寫些什
麼，紀念著什麼。傳說這個紀念碑在薩爾薩斯有人之前就存在了。現在這
裡則是商人們招募水手的地方，也有許多冒險者在此作最後的檢查。
LONG 
);
        set("exits",([
            "east":__DIR__"port_12",
            "west":__DIR__"port_08",
            //"south":__DIR__"port_05",
                ]));
        set("objects",([
            __DIR__"npc/ad_wm":1,
            __DIR__"npc/waterman":3,
            __DIR__"npc/ad_mn":1,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
       if( dir=="east" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}

