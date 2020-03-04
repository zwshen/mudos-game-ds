inherit ROOM;

void create()
{
	set("short", "山腳下");
	set("long", @LONG
你現在已經快要到達了紫陽山的山腳下，在之下偶爾會有幾片霧從
西方飄過來，常有一些花的種子就是這樣子從西方被霧吹至此地，聽說
這一種霧叫做隱霧，因為這種霧若隱若現常常被人所混淆掉，故其名。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"psin7.c",
  "south" : __DIR__"psin5.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
