
inherit ROOM;

void create()
{
	set("short", "巫毒教教壇");
	set("long", @LONG
你看到兩旁的牆壁彩妝上莊嚴的顏色，其上的壁畫似乎訴說著巫毒教
的創教經過以及傳承的歷史，屋頂的琉璃也排成規則的幾何圖形，大大小小
以及方正圓缺都有其特色，你看到教徒們膜拜神靈用的坐墊及法器。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room35",
	    "north": __DIR__"room39",
            ]));
	set("objects", ([ /* sizeof() == 1 */
	    __DIR__"mob/protector" : 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
