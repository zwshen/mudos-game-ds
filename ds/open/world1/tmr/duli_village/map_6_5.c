inherit ROOM;
void create()
{
	set("short", "�����۸�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_4",
	"east" : __DIR__"map_6_6",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
