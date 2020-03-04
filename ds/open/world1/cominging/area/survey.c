// Room: /open/world1/cominging/area/survey.c

inherit ROOM;

void create()
{
	set("short", "¨BÆF«°­ÁÀý¥x");
	set("long", @LONG
³o¸Ì¬O¨BÆF«°¤¤³Ì¥j¦Ñªº»»±æ¥x¡A¦b³o¸Ìªº©P³ò¬O¥Ñ¦Ë¤ì©Ò¿v¦¨ªº
¡A¦ü¥G¦³ÂI®e©ö­Ë¶òªº¼Ë¤l¡A¦b³oªº¥|©P¦³³\³\¦h¦hªºµ¡¤á(windows)
¡A¥i¥H±æ¦V¨BÆF«°ªº¥|©P¡A¦b±ß¤W®Éªº©]´º¤]¥iºÙªº¬O½«¬°¤@Æ[¡A¥i¤]
¬O¨BÆF«°¤¤¯S§OÁcºaªº´º¶H¡A¦bÀð¾À¤W¦³³\¦h¦a¹Ï¡A¤]¦³³\¦h¤Hªº§@¸Ö
¡A»á¦³¨Ç·R°êªº·PÄ±¡A¦b§Aªº¸}¤U¬O³q©¹¼s³õªº¼Ó±è¡A®ÇÃäªºÀð¤W¦³µÛ
¤@¤ù¤p¯È±ø(scrip)¡C
LONG
	);
	set("god_club_enter", 1);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"survey_out",
  "down" : __DIR__"boo-lin.c",
]));
	set("current_light", 1);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/minstrel.c" : 1,
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "windows" : "³o¬O¤@­Ó¥Ñ¦Ë°µ¦¨ªºµ¡¤á¡A¦ü¥G¥i¥H±q³o¸õ¤U(jump)¨ì«n¤jµó¡C
",
  "scrip" : "[1;36m¤p¯È±ø¤W­±¼gµÛ¡G
[1;32m¥i¥H¥Î singing ¨ÓÅý§Ú°Û¨Çºq¦±©Î ( talk with geisha ) §Ú±N§i¶D§A§Ú·|°Ûªººq¡C
[0m",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
