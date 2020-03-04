// Room: /tmr/ship/2.c

inherit ROOM;

void create()
{
	set("short", "西渡口");
	set("long", @LONG
這是一個位於Ｘ縣的西渡口，往右邊看去是極條寬廣的大運河。
LONG
	);
	set("no_clean_up", 0);
	set("no_kill",1);
	set("no_magic",1);

	setup();
	replace_program(ROOM);
}
