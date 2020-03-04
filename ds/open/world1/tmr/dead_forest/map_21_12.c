inherit ROOM;
void create()
{
	set("short", "¤ì¾ô[0m");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_21_13",
	"west" : __DIR__"map_21_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //¥[¨ä¥L¨ç¦¡xxx()®É½Ð®³±¼¦¹¦æ
}

