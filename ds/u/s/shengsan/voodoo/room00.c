#include <path.h>
inherit ROOM;

void create()
{
	set("short", "翠林");
	set("long", @LONG
在你的身旁都是青翠的竹林，隨著風吹林中的竹葉不時地發出沙沙的
聲音。相傳翠林裡是聞名已久的[35m『巫毒教』[m。無意間你發現在翠林旁有一
個牌子(sign)。
LONG
	);

	set("item_desc", (["sign":@NOTE
[1;32m
		巫毒教(voodoo)禁地,非請勿入。
		如果不打算進去請出去(out)。
		也許你可以 enter voodoo 進入巫毒教。

[m
NOTE
        ]) );

//	set("exits", ([ /* sizeof() == 1 */
//	    "enter" : "/u/s/shengsan/voodoo/room01",
//            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_out","out");
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="voodoo")
		return notify_fail("你要進入哪裡？\n");
	if(query_temp("user")>10)
		return notify_fail("你以為這裡是觀光勝地阿？\n");
	add_temp("user",1);
	me->move(__DIR__"room01");
	return 1;
}

int do_out(string arg)
{
	object me;
	me=this_player();
	if(query_temp("user")>0)
		add_temp("user",-1);
	me->move(SHENGSAN+"wisland/land24");
	return 1;
}
