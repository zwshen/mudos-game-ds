inherit ROOM;

void create()
{
set("short", "愛門村小路");
        set("long", @LONG
這是一條泥土路，你兩邊都是農舍，幾乎都是用紅磚瓦配上灰泥建蓋成
的。這裡的灰泥非常獨特，是用沙子混上麥稈、杏仁和水磨成，乾了之後便
成為相當堅硬的灰泥，而且不失其延展性。此處東南邊那間農舍便是村長的
住屋，也許可以前去打聽消息。
LONG
        );
        set("exits", ([
     "north":__DIR__"al2",
     "south":__DIR__"al4",
     "east":__DIR__"r1",
]));
        set("objects", ([
        __DIR__"npc/dog" : 1,
]));


        set("outdoors","land"); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
