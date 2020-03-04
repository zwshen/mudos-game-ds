// Room: /u/a/acme/workroom1.c

inherit ROOM;

void create()
{
	set("short", "¯«ªZ±Ð");
	set("long", @LONG


¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼
¡¼       ¡½¡½¡½       ¡½         ¡½¡½¡½¡½  ¡½  ¡½       ¡¼
¡¼                    ¡½                    ¡½          ¡¼
¡¼     ¡½¡½¡½¡½¡½ ¡½¡½¡½¡½¡½   ¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½     ¡¼
¡¼         ¡½     ¡½  ¡½  ¡½       ¡½        ¡½         ¡¼
¡¼       ¡½¡½¡½   ¡½¡½¡½¡½¡½       ¡½        ¡½         ¡¼
¡¼      ¡½ ¡½ ¡½  ¡½  ¡½  ¡½       ¡½¡½¡½     ¡½        ¡¼
¡¼     ¡½  ¡½  ¡½ ¡½¡½¡½¡½¡½    ¡½ ¡½         ¡½        ¡¼
¡¼         ¡½         ¡½        ¡½ ¡½          ¡½  ¡½   ¡¼
¡¼         ¡½         ¡½      ¡½¡½¡½¡½¡½¡½      ¡½¡½    ¡¼
¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"workroom.c",
]));
        set("objects",([
              "/open/world1/acme/area/npc/general" : 1,
              "/open/world1/acme/area/npc/general2" : 1,
              "/open/world1/acme/area/npc/general3" : 1,
              "/open/world1/acme/area/npc/general4" : 1,
              "/open/world1/acme/area/npc/general5" : 1,
              "/open/world1/acme/area/npc/general6" : 1,
              "/open/world1/acme/area/npc/general7" : 1,
              "/open/world1/acme/area/npc/general8" : 1,
//              "/open/world1/acme/area/npc/liu" : 1,
              "/open/world1/acme/area/npc/oldman.c" : 1,
           ]));
	set("no_clean_up", 0);
         set("light",1);

	setup();
	replace_program(ROOM);
}
