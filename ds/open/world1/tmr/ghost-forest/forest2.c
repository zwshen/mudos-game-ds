#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "林中分岐小路");  
	set("long", @LONG
只見小路於此往東北、西北二方向，分了二條而行，只見二邊盡是林
木，除了花草樹木，別無路標之類，而往北分岐的二條小路也無特異之處
，如要北行，實不知要往那一個方向行走才好。
LONG	
	);

	set("exits", ([ /* sizeof() == 3 */
	  "northeast" : __DIR__"forest3",
	  "south" : __DIR__"road1",
	  "northwest" : __DIR__"forest4",
	]));

        set("outdoors","forest");
    	set("no_clean_up", 0);
	setup();
}

void init()
{
	object ob;
	ob=this_player();

	if(!ob->query_temp("kneel_ghost") )
	{
		tell_object(ob,HIW"往南的方向忽然起了一陣白霧.......\n" NOR);
		set("exits", ([ /* sizeof() == 3 */
		  "northeast" : __DIR__"forest3",
		  "south" : __DIR__"road1",
		  "northwest" : __DIR__"forest4",
		]));
	}
	else
	{
  		ob->delete_temp("kneel_ghost");
		set("exits", ([ /* sizeof() == 3 */
		  "northeast" : __DIR__"forest3",
		  "south" : __DIR__"forest1",
		  "northwest" : __DIR__"forest4",
		]));

	}

}
