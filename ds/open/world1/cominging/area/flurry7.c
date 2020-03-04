inherit ROOM;

void create()
{
	set("short", "西走廊");
	set("long", @LONG
這裡是疾風門的側走郎，在這裡有許多的衛兵來回走動，在南方有
間房間，裡面並沒有燈火光明，似乎沒有人住的樣子，東邊是走廊，西
邊也還是走廊...。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry8.c",
]));
	set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
