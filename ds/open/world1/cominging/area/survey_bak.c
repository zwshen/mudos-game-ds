#include <ansi.h>

inherit ROOM;

string *songs = ({
"如果雲知道",
"走在雨中",
"月亮代表我的心",
"愛一個人好難",
"雨一直下",
"Call me",
"I Can't CRY",
"不可能錯過你",
"有染",
"或許\你是對的",
"我不是一個愛過就算的人",
"我可以抱你嗎？",
"我最搖擺\",
"把妳藏起來",
"孟婆湯",
"是不是這樣的夜晚你才會想起我",
"風一樣的男子",
"真愛無敵",
"這個位置留給你",
"愛我別走",
"當我開始偷偷想你",
"幫個忙",
"魔鏡",
});

string show_songs();

void create()
{
	set("short", "步靈城俯瞰台");
	set("long",@LONG
這裡是步靈城中最古老的遙望台，在這裡的周圍是由竹木所築成的
，似乎有點容易倒塌的樣子，在這的四周有許許多多的窗戶(windows)
，可以望向步靈城的四周，在晚上時的夜景也可稱的是蔚為一觀，可也
是步靈城中特別繁榮的景象，在牆壁上有許多地圖，也有許多人的作詩
，頗有些愛國的感覺，在你的腳下是通往廣場的樓梯，旁邊的牆上有著
一片小紙條(scrip)。
LONG
	);
	set("exits", ([
  "down" : __DIR__"boo-lin.c",
]));
	set("light",1);
	set("item_desc",([
  "windows" : "這是一個由竹做成的窗戶，似乎可以從這跳下(jump)到南大街。\n",
  "scrip" : (: show_songs() :) ,
/*             HIC"
小紙條上面寫著："HIG"
我所唱的，是為了讓大家能夠豐愉自己的生活，如果可以，可以用 singing 來
讓我唱些歌曲。
"HIM"
    1.如果雲知道
    2.走在雨中
    3.月亮代表我的心
    4.愛一個人好難
    5.雨一直下

"NOR,*/
]));
	set("objects",([
  __DIR__"npc/minstrel.c": 1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me,sstreet;
	me = this_player();
	sstreet = load_object(__DIR__"boo-lin2.c");

	if( arg!="down" && arg!="windows" )
		return notify_fail("你要跳上還是跳下呀？\n");
	if( me->start_busy() )
		return notify_fail("你現在還很忙！\n");

	tell_room(environment(me),me->name()+"從南邊的窗戶往下一條，你只聽見一聲長長的慘叫聲。\n",({ me }));
	me->move(sstreet);
	tell_room(environment(me),me->name()+"從北邊的遙望台上的窗戶跳了下來，結果重重的摔倒在地上。\n",({ me }));
	message_vision("$N摔在地上有一會兒沒辦法動！！\n",me);
	me->start_busy(10);
	return 1;
}

string show_songs()
{
	string show;
	int x;

	show = HIC"小紙條上面寫著：\n";
	show += HIG"可以用 singing 來讓我唱些歌曲。\n\n"HIM;

	for(x=0;x<sizeof(songs);x++)
		show += sprintf("  (%3d) %-30s\n",x+1,songs[x]);
	show += "\n"NOR;
	return show;
}
