inherit ROOM;
void create()
{
	set("short", "�ۿj�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_16",
	"north" : __DIR__"map_1_16",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
