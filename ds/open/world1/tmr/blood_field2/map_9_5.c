inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_6",
	"west" : __DIR__"map_9_4",
	"south" : __DIR__"map_10_5",
	"north" : __DIR__"map_8_5",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
