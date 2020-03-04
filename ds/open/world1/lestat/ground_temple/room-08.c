inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
一陣奇怪的白色煙霧從西邊飄來，混雜著燒焦味，烤肉香，以及
一股莫名的氣息，還有溫暖的熱風，肚子早已咕嚕咕嚕叫的你，不自
覺得想往西邊去尋找味道的來源。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "west" : __DIR__"room-07",
                  "north" : __DIR__"room-12",
                  "south" : __DIR__"room-04",
        ]));
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

