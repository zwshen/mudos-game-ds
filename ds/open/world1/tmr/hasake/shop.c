// shop.c 哈薩克小店 

inherit ROOM;

void create()
{
        set("short", "哈薩克小店");
        set("long", @LONG
這座帳篷略顯破舊，似乎搭好後主人就沒再修整過它。帳篷邊到是掛
了不少東西，牛皮筋，鈴鐺等等，看來這裡是個小雜品點。
LONG);
        set("exits", ([            
            "southwest" : __DIR__"pmchang.c",
        ]));        

        set("objects", ([
                    __DIR__"npc/dealer" : 1,
        ]));
        
        set("current_light", 1);
        set("light", 1);
        set("room_type", "shop");
        set("outdoors", "land");
        
        setup();
        replace_program(ROOM);
}
