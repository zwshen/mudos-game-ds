inherit ROOM;
void create()
{
	set("short", "������");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_19",
	"south" : __DIR__"map_9_18",
	"north" : __DIR__"map_7_18",
	"west" : __DIR__"map_8_17",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
