inherit ROOM;
void create()
{
	set("short", "�i��i�ж�");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_2",
	"north" : __DIR__"map_1_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
