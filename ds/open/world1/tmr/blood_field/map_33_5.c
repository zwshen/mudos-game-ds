inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_32_5",
	"west" : __DIR__"map_33_4",
	"south" : __DIR__"map_34_5",
	"east" : __DIR__"map_33_6",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
