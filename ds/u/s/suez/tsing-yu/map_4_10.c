inherit ROOM;
void create()
{
	set("short", "��D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_10",
	"west" : __DIR__"map_4_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
