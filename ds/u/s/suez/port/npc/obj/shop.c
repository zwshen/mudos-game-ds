inherit ROOM;
void create()
{
seteuid(getuid(this_object()));
set("short","´¶º¸°Ó·|­Ü®w");
set("long","\n");
set("light",1);
set("no_clean_up",1);
set("objects",([
    __DIR__"npc/quest_boy":1,
	]));
setup();
}