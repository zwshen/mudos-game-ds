inherit ROOM;
void create()
{
	set("short", "�w���L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_18_18",
	"south" : __DIR__"map_19_19",
	"east" : __DIR__"map_18_20",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
