inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
原本寬廣的地下通道在這邊被打斷了，崩塌的牆壁與岩石堆滿了
整個通路，除了西北方有一個小小的縫隙之外，就沒有其他的出路了
，那個縫隙剛好可以讓一個人通過，大概是之前來探險的人所開發的
。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "west" : __DIR__"room-13",
                  "northwest" : __DIR__"room-15",
                  "south" : __DIR__"room-10",
        ]));
        set("objects",([
                   __DIR__"../npc/air_flame" : 1,
                 ]) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

