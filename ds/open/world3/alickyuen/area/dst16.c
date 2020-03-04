// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IWest[2;37;0m");
	set("long", @LONG
«n­±µo¥X¤F¹Ë§nªºÁn­µ¡A´Nª¾¹D¬O¤@³¡¾÷¾¹¦b»s³yªZ¾¹®Éµo¥Xªº¥¨ÅT
¡C¦Ó­»¨ý¤´µM¦b¥|³BÄÆ´²¡A¨Ï±o§A¦n¹³¹C»î¯ë·QÄÆ¹L¥h­¹«~µó¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"gate4.c",
  "south" : __DIR__"shop2.c",
  "east" : __DIR__"dst15.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
