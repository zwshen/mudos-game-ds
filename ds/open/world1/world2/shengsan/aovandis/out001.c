// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
綠油油的草坪生長在這片土地之上，有點暑意的空氣裡瀰漫著提神醒
腦的樟樹氣味。不時也有幾棵高過一般人身高的芒草長在地上。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"out002",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}