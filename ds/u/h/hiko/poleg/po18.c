inherit ROOM;
void create()
{
        set("short", "泊浪村東側");        
        set("long",@LONG
這裡是泊浪村廣場的東側的街道，在你面前有著一間十分大的建築
物，看起來該就是村長家，感覺起來跟村民的住宅一比相差甚大，令人
不僅懷疑起來，為何一個村長有著那麼多財力，不過還是只有進去瞧瞧
才知道因由了。
LONG
        );
        set("exits", ([  
"enter" : __DIR__"vi1",
"west" : __DIR__"po17",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








