inherit ROOM;
void create()
{
        set("short", "後山");
        set("long",@LONG
這裡是屬於後山的地方，幾乎看起來是渺無人跡，動物也相當的多
，平時會來此地的大概只有獵戶或是一些採藥郎，所以景物都十分原始
，沒有一點人為雕琢的痕跡，給人和外面是兩個世界的感覺。
LONG
        );
  
set("exits", ([
  "out" : __DIR__"mu12",
  "eastdown" : __DIR__"mu15",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 






