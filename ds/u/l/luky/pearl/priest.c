// Room: /d/cham/mguild.c

#include <ansi.h>
#include <path.h>
#include <room.h>
inherit ROOM;
inherit F_GUILD;
void greeting();
void create()
{

set("short","[1;34m¡i[32mªª®v¤u·|[34m¡j [0m");
set("long", @LONG

    ³o¸Ì¬Oªª®v¤u·|¡CÂ²³æªºÂ\³]Åã¥Ü¥X¯«Â¾¤H­û¤@³eªº¾ë¹êºë¯«, ¤@¨«¶i³o
¸Ì, §A¥ß¨èª`·N¨ì¤jÆU¤¤¥¡ªº¤@®y¥¨¤jªº­C¿q°ò·þÀJ¹³, ¨â®Ç©ñ¤F³\¦hªº®y´È
¨Ñ¤H¦b¦¹Ã«§iÄb®¬¡C³o¸Ìªº¿O¥ú¦³¨Ç©ü·t, «Ü®e©ö¯àÅý¤Hªº¤ß±¡¥­ÀR¤U¨Ó¡C

LONG
);
set("exits", ([ /* sizeof() == 1 */
"east":__DIR__"pearl_37",
]));
set("objects",([
LUKY+"pearl/npc/clemaster":1,
]));
set("light",1);


      set("valid_startroom", 1);
    set("no_clean_up", 1);

	setup();
replace_program(ROOM);
}
/*
void init()
{
greeting();
}
*/

/*
void greeting()
{
if(this_player()->query("birthday"))
if(this_player()->query("level")>35)
{
write(HIY"ªù¤fªº¦u½Ã¾×¦í§A,¤£Åý§A¶i¨Ó\n"NOR);
this_player()->move("open/clc/room1/road6");
}
if(this_player()->query("pet"))
this_player()->move("open/clc/room1/road6");
}
*/
