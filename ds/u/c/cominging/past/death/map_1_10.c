inherit ROOM;
void create()
{
	set("short", "�ۿj�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_2_10",
	"north" : __DIR__"map_0_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
