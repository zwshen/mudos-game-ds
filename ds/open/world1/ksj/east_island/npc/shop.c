inherit ROOM;

void create()
{
seteuid(getuid(this_object()));
set("short","ªF¤è®qªº­Ü®w");
set("long","\n");
set("light",1);
set("no_clean_up",1);
setup();
}
