inherit ROOM;
void create()
{
seteuid(getuid(this_object()));
set("short","�_�Z�����Q�ܮw");
set("long","\n");
set("light",1);
set("no_clean_up",1);
  set("exits",([
     "out" : "/open/world1/tmr/north_bar/shop",
  ]));
setup();
}

