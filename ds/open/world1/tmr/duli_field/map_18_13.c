inherit ROOM;
void create()
{
	set("short", "���a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_17_13",
	"east" : __DIR__"map_18_14",
	"south" : __DIR__"map_19_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
