inherit ROOM;
void create()
{
	set("short", "���� ");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_14",
	"north" : __DIR__"map_9_14",
	]));
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
