inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
藉著你身上光源所發出的微弱光芒，在這黑漆漆的地下遺跡中，
努力地探索著，古樸粗糙的大石塊堆砌成的牆壁，長滿了綠色的苔蘚
，不時滲出的地下水泉，寬廣的迷宮結構都讓人嘆為觀止。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-05",
                  "north" : __DIR__"room-08",
                  "southeast" : __DIR__"room-03",
        ]));
        set("objects",([
                   __DIR__"../npc/pf_demon" : 2,
                 ]) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}
