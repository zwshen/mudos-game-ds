// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
愈往樹林的深處走去，樹林的密度就愈高，不時間你會聽到一些奇怪
的聲音，像是由某種動物所發出的，聽得你心裡產生毛毛的感覺。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out037",
	    "south": __DIR__"out042",
	    "north": __DIR__"out030",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}