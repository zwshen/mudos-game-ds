// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
這裡的樹木並不會很多，所以可以看到大部分的天空。天空上不時有
老鷹在上邊盤旋，似乎這附近有獵物似的。有時幾隻的松鼠會在樹林間穿
梭跳躍，玩耍在這天地之間。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out051",
	    "south": __DIR__"out056",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}