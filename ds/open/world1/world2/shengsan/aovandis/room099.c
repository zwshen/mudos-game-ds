// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"百貨公司"NOR);
	set("long", @LONG
在櫥窗裡展示著時髦的服飾及首飾，更有業者請真人模特兒在櫥窗裡
展示。每個專櫃都有一至二位的小姐服務，所有流行的訊息在這邊都找得
到。你可以看到一個牌子(sign)擺放在你眼前。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room092",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	set("item_desc", (["sign":@NOTE

		     �翦�����      ﹏
	    ﹏       │ 內 │
	             │ 部 │            ﹏
	﹏         �翦� 整 �澺�
		﹏ ││ 修 ││
		   ││ 中 ││﹏
		   │�檛����謖x
		 ╭┴╮    ╭┴╮   ﹏
	     ﹋﹌��─��﹋﹌��─��﹋﹌
	         ﹌       ﹏    ﹌      ﹏
NOTE
        ]) );

	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{

	if(!arg) return 0;
	if( arg != "the book" )	return 0;
	write("Yes...哈...哈...你打開了這本書...也跟著打開了你往後悲慘痛苦的人生了...\n"
		"你感到有種莫名的失落感降臨到你的身上了...\n");
	return 1;
}