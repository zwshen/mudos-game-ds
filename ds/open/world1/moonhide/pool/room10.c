inherit ROOM;

void create()
{
        set("short", "水寒星洞");
        set("long", @LONG 
這裡的景觀，在這裡更成一色，所有的東西都蓋上了白色的沙
子，一片雪白的景色，在你心中印下的美好的印象，且中間還有著
一塊大的『石頭』，不知道是做什麼用的。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room7", 
  "north" : __DIR__"room9",
]));
        set("light",1);
set("item_desc",([
"石頭":"長高寬都正好五寸的花鋼石，蠻漂亮的！？\n",
]) );

        set("no_clean_up", 0);

        setup();
}
