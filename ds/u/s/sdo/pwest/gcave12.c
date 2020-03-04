inherit ROOM;

void create()
{
	set("short", "洞窟內");
	set("long", @LONG
這裡的牆邊和地上，被水沖刷過的痕跡比在中間還來的明顯，看
來這個洞窟以前果然是地下河道的一部分，只是現在河水水位大概退
到更下面去了吧。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"gcave13",
  "northwest" : __DIR__"gcave9",
  "west" : __DIR__"gcave10",
]));

	setup();
	replace_program(ROOM);
}
