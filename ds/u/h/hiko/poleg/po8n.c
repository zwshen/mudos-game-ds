inherit ROOM;

void create()
{
set("short", "迎波當鋪");
set("long", @LONG
這裡是泊浪村內的一家當舖，仔細一看也蠻舊了，看得出來已經有
相當年代，聽說是經營了許多代了，而當鋪主人也是非常歷經風霜，不
過由於價格公道因此人們也蠻樂意和他做生意，算是泊浪村的一個老店
了。
LONG
        );
set("exits", ([ 
    "south" : __DIR__"po8",
]));
set("objects", ([__DIR__ "npc/sellsman" : 1,
    ]));

set("room_type","shop");
set("no_clean_up", 0);
set("light",1);
setup();
}


