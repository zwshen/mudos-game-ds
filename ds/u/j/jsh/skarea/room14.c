inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這裡是廢墟外的道路，雖然兩旁雜草叢生蓋住部份路面，但是可以看得出來以
前是條寬廣的大路，這條路往西可以到達港都 賽安尼爾斯。 
[此與東南方的維南族廢墟相連，暫未完工，故不開放]
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"east" : __DIR__"room7",  
  "northwest" : __DIR__"room13", 
  //"south": __DIR__"room9",
  //"north": __DIR__"room8", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


