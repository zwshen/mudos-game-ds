inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你來到了森林的東南邊，這裡的樹木十分稀少，感覺不太對勁的樣
子，這裡就是怪聲的傳出地點，你面前有著一個樵夫，他似乎受了一點
傷，呼喚著你的也許就是他的呻吟聲。
LONG
        );
        set("exits", ([
  "northwest" : __DIR__"t14",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}









