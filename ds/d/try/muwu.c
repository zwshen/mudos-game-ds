// Room: /d/shaolin/muwu.c

inherit ROOM;

void create()
{
	set("short", "小木屋");
	set("long", @LONG
這是一間簡陋的小木屋，屋內靠邊放著一張木板床，中間是
一張木桌，桌上放著筆墨紙硯和几本詩集，一看主人就是一位讀
書人，屋外是一片翠綠的竹林。
LONG
	);
	set("no_clean_up", 0);

	set("exits",([
	"east" : __DIR__"zhulin/exit",
]));

	setup();
	replace_program(ROOM);
}
