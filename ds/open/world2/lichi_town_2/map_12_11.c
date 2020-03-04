inherit ROOM;
void create()
{
	set("short", "櫃檯");
        set("long", @LONG
走到這裡映入眼簾的是一堆大大小小的紙箱子，牆上掛著一些廉
價的油畫和一張手寫的價目表。整個地方都是灰塵和蜘蛛網，令人感
覺有點呼吸困難。
	====================================================
	查詢存貨 	<list> <list wp> <list eq>
	買東西 		<buy 物品> <buy 數量 物品>
	賣東西 		<sell 物品> <sell all> <sell 數量 物品>
	試用東西 	<try 物品>
	====================================================
LONG
);
	set("exits",([
	"east" : __DIR__"map_12_12",
	"south" : __DIR__"map_13_11",
	"north" : __DIR__"map_11_11",
	]));
	set("objects",([
		__DIR__"../npc/malo_shoper_19": 1,
	]));
	set("no_kill",1);
	set("light",1);
        setup();
}
/*
string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

*/