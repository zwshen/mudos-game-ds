inherit ROOM;

void create()
{
        set("short", "七號碼頭");
        set("long", @LONG   
這裡是賽安尼爾斯的七號碼頭，整個碼頭用岩石與木頭搭建而成，
    七號碼頭是往東方大陸航線的三個碼頭之一，停泊開往東方的船隻
    ，碼頭上豎立著大牌子，上面寫著【東方三號航線】。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"street5",
  //"west" : __DIR__"hotel",
  //"north" : __DIR__"square",
  "east" : __DIR__"room16",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


