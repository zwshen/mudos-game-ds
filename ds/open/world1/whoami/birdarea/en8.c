// Room: /open/world1/whoami/birdarea/en8.c

inherit ROOM;

void create()
{
	set("short", "[1;37mªF¥_[2;37;0m¿AªL");
	set("long", @LONG
§A²{¦b¨Ó¨ì¤@³Bº¡¬O¤g¥Û¶ôªº¦a¤è¡A¤@°}°}ªº§N­·¼³­±¦Ó¨Ó
¡A¦ý¬O°£¤F«¦«¦ÅTªº­·Án¡A´N¦A¤]¨S¦³¨ä¥¦¥ô¦óÁn­µ¤F¡AÀR®¨®¨
ªº®ðª^·tÂÃ¤F¤@µ·µ·®£Äß·P¡C§Aª`·N¨ì¦b¸ô®Ç±×´¡µÛ¤@¶ô¤ìµP¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"en7",
  "north" : __DIR__"en9",
]));
	set("outdoors", "forest");
	set("no_clean_up", 0);
	set("mob_object", ({ /* sizeof() == 1 */
  __DIR__"npc/fox"
}));
	set("chance", 80);
	set("mob_amount", 3);
	set("current_light", 2);
	set("mob_max", 15);
	set("item_desc", ([ /* sizeof() == 1 */
  "¤ìµP" : "§A´Â³o¤ìµP¬Ý¤F¬Ý, µo²{¤W­±¦³´X­Ó¤j¦r,

       [1;31mª° ¯W ¥Þ     [5m[1;31m¥Í¤H¤Åªñ[2;37;0m

§A¤£¸T§N¦½ª½¬y, §A·Q·Q¤]³\¸Ó¦^ÀY¤F.
",
]));

	setup();
	replace_program(ROOM);
}
