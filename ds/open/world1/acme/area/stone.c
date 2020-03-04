// Room: /u/a/acme/area/stone.c

inherit ROOM;

void create()
{
	set("short", "石室");
     set("light",1);
	set("long", @LONG
這裡空蕩蕩的，什麼東西也沒有，四方是由石牆所構成的，在入口石
壁的地方，隱隱約約有著東西在發光。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"rock",
]));
	set("no_clean_up", 0);

     set("item_desc", ([
     "石壁" : "你仔細瞧了瞧石壁，發見石壁有個小洞，裡頭有個東西在發光。\n",
    "小洞" : "你仔細瞧了瞧小洞，裡頭有一個球在發光。\n",
     ]) );
	setup();
}

int do_search(object me,string arg)
{
        object pearl;
        if( arg == "石壁" )
        {
         write("石壁上有個小洞。\n");
         return 1;
        }
        if(arg != "小洞" && arg != "hole" ) return 0;
        if(query_temp("getpearl")) return notify_fail("你在小洞裡摸了摸, 但是卻沒有找到什麼。\n");
	
    message_vision("$N摸了摸小洞，突然掉出了一顆夜明珠。\n\n",me);
        pearl=new(__DIR__"npc/obj/pearl.c");
        pearl->move(me);
        set_temp("getpearl",1);
        set("item_desc", ([
     	"石壁" : "你仔細瞧了瞧石壁，發見石壁有個小洞。\n",
    	"小洞" : "你仔細瞧了瞧小洞，裡面空空的什麼都沒有。\n",
     	]) );
set("long", @LONG
這裡空蕩蕩的，什麼東西也沒有，四方是由石牆所構成的，潮濕的地
上還留了一些新腳印。
LONG
);
	set("light",0);
        call_out("delay",600,this_object());
        return 1;
}

void delay(object room)
{
 delete_temp("getpearl");
      set("light",1);
	set("long", @LONG
這裡空蕩蕩的，什麼東西也沒有，四方是由石牆所構成的，在入口石
壁的地方，隱隱約約有著東西在發光。
LONG
	);
     set("item_desc", ([
     "石壁" : "你仔細瞧了瞧石壁，發見石壁有個小洞，裡頭有個東西在發光。\n",
    "小洞" : "你仔細瞧了瞧小洞，裡頭有一個球在發光。\n",
     ]) );
     return;
}
