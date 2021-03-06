// Room: /d/xiangyang/guofuting.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "郭府客廳");
	set("long", @LONG
這裡是郭府的客廳。廳雖不大，卻佈置的挺雅致。東壁懸
掛著四幅屏條，繪的是梅蘭菊竹四種花卉；西壁懸掛的是春夏
秋冬。內廳居中的是一張八仙桌。桌上端放著一套茶具，兩旁
擺放著四張檀香椅，顯得極為古樸。廳角各擺放著一盆牡丹花，
似乎給這裡帶來一絲暖意。北壁內牆的神龕供奉嶽飛的畫像，
上面是一條橫幅，上書“還我河山”。
LONG );
	set("exits", ([
		"south" : __DIR__"guofuyuan",
		"north" : __DIR__"guofuhuayuan",
	]));
	set("objects", ([
//          __DIR__"task/guo" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
