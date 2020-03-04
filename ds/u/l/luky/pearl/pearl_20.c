// Room: /u/l/luky/room/pearl_20.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]¥_µó"NOR);
set("long", @LONG

¡Ä¡Ä¡Ä¡Ä¡Ä   ³o¸Ì¬OºÑ¹pº¸ÂíªºªF¥_¨¤¡C§A¬Ý¨ìÀð  ¡Ä¡Ä¡Ä¡Ä¢¬ùþ
"  .   -   ¨¤¦³­Ó¤T¨¤§Îªº¤p¬}¡A¬}¤fÁÙ¦³¤@¨Ç³½        ¢y: ùþ
:      -   °©ÀY¡C±q³o¸Ì©¹«n¬O¬Ã¯]ªFµó¡A©¹¦è«h       -¢y: ùþ
= ."   -   ¬O¼ö¾xªº¬Ã¯]¥_µó¡A¨º¸Ì¦³´X´É¤Q¤À²{       =¢y: ùþ
==-  " -   ¥N¤Æªº«Ø¿vª«¡C                 -      -=[32m¡¶[m¢y: ùþ
¡Ã¡Ã¡Ã¡Ã¡Ã                   ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¢­ùþ


LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_19",
"south" : __DIR__"pearl_21",
]));
set("item_desc",([
"hole":"¤@­Ó¤T¨¤§Îªº¤p¬}¡C\n",
"bone":"¤@°ï¦Y³Ñªº³½°©ÀY¡C\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}

void init()
{
 add_action("do_search","search");
}

int do_search(string arg)
{
 object me,obj;
 me=this_player();
 if(!arg) return notify_fail("§A­n·j¬d¤°»ò?\n");
 if(arg=="hole" || arg=="¤p¬}" || arg=="¬}")
 {
  if(query_temp("nocork")) return notify_fail("¤p¬}¸Ì­±¨S¦³¥ô¦óªF¦è.\n");
  message_vision("$N±q¤p¬}¤¤§ä¨ì¤F¤@­Ó¤p¤ì¶ë¡C\n",me);
  obj=new(__DIR__"obj/cork");
  if ( (obj->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
  {
   write("§A®³¤£°Ê¤p¤ì¶ë, ¤â¤@³n..¤p¤ì¶ë±¼¨ì¦a¤W¤F!!\n");
   obj->move(environment(me));
  } else
  obj->move(me);
  set_temp("nocork",1);
  call_out("do_reborn",600);
  return 1;
 }
 if(arg=="bone" || arg=="³½°©ÀY" || arg=="°©ÀY")
 {
  if(query_temp("bone")>10) return notify_fail("³Ñ¤U¤@°ï´Ý´í..¨S¦³¤°»ò¦n®³ªº¤F.\n");
  message_vision("$N±q³½°©ÀY¤¤§ä¨ì¤F¤@°¦³½°©½b¡C\n",me);
  obj=new(__DIR__"npc/item/fisharrow");
  if ( (obj->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
   return notify_fail("¥i¬O§Aªº¤O¶q¤£°÷,®³¤£°_¨Ó\n");
  obj->move(me);
  add_temp("bone",1);
  call_out("do_reborn",600);
  return 1;
 }
 return 0;
}

void do_reborn()
{
 this_object()->delete_temp("nocork");
 this_object()->delete_temp("bone");
}