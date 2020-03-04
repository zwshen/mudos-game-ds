inherit ROOM;

void create()
{
        set("short", "防具之屋");
        set("long", @long
走進防具之屋，你停下腳步來慢慢的檢視所有的防具。在這裡有
著能夠大量強化自身防禦的盔甲和衣物，要從那麼多防具中選出一套
適合你的，似乎要花不少時間。

long);
        set("exits", ([
  "northwest" : __DIR__"ladder-1",
]));
        set("objects", ([ 
  __DIR__"item/equip_box.c" : 1,
]));

        set("light", 1);
        setup();
        set("stroom", 1);
}

