inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_21_12",
	"north" : __DIR__"map_19_12",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
