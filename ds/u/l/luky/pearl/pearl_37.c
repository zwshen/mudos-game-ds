// Room: /u/l/luky/room/pearl_37.c
inherit ROOM;
void init();
void create()
{
set("short", "[1;32m­×¹D°|¤jÆU[m");
set("long", @LONG

¹u¤l½ñ¦b¤jÆUªº¤j²z¥Û¦aªO¤Wµo¥X²M¯Üªº¡u³Ø°Õ¡A³Ø°Õ¡v¦^ÅT¡A
µÛ¦Wªº¯«Å]¾Ôª§¹³(Figure)´N¨è¦b¦¹³B¤W¤è¡AµLªk±æºÉªº¥|¾À³º¤]§G
º¡µÛº¯¤J¯«¸t¥ú¨~ªº¤C±m¬Á¼ş(Window)¡A¥i»¡¬O¥@¶¡©_´ººÉ»E¨ä«Ç¡A
¤£¹L³o¸Ì³Ì¯à¤Ş¤H²´¥úªº²ö¹L©óÀğÃä¤@±Æªº¥jÄÁ¤F...

LONG
);
set("objects",([
__DIR__"npc/academician":1,
]));
set("exits", ([ /* sizeof() == 1 */
"up" : __DIR__"pearl_40",
//  "down" : __DIR__"pearl_41",
"east" : __DIR__"pearl_25",
"west" : __DIR__"priest",
]));

