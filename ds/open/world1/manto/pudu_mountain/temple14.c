inherit ROOM;

void create()
{
        set("short", "小石台");
        set("long", @LONG
緩步在林中行走，越走越順，林中亦發稀疏，踏著松針，很快來到至
幾株華蓋頂天、蚺枝纏繞的蒼松之下。一隻白鶴正站在樹下石桌之上，單
腿而立，長頸曲後，細長地尖嘴輕輕梳理著身上羽毛，羽毛潔白如雪。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"temple13",
  "south" : __DIR__"temple12",
]));

 set("objects", ([
 __DIR__"obj/table" : 1,
 __DIR__"obj/seat" : 2,
 ]));
        set("outdoors", "land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
} 
