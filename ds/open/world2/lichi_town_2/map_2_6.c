inherit ROOM;
void create()
{
	set("short", "���U");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_7",
    "south" : "/open/world2/lichi_town_1/map_3_6",
	"west" : __DIR__"map_2_5",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
