#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻部落"NOR"－"HIG"大門"NOR);
 set("long",@LONG 
來到這裡，往前一望，有一個大大的用竹子做的大門，裡面
似乎是個部落。但這種部落卻十分少見，住家房子的屋頂較高級
的就用竹子搭建，叫普通的卻只有用稻草堆覆蓋。
LONG
    );
 
 set("exits",(["north":__DIR__"town2",
           ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

