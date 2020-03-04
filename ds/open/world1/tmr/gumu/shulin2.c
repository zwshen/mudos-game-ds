// shulin2.c 樹林
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "小樹林");
        set("long", @LONG
你走在一條林間的小道上，四周都是樹。遠處似乎有一角建築的
飛簷從樹叢中露了出來，也許附近的山上有一座道觀之類。這些樹你
大都叫不出名字來，樹齡都已經很長了。
LONG    );
        set("outdoors", "forest");
        set("exits", ([
                "southwest" : __DIR__"shulin3",
                "northeast" : __DIR__"shulin1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

