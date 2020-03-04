inherit ROOM;

void create()
{
	set("short", "疾風門");
	set("long", @LONG
這裡是疾風門的入口進去最先到達的地方，為了預防刺客，小偷等
人，所以這邊也有一些衛兵在來回巡邏監視，在東方是一條小走廊，而
西方也是一條小走廊，這裡的地很廣大，令人不禁稱奇。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"flurry9.c",
  "south" : __DIR__"flurry2.c",
  "north" : __DIR__"flurry10.c",
  "east" : __DIR__"flurry4.c",
]));
	set("objects",([
  __DIR__"npc/fguard.c" : 3,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	call_other("/obj/board/flurry_b.c","???");
}
