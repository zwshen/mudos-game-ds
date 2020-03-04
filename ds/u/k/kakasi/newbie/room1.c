inherit ROOM;

void create()
{
        set("short", "道館大門");
        set("long", @LONG
你走在一條人煙稀少的大街上，正前方就是遠近馳名的「新手大道館」，
全樓高4層，隱隱約約都可以聽到很多雜聲，四周都是 枯藤 老樹 昏鴉，�
這個道館倚山靠水，風景秀麗，難怪會遠近馳名。 
似乎有怪獸的聲音在跟你挑釁。LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"/open/world1/cominging/purple_sun/psin3",
  "north" : __DIR__"room2",
  ]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"beast" : 2,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

