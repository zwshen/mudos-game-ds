// Room: /open/world1/tmr/frost/temple.c

inherit ROOM;

void create()
{
        set("short", "寒澈道觀-正門口");
        set("long", @LONG
你正站在寒澈道觀的正門口，道觀造勢宏偉而自然，雖建在山林之間，
卻一點也沒喧賓奪主似佔出倚霄峰山林之美，有的是和大自然融合在一起而
散發出的美感。道觀正門由紅漆木製成，門口有二個小道僮正忙著打掃。
往南是一座高聳入雲的塔，給人虛無飄渺，雲深不知處的奇妙感覺。
LONG
        );
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/taoist-child" : 1,
]));
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"temple1",
  "west" : __DIR__"hill1",
  "south" : "/open/world1/tmr/endless/enter",
]));
        set("outdoors", "forest");
        set("current_light", 3);

        setup();
        replace_program(ROOM);
}

