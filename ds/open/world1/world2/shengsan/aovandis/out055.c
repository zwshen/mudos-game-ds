// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "湖邊樹林");
	set("long", @LONG
這裡有十幾棵高大的樹木佇立在這邊，還有許多的飛鳥在枝頭上吱吱
亂啼，往西看去可以看到一座碧綠的湖泊，湖面反射太陽的光輝成為點點
的閃亮珍珠，好不美麗。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out059",
	    "north": __DIR__"out050",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}