inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_4_4",
	"west" : __DIR__"map_5_3",
	"south" : __DIR__"map_6_4",
	"east" : __DIR__"map_5_5",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
