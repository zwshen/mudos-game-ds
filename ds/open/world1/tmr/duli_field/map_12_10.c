inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_12_9",
	"north" : __DIR__"map_11_10",
	"east" : __DIR__"map_12_11",
	"south" : __DIR__"map_13_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
