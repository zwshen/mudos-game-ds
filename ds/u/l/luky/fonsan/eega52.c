// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "正義街尾");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega47",
	"southeast": __DIR__"eega58",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
