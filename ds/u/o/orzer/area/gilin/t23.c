inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
這裡已經是森林東邊的內側，感覺有著無聲的靜默感，似乎安靜的
的讓人有點無法置信，你覺得有些無法形容的詭異，東邊可以繼續往最
東邊前進，西南則是回頭，有一道若有似無的人影。
LONG
        );
        set("exits", ([
        "east" : __DIR__"t24",
        "southwest" : __DIR__"t17",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}












