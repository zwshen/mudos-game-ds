inherit ROOM;
void create()
{
	set("short", "�E��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_37",
    "north" : "/open/world2/lichi_town_1/map_2_36",
	"west" : __DIR__"map_3_35",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
