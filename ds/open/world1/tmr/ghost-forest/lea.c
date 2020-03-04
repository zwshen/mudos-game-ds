// Room: /tmr/garea/lea.c

inherit ROOM;

void create()
{
	set("short", "草叢");
	set("long", @LONG
你正處在一片草叢之中的丈許圓地，四周皆是不知名的茂盛野草，地
上散落著數張道士作法用的符咒以及一些空酒袋，在這片闊林綠野中，顯
著格外怪異。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"forest6",
	]));
	set("objects",([
	__DIR__"npc/taoist":1,
	]) );
	set("item_desc",([
	"空酒袋":"一個已喝完的空酒袋，上頭寫著「百花釀」。\n",
	"符咒":"一張破爛不堪符咒，上頭寫的符文早已經過風吹雨淋而不見了。\n",
	]) );
	set("no_clean_up", 0);
	set("outdoors","forest");		
	setup();
	replace_program(ROOM);
}
