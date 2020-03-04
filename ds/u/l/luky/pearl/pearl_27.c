// Room: /u/l/luky/room/pearl_27.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "[1;32m®ü©³¹qÅK¯¸¤jÆU[m");
set("long", @LONG

ùþ¢­  ¡Ä¡Ä¡Ä¡Ä¡Ä
ùþ¢y¡Ä¢j°â²¼³B¢y¢©¡Ä¡Ä  ³o¸Ì¬O®ü©³¹qÅK¯¸ªº¤jÆU¡C¤J¤f®Ç
ùþ¢y :¢j¢i¢i¢i¢y¢i      Ãä¦³­Ó°â²¼³B¡A¨Ñ®È«ÈÁÊ²¼(buy)
ùþ¢y :¢j¢i¢i¢i¢y¢i      ¥Î¡C³o¸Ìªº¶¢Âø¤H«Ü¦h¡A§A³Ì¦n¤p
ùþ¢y :¢j      ¢y¢i      ¤ß¤@ÂI¡A¥H§K³Q¥¶¤â¬Ý¤W¡C
ùþ¢y :¢j      ¢y¢«¡Ã¡Ã
ùþ¢y¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã
ùþ¢¬

LONG
	);
set("objects",([
__DIR__"npc/sightseer":2,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_32",
"east" : __DIR__"pearl_26",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="west")
 {
  if(!wizardp(me))
  {
   if(!this_player()->query_temp("ticket")) return notify_fail("§A¨S¦³¶R²¼¤£¯à¶i¥h¡C\n");
   write(HIW"§A§â²¼®³µ¹¯¸ªø«á«K©¹¤ë¥x¨«¥h¡C\n"NOR);
   me->delete_temp("ticket");
   return ::valid_leave(me, dir);
  } else 
   {
    message_vision("[1;35m$N[1;37m®¨®¨¹ï¯¸ªø»¡: §Ú¬O§Å®v... ¤£¥Î¶R²¼¤F§a..[m\n",this_player());
    message_vision("[0;36m¯¸ªøÂI¤FÂIÀY.. ©ñ$N[0;36m¹L¥h¤F..[m\n",this_player());
    return ::valid_leave(me, dir);
   }
 }
 return ::valid_leave(me, dir);
}

void init()
{
add_action("do_buy", "buy");
}

int do_buy(string arg)
{
 object me;
 me=this_player();
 if(!arg) return notify_fail("§A­n¶R¤°»ò??\n");
 if(arg=="ticket")
 { 
  if(me->query_temp("ticket")) return notify_fail("§A¤w¸g¶R¹L²¼¤F¡C\n");
  if(this_player()->query("coin")<300)
   return notify_fail("¤@±i²¼­n¤T¨Õ¤¸³á.. §Aªº¿ú¤£°÷¡C\n");
  write(HIY"§A¥I¤F300¤¸, °â²¼¤¸µ¹¤F§A¤@±i²¼¡C\n"NOR);
  me->set_temp("ticket",1);
  this_player()->add("coin",-300);
  return 1;
 }
 return notify_fail("³o¸Ì¥u½æ²¼(Ticket)³á¡C\n");
}