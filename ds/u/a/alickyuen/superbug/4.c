// Room: /u/a/acme/area2/t20.c

inherit ROOM;

void create()
{
        set("short","洗手間");
	set("long", @LONG
這裡是洗手間，在你的身後是一面屏風，面前放了一面鏡子，還有幾
個洗手台，從門上的標誌你可以得知，在你的左方是男廁所，右方是女廁
所，可是女廁所的門上掛了一張「暫停使用」的牌子。
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"6.c",
  "out" : __DIR__"2.c",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "牌子" : "一面寫著：「暫停使用」的牌子。n",
  "門" : "一扇掛著牌子的門，看起來似乎可以踹開它。n",
  ]) );
	set("no_clean_up", 0);

	setup();
}
void init()
{ 
         add_action("do_kick","kick");
}
int do_kick(string arg)
{
          object me;
          me=this_player();
          if(arg != "門")
            return 0;
          else {
            message_vision("$N用力一腳往門踹去，只見門應聲而開。\n\n",me);
            message_vision("$N的腳因為踢得太用力而受傷流血，走路一跛一跛的，站都站不穩。\n",me);
    set("exits", ([ /* sizeof() == 3 */
               "west" : __DIR__"6.c",
               "out" : __DIR__"2.c",
               "east" : __DIR__"7.c",
            ]));
            me->receive_wound("left_leg",10);
            return 1;
          }
}
int valid_leave(object me, string dir)
{
       if( dir=="westdown" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
