inherit MOBROOM;

void create()
{
        set("short", "地底神殿遺跡");
        set("long", @LONG
矗立在你面前的，是一座巨大的乳白色門，其材質是無法判斷的
神秘物質，門面上的青綠色花紋雕著一幅大壁畫，畫中有一位手執巨
劍，遊俠裝扮的戰士正在與惡魔撒旦格鬥。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                   "north" : __DIR__"room-30",
                   "south" : __DIR__"room-22",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",15);
        set("mob_object",({
           __DIR__"../npc/mascot_lion",
        }) );
        set("light",1);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}



