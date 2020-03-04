// Room: /u/m/matlab/area/r4.c

inherit ROOM;

void create()
{
	set("short", "岩壁");
	set("long", @LONG
眼前是一大片光滑厚實的石壁，似乎將去路給完全斷絕了，你仔細觀視四週，
發現石壁的形成絕非天然 !! 對此一鬼斧神工的巨作，你不禁開始想像石壁之後是
怎樣一番光景 ! 在好奇心一再地驅始下，你決定展開搜索機關暗門(lookfor)...
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r3.c",
]));
	set("no_clean_up", 0);

	setup();
}
init()
{
add_action("do_lookfor","lookfor");
}
int do_lookfor(string arg)
{
object me;
me = this_player();
if ( !arg ) return 0;
else if((arg == "機關暗門")||(arg == "機關")||(arg == "暗門"))
{message_vision("$N靈光一現地在石壁上一陣拍打，竟鬼使神差地敲中機關\n
                    轟隆一陣巨響之後......石門開了 !! \n\n",me);
set("exits",([
"north" : "/u/m/matlab/area/r5.c",
"south" : "/u/m/matlab/area/r3.c",
]));
return 1;
}
}
