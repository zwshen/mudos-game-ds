// shijie6.c 石階
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
這是一條整齊的石板路，依山而建，隨著山勢的曲折蜿蜒曲折。
由於山勢陡了，當初修建這條石階時肯定費了不小的功夫。走到這
裡，已經可以看見全真教重陽觀的檐角了。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"shijie7",
                "southdown" : __DIR__"jiaobei",
        ]));
        set("no_clean_up", 0);
        //set("objects",([
        //      __DIR__"npc/youke" : 1,
        //      __DIR__"npc/xiangke" : 1,
        //]));

	set("coor/x", -3140);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}