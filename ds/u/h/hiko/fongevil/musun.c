inherit ROOM;
void create()
{
        set("short","山壁頂");
        set("long",@LONG
這裡看下去可以看清楚整個後山上的情形，而且讓人感覺非常舒服，
氣氛和下面完全不同，令人頗為納悶，四周仔細看了一下，你發現原來是
一顆大石發出的陽氣，讓人有一種十分燥熱的感覺。
LONG
        );
  
        set("exits", ([
            "down" : __DIR__"mu22",
            ]));
        set("objects",([
            __DIR__"sun-rock" : 1,
            ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}




