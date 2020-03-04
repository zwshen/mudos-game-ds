#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "茅廁");
	set("long", @LONG
這裡是守衛塔旁的小茅廁，在這裡奇臭無比，正是”一”臭萬年，
在你的旁邊有些牛皮紙，可以擦下你「痕跡」，想到下面就是一陀陀的
．．，就不禁令人有些想嘔吐。
LONG
	);
	set("exits", ([
  "south" : __DIR__"tower.c",
]));
	set("item_desc",([
  "牛皮紙" : "專門給人上完 1 號專用的紙，偶爾上面還有些咖啡色不明物體。\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

void init()
{
	tell_object(this_object(),"突然一陣奇'香'無比的氣味衝入你的鼻中，頓時整個人似乎就要昏的感覺。\n");
}