// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IEast[2;37;0m");
	set("long", @LONG
³o¸Ì¥_­±¬O¤@¶¡¤j°s©±¡A¨º¸Ìªº³]³Æ«D±`§¹µ½¡A¥ç¬O«Ü¦h¤H´ç°²¦íªº
¦a¤è¡C¦Ó«e­±¨º¶¡©±çE¨ÌµM¤H¤s¤H®ü¡A¬Ý¨ÓÀ³¸Ó¬O¤@¶¡½æ­¹ª«ªº©±¡A§A·Q
¥i¯à¨º¸Ì¦³¦nªºªF¦è¡A´N·Q½Ä¹L¥h´ê´ê¼ö¾x¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"inn.c",
  "west" : __DIR__"dst6.c",
  "east" : __DIR__"dst12.c",
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
