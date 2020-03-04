// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "南昌街轉角");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega28",
	"south": __DIR__"eega41",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
