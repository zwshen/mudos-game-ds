inherit ROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_6",
	"west" : __DIR__"map_2_4",
	"north" : __DIR__"map_1_5",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
