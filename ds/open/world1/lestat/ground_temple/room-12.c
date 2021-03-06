inherit MOBROOM;

void create()
{
        set("short", "地底神殿遺跡");
        set("long", @LONG
整個房間到處是斷垣殘壁，巨石林立，顯然是經過一些天災變動
，房間中瀰漫著一股腥羶味，不時從隱密處傳來的低吼聲，加上到處
都有骷髏跟血跡，不難推知這裡有些凶猛的生物存在。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                   "east" : __DIR__"room-13",
                   "south" : __DIR__"room-08",
                   "northeast" : __DIR__"room-15",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",15);
        set("mob_object",({
           __DIR__"../npc/saint_wolf",
        }) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}


