inherit ROOM;
void create()
{
        set("short", "泊浪村南側");
        set("long",@LONG
這裡是泊浪村的街道，往東邊是一家海產店，由於泊浪村靠海所以
新鮮的海產容易取得，因此此地的海鮮料理也是十分聞名的，常常有人
大老遠的來此享受一番，甚至皇室也有人愛好於此，路上常見有漁夫拿
著新鮮漁獲去賣給店裡來作料理，也算是泊浪村經濟來源了。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po3",
  "south" : __DIR__"po1",
  "east"  : __DIR__"po2e",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


