// Room: /u/s/suez/grave/path_8.c

inherit ROOM;

void create()
{
	set("short", "小石山徑");
	set("long", @LONG

小石山上綠草香，雲聚霧散洗玉陽，莫把風月破清謐，斌山婷婷到山崗。
小石遍落山徑邊，清風總拂清人面，村歌傲唱雨夜遲，總角還笑酒中仙。

這兩首是登小石山的文人寫的，就刻在山道旁的石碑上，說盡了小石山的
小巧峻麗，清新宜人。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"path_7",
  "eastdown" : __DIR__"path_9",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
