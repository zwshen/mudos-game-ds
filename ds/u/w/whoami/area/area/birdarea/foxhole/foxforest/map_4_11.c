inherit ROOM;
void create()
{
	set("short", "�L�y");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_12",
	"west" : __DIR__"map_4_10",
	"north" : __DIR__"map_3_11",
	]));
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
