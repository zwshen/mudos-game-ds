inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_15_11",
	"north" : __DIR__"map_14_10",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_34" : 2,
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
