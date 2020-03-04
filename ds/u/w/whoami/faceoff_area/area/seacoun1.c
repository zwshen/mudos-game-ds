#include <ansi.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short","此狶笵");
set("long",@LONG
眖硂柑┕狥ǐ碞穦礚马, 眖ê┕狥ǐ碞琌
↙瑅, τ┕﹁玥穦˙艶臔猠, オ常琌
厚猳猳此狶, 焚琌芠!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun2",
	"west":COMINGING_PAST+"area/river2",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
