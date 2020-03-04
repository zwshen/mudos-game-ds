inherit ROOM;
void create()
{
seteuid(getuid(this_object()));
set("short","Äq¥Û¶°¤¤Àç");
set("long","Äq¥ÛÄq¥Û\n");
set("light",1);
set("no_clean_up",1);
setup();
}
