// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;36mST¡DRecycleStation¢IRobot[2;37;0m");
	set("long", @LONG
³o¸Ì¬O¤@¶¡°£¤F¤£­È¿úªºªF¦è¤§¥~¡A¤°»ò³£·|¦^¦¬ªº¦^¦¬«Î¡C¦Ó³o¸Ì
ªº¦^¦¬»ù®æ©M¨ä¥Lªº³£¬O¤@¼Ë¡A©Ò¥H³£¤£·|¥X²{§äÄò¤Wªº°ÝÃD¡C¦Ó³o¸Ìªº
¦^¦¬¤u§@¬O¥Ñ¾÷±ñ¤H­t³d¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dst9",
]));
set("light",1);
	set("world", "future");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/seller.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
