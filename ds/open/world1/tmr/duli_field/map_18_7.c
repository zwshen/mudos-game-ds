inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_18_6",
	"north" : __DIR__"map_17_7",
	"east" : __DIR__"map_18_8",
	"south" : __DIR__"map_19_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
