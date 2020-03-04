inherit ROOM;

void create()
{
        set("short", "會議大廳");
        set("long", @long
經過了一個長廊，來到了神境的會議大廳，大廳的中央有一張很
大會議桌，旁邊還有一個公佈欄。在這個神聖的會議大廳裡，會公告
一些重大的事情或舉行一些大型會議。如果你有什麼事情想說的，也
可以貼在公佈欄上。再往南走，是專門存放道具的道具之屋。 

long);
        set("exits", ([
  "north" : __DIR__"ladder-1",
  "south" : __DIR__"room_item",
]));
        set("light", 1);
        setup();
        set("stroom", 1);
        call_other("/obj/board/club_god_1.c", "???");
}

