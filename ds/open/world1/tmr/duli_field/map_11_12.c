inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_11",
	"north" : __DIR__"map_10_12",
	"east" : __DIR__"map_11_13",
	"south" : __DIR__"map_12_12",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
