inherit ROOM;
void create()
{
	set("short", "���s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_32",
	"north" : __DIR__"map_9_31",
	"west" : __DIR__"map_10_30",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
