inherit ROOM;

void create()
{
        set("short", "大廳");
        set("long", @LONG 
這裡是古墓派主人之一 [36m「小龍女」[0m 的房間，在這房間的中上方，有一�
條長十尺八寸的粗麻繩，據說小龍女睡覺  休息跟練功，都是在這條長長的
繩子上，輕功造詣，不可輕視 。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
//      "east" : __DIR__"room4",
      "northeast" : "/open/world1/tmr/gumu/mudao02", // 新古墓 2006/10/23
]));
        set("objects", ([ /* sizeof() == 1*/
  __DIR__"dragongirl" : 1,
]));      
        set("no_clean_up", 0);
        setup();

}

