inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_5",
	"south" : __DIR__"map_12_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
