inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_14",
	"east" : __DIR__"map_7_15",
	"north" : __DIR__"map_6_14",
	"west" : __DIR__"map_7_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
