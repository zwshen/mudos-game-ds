inherit ROOM;
void create()
{
        set("short", "後山");
        set("long",@LONG
你到了後山中的叢林中，這裡枝葉茂密樹叢遮天，自然的生機
非常蓬勃，樹上不時有野猴跑來跑去，看來十分逗趣，這裡的景色
優美，讓你放開胸懷靜靜的悠遊其中。
LONG
        );
  
set("exits", ([
  "southdown" : __DIR__"mu21",
  "northup" : __DIR__"mu19",
  "eastdown" : __DIR__"mu22", 
]) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 







