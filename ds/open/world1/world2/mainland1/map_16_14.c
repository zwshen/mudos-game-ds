inherit ROOM;
void create()
{
	set("short", "���~�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_16_13",
	"south" : __DIR__"map_17_14",
	"north" : __DIR__"map_15_14",
	"east" : __DIR__"map_16_15",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
