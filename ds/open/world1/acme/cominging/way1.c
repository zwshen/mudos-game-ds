inherit ROOM;

void create()
{
	set("short", "長道");
	set("long", @LONG
你走到這，發現還是有些官兵走動，不時有些民眾前來申冤，或者
是賄賂，都帶著大箱的金銀珠寶前來貢獻，還有些碎銀掉在地上，卻都
也沒人撿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"way2",
  "south" : __DIR__"bigdoor",
]));
	set("no_clean_up", 0);
	set("item_desc",([
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}
