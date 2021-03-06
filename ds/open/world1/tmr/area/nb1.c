// Room: /u/t/tmr/area/nb1.c

inherit ROOM;

void create()
{
	set("short", "鶴子橋口");
	set("long", @LONG
在你面前是一座築於朝天湖面上的長石橋，橋口有張石碑。向北遙望
，隱約在湖中有四五座房舍，建在一個不知是小島還是半島的陸地上。往
東是片大花叢，由於遍植花草樹木，景致迷人，卻大同小異，一不小心就
會在裡面迷路，當地居民也不敢亂闖進去。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "石碑" : "一張精雕細刻的石牌，上頭用朱砂寫著「鶴子橋」。
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"round4",
  "northup" : __DIR__"nb2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
