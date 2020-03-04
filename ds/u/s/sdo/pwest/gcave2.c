inherit ROOM;

void create()
{
	set("short", "洞窟內叉路");
	set("long", @LONG
這裡是洞窟裡的叉路之一，狹小的通道讓人感覺有點不舒服，但
是不算難走，尤其是地面還頗為平坦，好像有人常常在這裡行走一樣
。可是依稀有一些危險的氣味，讓你不禁戒備起來。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"gcave4",
  		"southeast" : __DIR__"gcave1",
	]));

	setup();
	replace_program(ROOM);
}
