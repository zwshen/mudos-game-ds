/// Room: /u/a/acme/area/pathway1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裡是通往天湖的小路，周圍盡是住家，南邊可看到中央廣場，西
南邊有一間藥鋪，東邊隱約可見一條小路，但似乎是久無人煙而長滿了
雜草。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"pathway2",
  "south" : __DIR__"street6",
   "northwest" : __DIR__"smallway",
]));
	set("no_clean_up", 0);
         set("objects",([
            __DIR__"npc/guan" : 1,
         ]) );
 
     set("outdoors","land");

	setup();
}
void init()
{ 
         add_action("do_enter","enter");
}
int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "小路")
            return 0;
          else {
            message_vision("$N播開了雜草叢往東邊的小路走了過去。\n",me);
            me->move(__DIR__"pathway");
            return 1;
          }
}
