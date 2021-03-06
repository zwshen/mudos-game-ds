
inherit ROOM;

void create()
{
        set("short", "錟都城中央水塘的步道東南角");
        set("long", @LONG
這裡是錟都城中央水塘步道西北角，而你正站在一個人工的小沙洲上，
往西和往北都可以到水塘的出口，往西北方向看去可以看到錟都城的地標─
噴水池。而你所立足的沙洲被水池的水所環繞，沙洲上種了一些竹子，十分
的詩情話意。
LONG
        );
        set("exits", ([                 
                "west" : __DIR__"city8",
                "north" : __DIR__"city6",
                                        ]));
                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

