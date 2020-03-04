inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你越過剛剛的小路來到了一條綿延不絕的山路，看來還有許多的路
途要前進，雖然你想要看一下遠處的盡頭，可是卻因為霧茫茫而沒辦法
看到路通往何處，看來還有得走了。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"m2",
  "southwest" : "/open/world1/cominging/purple_sun/1f3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}




