// Room: /u/l/luky/room/pearl_23.c
#include <ansi.h>
inherit ROOM;
void init();
void create()
{
set("short", HIY"­×¹D°|¤jªù"NOR);
set("long", @LONG

ùþ¢­                                                   ¢¬ùþ
ùþ¢y¡Ä    ³o¸Ìªº§Ù³Æ¤Q¤À´ËÄY¡A¦ü¥G¦³¤°»ò¦M¾÷§Y±Nµo   ¢¬: ùþ
ùþ¢y :¢j¥Í¡A¥|¶g¦³¤£¤Ö¥´°«ªº²ª¸ñ¡C¦èÃäªºÅKªù(Gate) ¢y: : ùþ
ùþ¢y :¢j¤W¦³¤T±ø«Ü²`ªº¤ö¦L¡A¦a¤WÁÙ´²¸¨µÛ¥¨¤jªºÅì¤ù ¢y: : ùþ
ùþ¢y¡Ã  ¡A³o¤@¤Á³£©M§A·Q¹³¤¤²øÄYµÂ¿pªº±Ð°ó¤£¦P¡C     ¢­: ùþ
ùþ¢¬                                                   ¢­ùþ


LONG
);
set("objects",([
__DIR__"npc/chuguard":2,
]));
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_22",
/*  "west" : __DIR__"pearl_25", */
"south" : __DIR__"pearl_24",
]));
set("item_desc",([
"gate":"\n
¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢s¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i    ¤W­±ÁÙ¦³´X­Ó«ö¶s¡C
                ¢ª¢i¢x¢i¢«                     ¢z¢w¢s¢w¢s¢w¢{
                  ¢i¢x¢i      ¢­¢­             ¢x¢¶¢x¢·¢x¢¸¢x
                  ¢i¢x¢i      ¢­¢­¢­           ¢u¢w¢q¢w¢q¢w¢t ¨Ï¥Î¤èªk:
              ¢¨  ¢i¢x¢i  ¢©    ¢­¢­           ¢x¢³¢x¢´¢x¢µ¢x 
              ¢ª  ¢i¢x¢i  ¢«                   ¢u¢w¢q¢w¢q¢w¢t press [¼Æ¦r]
                  ¢i¢x¢i                       ¢x¢°¢x¢±¢x¢²¢x
                  ¢i¢x¢i                       ¢u¢w¢q¢w¢q¢w¢t
                ¢¨¢i¢x¢i¢©                     ¢x¡¯¢x¢¯¢x¡­¢x
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i     ¢|¢w¢r¢w¢r¢w¢}
¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢r¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w
\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
void init()
{
 add_action("do_press","press");
}

int do_press(string arg)
{
 object me;
 me = this_player();
if(!me->query_temp("pass_num")) return notify_fail("§A¤£ª¾¹D±K½X´Nºâ«ö0¤]¨S¥Î\n");
 if(!arg) return notify_fail("    press [¼Æ¦r]\n");
 else{
  if(me->query_temp("pass_num")==atoi(arg))
  {
   message_vision("\n$N«ö¤U¤F«ö¶s..\n",me);
   me->start_busy(2);
   tell_room(this_object(),"\n
[2J¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢s¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
                ¢ª¢i¢x¢i¢«                
                  ¢i¢x¢i      ¢­¢­        
                  ¢i¢x¢i      ¢­¢­¢­      
              ¢¨  ¢i¢x¢i  ¢©    ¢­¢­      
              ¢ª  ¢i¢x¢i  ¢«              
                  ¢i¢x¢i                  
                  ¢i¢x¢i                  
                ¢¨¢i¢x¢i¢©                
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢r¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w
");
  call_out("open1",2,this_object());
  call_out("open2",3,this_object());
  call_out("closedoor",30,this_object());
  } else return notify_fail("\n  §A«ö¤U«ö¶s¡A¦ý¬O«o¨S¦³¤ÏÀ³¡C\n");
 }
 return 1;
}
int open1(object me)
{
if(!me) return 0;
 tell_room(me,"\n
[2J¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{  ¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x  ¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i
              ¢ª¢i¢x  ¢x¢i¢«              
                ¢i¢x  ¢x¢i      ¢­¢­      
                ¢i¢x  ¢x¢i      ¢­¢­¢­    
            ¢¨  ¢i¢x  ¢x¢i  ¢©    ¢­¢­    
            ¢ª  ¢i¢x  ¢x¢i  ¢«            
                ¢i¢x  ¢x¢i                
                ¢i¢x  ¢x¢i                
              ¢¨¢i¢x  ¢x¢i¢©              
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x  ¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i
¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}  ¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w

");
}
int open2(object me)
{
if(!me) return 0;
 tell_room(me,"\n
[2J¢w¢w¢w¢w¢w¢w¢{              ¢z¢w¢w¢w¢w¢w¢w
¢i¢i¢i¢i¢i¢i¢x              ¢x¢i¢i¢i¢i¢i¢i
        ¢ª¢i¢x              ¢x¢i¢«        
          ¢i¢x              ¢x¢i      ¢­¢­
          ¢i¢x              ¢x¢i      ¢­¢­
      ¢¨  ¢i¢x              ¢x¢i  ¢©    ¢­
      ¢ª  ¢i¢x              ¢x¢i  ¢«      
          ¢i¢x              ¢x¢i          
          ¢i¢x              ¢x¢i          
        ¢¨¢i¢x              ¢x¢i¢©        
¢i¢i¢i¢i¢i¢i¢x              ¢x¢i¢i¢i¢i¢i¢i
¢w¢w¢w¢w¢w¢w¢}              ¢|¢w¢w¢w¢w¢w¢w
");
tell_room(me,"\n  ¹Í!!.. ÅKªù¬ðµM¥´¶}¤F! \n");
set("exits",([
 "north" : __DIR__"pearl_22",
 "south" : __DIR__"pearl_24",
 "enter":__DIR__"pearl_25",
]));
set("item_desc",([
"gate":"\n
¢w¢w¢w¢w¢w¢w¢{              ¢z¢w¢w¢w¢w¢w¢w
¢i¢i¢i¢i¢i¢i¢x              ¢x¢i¢i¢i¢i¢i¢i
        ¢ª¢i¢x              ¢x¢i¢«        
          ¢i¢x              ¢x¢i      ¢­¢­
          ¢i¢x              ¢x¢i      ¢­¢­
      ¢¨  ¢i¢x              ¢x¢i  ¢©    ¢­
      ¢ª  ¢i¢x              ¢x¢i  ¢«      
          ¢i¢x              ¢x¢i          
          ¢i¢x              ¢x¢i          
        ¢¨¢i¢x              ¢x¢i¢©        
¢i¢i¢i¢i¢i¢i¢x              ¢x¢i¢i¢i¢i¢i¢i
¢w¢w¢w¢w¢w¢w¢}              ¢|¢w¢w¢w¢w¢w¢w
\n",]));
}

int closedoor(object me)
{
if(!me) return 0;//by pudon
tell_room(me,"\n  ÅF!!ªº¤@Án.. ÅKªù¤SÃö°_¨Ó¤F¡C \n");
 set("exits",([
 "north" : __DIR__"pearl_22",
 "south" : __DIR__"pearl_24",
 ]));
 set("item_desc",([
 "gate":"\n
¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢s¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i    ¤W­±ÁÙ¦³´X­Ó«ö¶s¡C
                ¢ª¢i¢x¢i¢«                     ¢z¢w¢s¢w¢s¢w¢{
                  ¢i¢x¢i      ¢­¢­             ¢x¢¶¢x¢·¢x¢¸¢x
                  ¢i¢x¢i      ¢­¢­¢­           ¢u¢w¢q¢w¢q¢w¢t ¨Ï¥Î¤èªk:
              ¢¨  ¢i¢x¢i  ¢©    ¢­¢­           ¢x¢³¢x¢´¢x¢µ¢x
              ¢ª  ¢i¢x¢i  ¢«                   ¢u¢w¢q¢w¢q¢w¢t press [¼Æ¦r]
                  ¢i¢x¢i                       ¢x¢°¢x¢±¢x¢²¢x
                  ¢i¢x¢i                       ¢u¢w¢q¢w¢q¢w¢t
                ¢¨¢i¢x¢i¢©                     ¢x¡¯¢x¢¯¢x¡­¢x
¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢x¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i     ¢|¢w¢r¢w¢r¢w¢}
¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢r¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w
\n",
]));
return 1;
}
