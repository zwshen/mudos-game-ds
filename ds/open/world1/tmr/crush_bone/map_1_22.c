inherit ROOM;
void create()
{
	set("short", "�p�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_21",
	"south" : __DIR__"map_2_22",
	]));
    set("objects", ([
        __DIR__"npc/orc_follower" : 4,
        __DIR__"npc/orc_hundred_leader" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
