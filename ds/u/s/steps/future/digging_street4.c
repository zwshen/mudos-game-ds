inherit ROOM;
void create()
{
          set("short","住宅區小路");
          set("long",@LONG
前面就是住宅區的入口，雖然進去沒有什麼事做，不過都可以說是這
裡唯一值得走走的地方。而你從這裡走上去，就可去到連接到地球主城的
鐵路車站，回到主城去。
LONG
          );
               set("world", "future");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"district1",
  "eastup" : __DIR__"train_station1",
]));

	setup();
	replace_program(ROOM);
}
