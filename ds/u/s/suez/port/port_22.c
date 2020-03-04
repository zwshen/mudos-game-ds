#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",MAG"拜坦之門"NOR);
        set("long",@LONG
在兩旁山壁之間，薩爾薩斯唯一的城門「拜坦之門」矗立於此，雖然
這個拜坦之門十分堅固，也挖了一條又深又寬的護城河，冠上了戰神之名
，甚至還加上了抗魔法的結界，但是從這裡出去是十分安全的平坦大道，
根本沒有需要這種城門，後來此門被戲稱為「薩爾薩斯最貴的垃圾」。
LONG 
);
        set("exits",([
            "west":__DIR__"port_21",
            //"east":__DIR__"",
                ]));
        set("no_magic", 1);
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
