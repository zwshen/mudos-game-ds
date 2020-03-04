#include <ansi.h>
inherit ROOM;
int check_killer();
void create()
{
set("short", "[1;36m©Ô¿p¥¾®ÈÀ][m");
set("long",@LONG

  ³o¶¡®ÈÀ]ªº¾ú¥v¤Q¤À±y¤[¡MÂ\³]¤]·¥¬°¾ë¯À¡C®ÈÀ]¦ÑÁó
¦è¸Ëµ§®¼ªº¯¸¦bÂdÂi¿Ë¦Û¬°®È«ÈªA°È(service)¡C                       
       ¢z¢s¢{          ¢z¢s¢{                  ¢j
       ¢u¢q¢t          ¢u¢t¢x                  ¢j
       ¢|¢r¢}          ¢|¢r¢}[1;32m¡\[m   ¡Å¡Å         ¢j
¡Å                         [1;32m¡ì[1;31m¡¯[1;32mùû[m ¢©  ¢­       ¢j
¢¨¡Å    ¢z¢w¢w¢w¢{          [1;32m/_|_*[m ¢i¢©  ¢­___O_¢j
¢«¢¨¡Å¡Ã¢x[1;33m½Ğ¤W¼Ó[m¢x¡Ã¡Ã¡Ã¡Ã¡Ã \_/¡Ã¢ª¢i¢©  ¢­/Y\¢­
¡Ã¢«¢¨¡Å¢|¢w¢s¢w¢}                  ¢ª¢i¢©  ¡Ã¡Ã¡Ã¡Ã¢­
  ¡Ã¢«¢¨    ¢r                        ¢ª¢i¢i¢i¢i¢i¢i¢i
    ¡Ã¢«                                ¢ª¢i¢i¢i¢i¢i¢i
¡Ã¡Ã¡Ã
LONG
);
set("item_desc", ([
"window":@NOTE
[1;32mµ¡¥~¤H¨Ó¤H©¹ªº¡Aºc¦¨¤@´T©M¥­¼Ö¾xªº´º¶H¡C[m
NOTE
]) );        
 set("light",1);
  set("no_clean_up", 0);
 set("objects",([
 __DIR__"npc/lamuza":1,
 ]));
 set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"pearl_8",
  "up" : __DIR__"pearl_38", 
 ]));
 setup();
}
void init()
{
 check_killer();
}
int check_killer()
{
 object me;
 me=this_player();
 if(me->query_temp("killer"))
 {
  message_vision(HIR"\n®ÈÀ]¦ÑÁó¤j½|: $N¤£­ã¶i¨Ó!!\n\n §Ú­Ì³o¸Ì¤£Åwªï±ş¤H¨g!!!\n\n"NOR,me);
  me->move(__DIR__"pearl_8");
  message_vision(HIY"\n$N³Q®ÈÀ]¦ÑÁó½ğ¤F¥X¨Ó..\n\n"NOR,me);
  return 0;
 }
 return 1;
}