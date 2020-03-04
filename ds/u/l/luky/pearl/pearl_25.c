// Room: /u/l/luky/room/pearl_25.c
inherit ROOM;
void create()
{
set("short", "[1;32m¼ÚªB§V­×¹D°|[m");
set("long", @LONG

     ³o­Ó­×¹D°|¬O¥Ñ¤j½åªÌ¼ÚªB§V©Ò³Ğ«Ø¡A¦b 7¦~«e»P³ÈÀw¨¸¯«ªº¤@
 ³õ¤j¾Ô«á¡A¼ÚªB§V©M¥Lªº¾Ô¤Í­Ì«K¤£ª¾¥h¦V¡C¥Lªº§Ì¤l­ÌÄ~©Ó¤F¥Lªº
 ·N§Ó¡A¤´¶Ô¾Äªº±M¬ã¸t³N¡A¥H¨¾¤î¨¸¯«¦A«×ªºµd¿ô¡C

                        ¢®  
                          ¢­  
                       _£[_.O. 
                      /\__.\/ ¢­ 
                      \/__\  
                       | :|              k
                       | :|           O  |
                     ¢g¢i¢i¢g       ()Y==o
               ¢i¢g¢i¢iÀJ¹³¢i¢i¢g¢i  /_\ |
               ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  _W_ |
   ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã

LONG
);
set("objects",([
__DIR__"npc/chufighter":2,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_37",
"leave" : __DIR__"pearl_23",
]));
set("item_desc",([ //´ºª«
  "statue":"³o¬O¤j½åªÌ¼ÚªB§VªºÀJ¹³¡C\n",
  "ÀJ¹³":"³o¬O¤j½åªÌ¼ÚªB§VªºÀJ¹³¡C\n",
  "words":"§A¥i¥H¸ÕµÛÅªÅª¬İ(read words)¡C\n",
  "¥j¤å":"§A¥i¥H¸ÕµÛÅªÅª¬İ(read words)¡C\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}

void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
 object me;
 me = this_player();
 if( !arg || (arg != "words"))return notify_fail("§A­nÅª¤°»ò?\n");
 if(random((int)me->query("int"))<20)
   message_vision("$N¬İ¤F¥b¤Ñ¤]¬İ¤£¥X¬O¤°»ò·N«ä¡C\n",me);
 else
 {
  message_vision("$N¬İ¤F¤@¤U¡Aµo²{¤W­±¼gµÛ[¶}µo¤¤]¡C\n",me);
  me->set_temp("statusword",1);
 }
 return 1;
}
