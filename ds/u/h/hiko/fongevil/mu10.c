inherit ROOM;
void create()
{
        set("short", "山道");
        set("long",@LONG
你已經可以看清楚山上的景物了，一望而去皆是野墳，而且一堆堆的
極為眾多，原來此地是亂葬岡，仔細感覺竟然有些陰森，令你有些打些前
進的念頭，北邊有一條路往山崗，東南邊則是下山。
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"zk22",
  "southeast" : __DIR__"mu9",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





