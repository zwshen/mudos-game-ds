inherit ROOM;
void create()
{
	set("short", "�o�󪺥۸�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_13_12",
	"north" : __DIR__"map_12_13",
	"east" : __DIR__"map_13_14",
	"south" : __DIR__"map_14_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
