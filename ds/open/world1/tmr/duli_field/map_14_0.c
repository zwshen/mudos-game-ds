inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_13_0",
	"east" : __DIR__"map_14_1",
	"south" : __DIR__"map_15_0",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
