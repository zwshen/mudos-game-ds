// Room: /open/world1/tmr/bagi/ghat11.c

inherit ROOM;

void create()
{
	set("short", "林地");
	set("long", @LONG
你正站在一處頗寬闊的林地裡，四周圍滿了峰頂上常見的針葉樹，如
水衫、水松或是馬尾松等常見的耐寒樹種，原本凜冽而威勢不斷的寒風在
此由於林木的阻隔，風勢似乎就收斂許多了。
LONG
	);
	set("outdoors", "snow");
	set("no_clean_up", 0);
	set("current_light", 4);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ghat12",
  "southeast" : __DIR__"ghat10",
]));

      set("objects",([
         __DIR__"npc/woodman":1,
      ]) );

	setup();
	replace_program(ROOM);
}
