inherit ROOM;

void create()
{
        set( "short", "地底洞穴") ;
        set( "long", @LONG
陰森森的氣息一直從前方的通道中湧來，陰風陣陣，夾雜著各種
奇怪的聲音，讓人毛骨悚然，心中直犯嘀咕，該不會是碰上好兄弟了
吧？
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "up" : __DIR__"room-51",
                  "north" : __DIR__"room-34",
        ]));
        set("light",0);
        set("no_clean_up", 0);
        
        setup();
}


