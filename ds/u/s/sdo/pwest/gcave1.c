inherit ROOM;

void create()
{
	set("short", "洞窟內");
	set("long", @LONG
在你的面前出現了一大片石壁，石壁的左右兩邊都有出口，看起
來深不見底，不知道裡面會有些什麼樣的危險。你不禁躊躇起來，認
真思考：『我究竟該繼續往前進，還是轉身離開這個漆黑的洞窟？』
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  		"northwest" : __DIR__"gcave2",
  		"out" : __DIR__"hill1",
  		"northeast" : __DIR__"gcave3",
	]));

	setup();
	replace_program(ROOM);
}
