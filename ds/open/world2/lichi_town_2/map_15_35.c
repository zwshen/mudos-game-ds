inherit ROOM;
void create()
{
	set("short", "���U");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_16_35",
	"north" : __DIR__"map_14_35",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
