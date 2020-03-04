inherit ROOM;
void create()
{
	set("short", "¤ì¾ô[0m");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_14_2",
	"north" : __DIR__"map_12_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //¥[¨ä¥L¨ç¦¡xxx()®É½Ð®³±¼¦¹¦æ
}

