inherit ROOM;
void create()
{
	set("short", "�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_15",
	"north" : __DIR__"map_10_16",
	]));
    set("objects", ([
        __DIR__"npc/orc_commander" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
