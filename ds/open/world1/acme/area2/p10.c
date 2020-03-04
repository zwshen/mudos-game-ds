// Room: /u/a/acme/area3/p10.c

inherit ROOM;

void create()
{
	set("short", "大廳");
	set("long", @LONG
這是裡施宅的大廳，四周牆上掛了許多名畫，和書法詩詞，正前方坐
著許多大人物，兩旁還有許多門派長老在此，不知發生了何事，要勞動這
些人來此聚會。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p5",
]));
       set("light",1);
set("objects",([
    __DIR__"npc/shi" : 1,
 __DIR__"npc/general" : 1,
__DIR__"npc/aw" : 1,
__DIR__"npc/lee" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
