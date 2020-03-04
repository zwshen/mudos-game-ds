inherit ROOM;

void create()
{
        set("short", "二號碼頭");
        set("long", @LONG
這裡是賽安尼爾斯的二號碼頭，整個碼頭用岩石與木頭搭建而成，
賽安尼爾斯鄰近皮斯活火山，屬於岩岸，很適合作為港口，許多經商的
船隻都在此地停泊，碼頭旁的木牌寫著【南洋航線】。 
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room5",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


