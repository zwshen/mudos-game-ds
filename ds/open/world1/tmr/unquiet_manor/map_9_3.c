inherit ROOM;
void create()
{
	set("short", "�L�����-�X��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_3",
	"north" : __DIR__"map_8_3",
	"west" : __DIR__"map_9_2",
	"east" : __DIR__"map_9_4",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
