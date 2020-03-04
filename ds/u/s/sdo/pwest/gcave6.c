inherit ROOM;

void create()
{
	set("short", "洞窟內通道");
	set("long", @LONG
你站在這裡，靠著牆上微弱的燭光，才發現原來兩條叉路走到這
裡還是會會合成一條通道，看來這個山洞構造滿奇特的，你不禁感嘆
造物者的巧思。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  		"northwest" : __DIR__"gcave7",
  		"southwest" : __DIR__"gcave4",
  		"southeast" : __DIR__"gcave5",
	]));

	setup();
	replace_program(ROOM);
}
