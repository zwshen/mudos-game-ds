inherit ROOM;
void create()
{
	set("short", "�L�����-�X��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_14",
	"north" : __DIR__"map_2_14",
	"west" : __DIR__"map_3_13",
	"east" : __DIR__"map_3_15",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