set("item_desc",([
"figure":@NOTE
¶Ç»¡¤¤·à¤l¾Ôª§ªº¼ÒÀÀ¹Ï¡A¦b­×¹D°|«Ø¦¨¤§«e½Ğ¤@¦ì¤u¤HÁÉ©Ô(Sala)
ÀJ»s¦Ó¦¨¡AÁÁ¶Ç¼CÅ]ªº¬G¨Æ¸ò¥L®¼¦³Ãö³s..
NOTE
,
"window":"±m¦â¬Á¼ş¤@¦V¬O±Ğ°ó¤¤¤£¥i¤í¯Ê¤§ª«¡A¤£¹L¦¹³B¦³ÂI¯S§O¡A¤W­±
´yÃ¸¤F³\\¦h¶Ç»¡¤¤ªº¬G¨Æ¡C\n",
"clock":"³o¤@¾ã±ÆªºÄÁ¦ü¥G¨S¦³­­¨îªº¤£°±©¹¥_¤è©µ¦ù¡A¥¿¤@¤@Æ[½à¤§®É
¡A³º¦³¤@®y²`ÂÅ¦âªºÄÁ(blue_clock)¤£°±ªºµo¥X©_©ÇªºÁn­µ¡H\n",
"¥jÄÁ":"³o¤@¾ã±ÆªºÄÁ¦ü¥G¨S¦³­­¨îªº¤£°±©¹¥_¤è©µ¦ù¡A¥¿¤@¤@Æ[½à¤§®É
¡A³º¦³¤@®y²`ÂÅ¦âªºÄÁ(blue_clock)¤£°±ªºµo¥X©_©ÇªºÁn­µ¡H\n",
"blue_clock":"³o®yÂÅ¦âªºÄÁ¬İ¨Ó¤]µL¯S§O¡A­è­èÅ¥¨£ªº©ÇÁn(sound)¥i¯à¬O¿ùÄ±§a¡C\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
set("hour",11);
set("min",46);
set("time",0);
}

void init()
{
 add_action("do_listen","listen");
 add_action("do_checkt","checktime");
 add_action("do_time","settime");
}

int do_listen(string arg)
{
 object me;
 me=this_player();
 if(!arg) return notify_fail("§A­nÅ¥¤°»ò?\n");
 if(arg=="sound")
 {
  message_vision("$N¨«¨ìÂÅ¦â¥jÄÁ®ÇÃä¥Î¤ßÅ¥¤F¤@·|¨à¡C\n",me);
  write("§Aµo²{³o­ÓÄÁªºÁn­µ¨«ªº¤ñ¨ä¥LªºÄÁºC..¦Ó¥B¤ñ¸û¤jÁn.. ¦A¥J²Ó¤@¬İ.. \n");
  write("­ì³o­ÓÄÁ¨S¦³Ãè­±.. ®É°w©M¤À°w³£¥i¥HÀH·N¶Ã³](settime)..§A¥i¥H¬İ¬İ\n");
  write("¥Ø«e³o­ÓÄÁ³]©wªº®É¶¡(checktime)¡C\n");
 }
 return notify_fail("§AÅ¥¤F"+arg+"¥b¤Ñ¤]Å¥¤£¥X¤°»ò¤ß±o¡C\n");
}

int do_checkt()
{
 int hour,min;
 hour=query("hour");
 min=query("min");
 write("²{¦b®ÉÄÁªº®É¶¡¬O "+hour+"ÂI"+min+"¤À¡C\n");
 return 1;
}

int do_time(string arg)
{
 object me,paper;
 string arg2;
 int num,min,hour,time;
 me=this_player();
 if(!arg) return notify_fail("®æ¦¡: \nsettime hour [¼Æ¦r]\nsettime min [¼Æ¦r]\n");
 if(sscanf(arg, "%s %d", arg2, num)==2)
 {
  if(arg2=="hour") 
  {
   if(num>12 ||num<1) return notify_fail("§A®aªºÄÁ¤~¦³³oºØ®É¶¡§a?!\n");
   set("hour",num);
   message_vision("$N¨«¨ìÂÅ¦â¥jÄÁ«e­±¼·¤F«ü°w¤@¤U¡C\n",me);
   write("[³Ø¯Y!] ®É¶¡³]©w§¹²¦¡C\n");
  //call_out("checkt",1);
  } 
  if(arg2=="min")
  {
   if(num>60 ||num<0) return notify_fail("§A®aªºÄÁ¤~¦³³oºØ®É¶¡§a?!\n");
   set("min",num);
   message_vision("$N¨«¨ìÂÅ¦â¥jÄÁ«e­±¼·¤F«ü°w¤@¤U¡C\n",me);
   write("[³Ø¯Y!] ®É¶¡³]©w§¹²¦¡C\n");
  // call_out("checkt",1);
  }
  hour=query("hour");
  min=query("min");
  time=query("time");
  if(time==0 && hour==7 && min==7) set("time",1);
  if(time==1 && hour==6 && min==3) set("time",2);
  if(time==2 && hour==12 && min==0)
  {
   if(paper=present("paper",me))
   {
    message_vision("$N®³¥X¯È¤ù·ÓµÛ¤W­±°áµÛ: ¥|¤èµL·¥, °®©[­Éªk, ¤Ñ¦a°­¯«, ¨Ñ§Ú®t¨Ï!!\n",me);
    message_vision("$N¤â¤¤ªº¯È¤ù²rµM¤Æ¬°¤@¹DÂÅ¥ú.. ®g¤J¤F¥jÄÁ¤§¤º!!\n",me);
    destruct(paper);
    message_vision("[1;33m\n\n¾´¡ã¾´¡ã¾´¡ã¾´¡ã¾´¡ã¡ã¡ã\n[37m¬ğµM¥ş³¡ªºÄÁ³£ÅT¤F°_¨Ó!!\n[m",me);
    message_vision("\n  ÂÅ¦âªº¥jÄÁ½w½wªº¦V«á²¾°Ê¡C¥X²{¤F¤@­Ó¦a¬}!! \n",me);
    set("exits/down", __DIR__"pearl_41");
   } else 
   {
    message_vision("$NÂÅ¦â¥jÄÁ®Ì¤F¤@¤U¡C\n",me);
    write(" §A·PÄ±¦ü¥G¬O¤Ö¤F¤°»ò¨BÆJ³á..\n");
    set("time",0);    
   } 
  }
  return 1;
 }
 return 0;
}

