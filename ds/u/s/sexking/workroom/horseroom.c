inherit ROOM;

void create()
{
   set("short","小麥草馬房");
   set("long", @LONG
這裡是小麥草的愛馬[小麥草之馬]的停放處..請不要亂牽走牠..牠會餓死.
如果牠不在這的話,代表小麥草已騎著牠出去玩了。
LONG );
  set("light", 1);
  set("exits", ([/* sizeof() == 2 */
"east" : "/u/s/sexking/workroom/sexking_room2.c"
]));
    set("no_kill",1);
    setup();
}   
