inherit ROOM;

void create()
{
        set("short", "四號碼頭");
        set("long", @LONG
這裡是賽安尼爾斯的五號碼頭，整個碼頭用岩石與木頭搭建而成，
五號碼頭是往東方大陸航線的三個碼頭之一，停泊開往東方的船隻，碼
頭上豎立著大牌子，上面寫著【東方一號航線】。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room13", 
  "south":__DIR__"room11",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


