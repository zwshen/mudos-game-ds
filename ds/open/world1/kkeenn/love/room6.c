inherit ROOM;
void create()
{
        set("short", "情城池當鋪");
        set("long", @LONG
你來到一間城民居住的房子裡頭，家具擺飾都井然有序的陳放著，可
見這家的主人是多麼的細心，可惜，這裡東看西看，就只有女性，似乎整
個城中都只有女性而已吧。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"room2",  
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/dwller" : 3,
 __DIR__"npc/seller1" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

