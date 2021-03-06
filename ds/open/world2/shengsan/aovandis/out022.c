// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
茵草在這邊生長，這裡並沒有受到工業的污染，你往南邊遠看可以看
到一大片的樹林聳立在南方，天空的鳥兒不時的啾啾啾的叫。往北可以到
通往奧凡迪斯東城門的道路。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out021",
	    "north": __DIR__"out015",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}