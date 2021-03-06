// Room: /future/area/digging_road7.c

inherit ROOM;

void create()
{
	set("short", "礦山洞口");
	set("long", @LONG
你正站在此區採礦區的礦山洞口，在你左手邊是座極大的礦區，在西
邊、西南邊、西北邊各有三個洞口，為這通往礦山內部的三個採礦洞，不
時有礦工進進出出，搬運著採掘的礦產，礦洞裡也不時傳出陣陣鐵、石撞
擊的聲音，看得出來礦工們極是賣力工作。
LONG
	);
	set("world", "future");
	set("outdoors","desert");	
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
	  "southwest" : __DIR__"digging_road10",
	  "west" : __DIR__"digging_road9",
	  "northwest" : __DIR__"digging_road8",
	  "east" : __DIR__"digging_road6",	
           "south" : "/open/world3/kkeenn/secret-area/enter.c", // add by -Acme-
	]));

	setup();
	replace_program(ROOM);
}
