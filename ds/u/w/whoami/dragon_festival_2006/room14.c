inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"桃花洞"NOR);
  set("light",1);
        set("long", @LONG

    桃花洞是個土洞，位於玉笥山麓。洞穴裡面涼爽宜人，相傳從前屈
原在盛夏酷暑之時，常來此洞讀書養性，賦詩明志。

LONG
        );
    set("exits",([
 "northwest" : __DIR__"room13",
 "southwest" : __DIR__"room15",
]));


        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}
