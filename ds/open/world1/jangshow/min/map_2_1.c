inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_1",
	"east" : __DIR__"map_2_2",
	"north" : __DIR__"map_1_1",
	]));
        set("objects",([
        __DIR__"magma":5,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
