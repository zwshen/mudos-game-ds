inherit ROOM;
void create()
{
	set("short", "�H�۸�");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_2",
	"north" : __DIR__"map_5_2",
	"east" : __DIR__"map_6_3",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
