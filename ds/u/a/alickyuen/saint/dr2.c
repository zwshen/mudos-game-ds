// Room: /u/a/alickyuen/area/dr2.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Door");
	set("long", @LONG
這裡就是醫院的大門口，一些受重傷的人都由這裡緊急的送進去，還
有一些人帶著生果籃的人進去探望自己的親友，人來人往，可能就是因為
只有一間大的醫院，所有的人都進來這裡受醫，可見這間醫院的先進和給
病人的信心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dr1",
  "in" : __DIR__"dr3",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
