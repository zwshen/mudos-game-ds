
inherit ROOM;

void create()
{
	set("short", "巫毒教廚房");
	set("long", @LONG
這裡是巫毒教的廚房，牆壁上卻不見油膩的景象，你看到一位老伯伯
正在烹飪美味的食物，想必他就是這個廚房的廚師了，旁邊還有幾位他的
徒弟在幫忙他切切菜，做做小點心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south" : __DIR__"room14",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/cook" : 1,
	    __DIR__"mob/cookstudent": 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
