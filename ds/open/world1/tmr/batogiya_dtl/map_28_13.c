inherit ROOM;
void create()
{
	set("short", "�۾�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_28_12",
	"east" : __DIR__"map_28_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
