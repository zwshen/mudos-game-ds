inherit ROOM;
void create()
{
	set("short", "�s�u�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_27",
	"north" : __DIR__"map_9_26",
	]));
	set("objects", ([
	__DIR__"../npc/beast_dog_4" : 1,
	]) );
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
