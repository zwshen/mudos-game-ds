// Room: /tmr/future/hunter_forest/forest6.c

inherit ROOM;

void create()
{
	set("short", "山洞前");
	set("long", @LONG
在你的北邊的不遠處有座開了小洞的山丘，你可以清楚的聽到「骨」
的動物叫聲從小山洞裡傳了出來。你稍微地看了看四周，由於植物的生長
茂盛，林間似乎已沒有可容人通行的道路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"forest5.c",
	]));
	set("item_desc",([
	"小山洞":"一個須要縮身才爬得進去的小山洞。(grovel)\n",
	]) );
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");
	setup();
}

void init()
{
	add_action("do_grovel","grovel");
}

int do_grovel(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="小山洞" ) return 0;
	message_vision("$N縮起身子，爬進了小山洞。\n",me);
	me->move(__DIR__"hole1");
	tell_room(environment(me),me->query("name")+"從山洞外頭爬了進來。\n",({me}) );
	return 1;
}
