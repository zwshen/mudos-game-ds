inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你來到了森林的東南邊，這裡的樹木十分稀少，感覺不太對勁的樣
子，從東南邊傳來一陣陣的怪聲，有什麼東西在呼喚著你前去，也許應
該前去看看，東南有一條路可以繼續前進。
LONG
        );
        set("exits", ([
  "north" : __DIR__"t13",
  "southeast" : __DIR__"t28",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}










