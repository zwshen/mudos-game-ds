
inherit ROOM;

void create()
{
	set("short", "一甲路");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega8",
	"west": __DIR__"eega6",
	]));
	setup();
	replace_program(ROOM);
}
