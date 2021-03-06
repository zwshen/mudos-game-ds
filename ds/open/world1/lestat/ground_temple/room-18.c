inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
潮濕黑暗的地道中，只有幾隻老鼠、蟑螂在活動，空曠的地下通
路中更加顯得冷清，若沒有你的來到，說不定這邊可能已經有幾百年
未見人蹤了，再往下走會是什麼狀況，不禁令人擔憂。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "northeast" : __DIR__"room-24",
                  "southwest" : __DIR__"room-15",
        ]));
        set("objects",([
                   __DIR__"../npc/wood_monster" : 1,
                 ]) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}
