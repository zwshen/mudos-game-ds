inherit ROOM;
void create()
{
	set("short", "旅館大廳");
        set("long", @LONG
    你正站在梅龍鎮旅館的中央大廳。地上有個石板(Slate)。
LONG
);
	set("exits",([
	"east" : __DIR__"map_5_27",
	"south" : __DIR__"map_6_26",
	"north" : __DIR__"map_4_26",
	"west" : __DIR__"map_5_25",
     "down" : "/open/world2/shengsan/aovandis/room103",  // add by wilred
	]));
	set("light",1);
	set("no_fight",1);
	set("valid_startroom", 1);
	set("hide_item_desc",([	
	"slate" : @SLATE1
一個鑲在地上的石板，上面刻著一些圖文。

        ▕█　████＊███████　　　　██＊▎平面圖例:
        ▕█████████︻█︻███　●　█　　▎
        ▕█████████　　　██＊　　　███▎♁  你目前的位置
        ▕████████＊　♁〔███　　　█　　▎♀  其他玩家
        ▕█████████　　　██　　　　██　▎＊  出入口
        ▕█████████︻█︻██　　●　█＊　▎〔  櫃檯
        ▕██████████████　　　　██　▎︻  床

SLATE1,
	])	);
	set("item_desc",([	
	"石板" : @SLATE2
一個鑲在地上的石板，上面刻著一些圖文。

        ▕█　████＊███████　　　　██＊▎平面圖例:
        ▕█████████︻█︻███　●　█　　▎
        ▕█████████　　　██＊　　　███▎♁  你目前的位置
        ▕████████＊　♁〔███　　　█　　▎♀  其他玩家
        ▕█████████　　　██　　　　██　▎＊  出入口
        ▕█████████︻█︻██　　●　█＊　▎〔  櫃檯
        ▕██████████████　　　　██　▎︻  床

SLATE2,
	])	);
        setup();
        call_other("/obj/board/now_malo_b", "???");
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

void init()
{
  this_player()->set_temp("now_new_city",1);
  this_player()->set_temp("now_old_city",);
}
