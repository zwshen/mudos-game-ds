inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_11",
	"north" : __DIR__"map_3_12",
	"south" : __DIR__"map_5_12",
	"east" : __DIR__"map_4_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
