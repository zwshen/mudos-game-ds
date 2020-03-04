// Room: /u/k/kenshin/sha-zin-gu/room29.c

inherit ROOM;

void create()
{
        set("short", "練習場");
        set("long", @LONG
這裡是武學之家弟子們平常習武之地，除了可以看到這些努力不
懈的人在習武外，也能看到在地的師父耐心的教導，難怪此地的武學
風氣會如此盛行，這不是不會沒有原因的。
LONG
        );
        set("current_light", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room26",
  ]));
        setup();
        replace_program(ROOM);
}

