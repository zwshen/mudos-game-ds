// Room: /u/l/luky/room/pearl_4.c
inherit ROOM;
void create()
{
set("short","[1;32m¬Ã¯]µóÂà¨¤[m");
set("long", @LONG

¡Ä¡Ä                                                   ¢¬ùþ
   :¢­        ³o¸Ì¬OºÑ¹pº¸ÂíªºªF«n¨¤¡A¦èÃä           ¢¬: ùþ
   : :¢j    ÄÆ¨Ó·L·Lªº¶ºµæ­»¡C±q³o¸Ì©¹¥_¬O         ¢y: : ùþ
=  : :¢j    ¬Ã¯]ªFµó¡A©¹¦è«h¬O¼ö¾xªº¬Ã¯]«n         ¢y: : ùþ
=  :¢¬      µó¡C                                     ¢­: ùþ
¡Ã¡Ã                                                   ¢­ùþ

LONG
);
set("objects",([
__DIR__"npc/pagurian":2,
]));
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pearl_5",
  "north" : __DIR__"pearl_3",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
