inherit ROOM;
void create()
{
        set("short", "泊浪村民宅");        
        set("long",@LONG
這裡是泊浪村的一間民宅，有著一些木頭潮濕的味道，由於位於海
邊，因此常常房子都會受潮，不過這裡的海邊空氣卻十分新鮮，而且居
民都十分好客，如果有需要可以向他們借房間，這也是村間的一個有趣
之處。
LONG
        );

set("objects", 
([__DIR__ "npc/bou" : 1,
    ]));
set("exits", ([
  "east" : __DIR__"po14",
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}








