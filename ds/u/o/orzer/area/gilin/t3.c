inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你繼續向森林西邊邁進，森林內就連動物也都頗為不尋常，彷彿整
個森林都受到了詛咒，四周都死氣沉沉的，這樣的森林實在是讓人提不
起勁，因此也讓你想一查究竟，西北和西南都各有一條路。
LONG
        );
        set("exits", ([
  "northwest" : __DIR__"t6",
  "southwest" : __DIR__"t4",
  "east" : __DIR__"t2",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}







