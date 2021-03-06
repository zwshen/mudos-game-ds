inherit MOBROOM;

void create()
{
        set("short", "地底神殿遺跡");
        set("long", @LONG
延續之前的建築風格，乳白色的牆壁上刻著青綠色的怪異螢光花
紋，你判斷這大概是遠古時代的古文字，近代幾乎已經沒有人懂得這
文字了，因此無法得知這些文字的意義以及整個建築的由來。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                   "northeast" : __DIR__"room-31",
                   "southeast" : __DIR__"room-24",
                   "northwest" : __DIR__"room-30",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",15);
        set("mob_object",({
           __DIR__"../npc/crazy_elephant",
        }) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}



