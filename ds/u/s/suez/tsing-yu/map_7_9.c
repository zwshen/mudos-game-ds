inherit ROOM;
void create()
{
	set("short", "��D");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_10",
	"south" : __DIR__"map_8_9",
	"north" : __DIR__"map_6_9",
	"west" : __DIR__"map_7_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
