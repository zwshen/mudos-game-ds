
inherit ROOM;
#include <ansi.h>
void create()

{
        set("short", WHT"汨羅江邊"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    此處可俯瞰屈原自沉的汨羅江。江水靜靜地流經一片油綠的草坪，
江邊還有幾個牧童放牛。微風中，彷彿可以聽到憤慨的悲鳴：「黃鐘毀
棄，瓦釜雷鳴，讒人高張，賢士無名。」一旁的獨醒亭讓《九歌》裡的
一幕幕湘君神話在你腦中躍動。

LONG
        );
    set("exits",([
 "south" : __DIR__"room03",
 "enter" : __DIR__"room01",
]));
        set("objects", ([ 
  __DIR__"npc02" : 1,
]));
        set("no_clean_up", 1);
        setup();
        replace_program(ROOM);
}
