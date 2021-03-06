// Room: /u/s/suez/tsing-yu/map_8_6.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
    由這裡往南，一條大街直直通往南邊的子午林，雖然子午林有著許多
詭異的傳說，但是由於北方土匪的出現，許多人便選擇了由南邊的子午林
繞路通往京城。以前平靜的南大街也因此熱鬧了不少。自從那場大戰之時
，所有居民便以廣場以南為據點來對抗北方而來的敵人，久而久之，這裡
以南就變成皴玉古城居民所居住之地，看著這裡安和樂利的生活，有如桃
花源般純樸的民風，讓人不禁也想在此定居，過著平凡但是快樂的生活。


LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "north" : __DIR__"map_7_6",
  "east" : __DIR__"map_8_7",
  "northwest" : __DIR__"map_7_5",
  "west" : __DIR__"map_8_5",
  "northeast" : __DIR__"map_7_7",
  "south" : __DIR__"map_9_6",
]));

	setup();
	replace_program(ROOM);
}
