// updated by alickyuen 27/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IWest[2;37;0m");
	set("long", @LONG
Å¥¨ì¤@¨Ç¹³¼s§iºqªººq¦±¡A´N©ïÀY¤@¬Ý¡Aµo²{¤ÑªÅ¤W¤@­Ó­Ó¼s§iªº²B
®ð²y¡A¦b¤j¤O«Å¶Ç¡C§A®³¨ì¤@±i¶Ç³æ¡A´N¬O»¡³o¸Ì·s¶}¤@±ø­¹ª«µó¡A¦Ó¥B
·s±i´Á¤º¦³¯S»ù¡A§A´N·Q§Ö¨Ç¶]¨ì¨º¸Ì¬Ý¬Ý¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dst16.c",
//  "northdown" : "/u/s/steps/area/door",  ¼È¤£¶}
  "east" : __DIR__"dst14.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
