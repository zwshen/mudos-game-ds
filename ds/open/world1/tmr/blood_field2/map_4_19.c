inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_20",
	"west" : __DIR__"map_4_18",
	"south" : __DIR__"map_5_19",
	"north" : __DIR__"map_3_19",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
