inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_14_20",
	"west" : __DIR__"map_15_19",
	"south" : __DIR__"map_16_20",
	"east" : __DIR__"map_15_21",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
