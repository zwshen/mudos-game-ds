#include <ansi2.h>
inherit ITEM;
void create()
{
  set_name("123123", ({ "ch","ccchhh" }));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
    set("long","\n");
  setup();
}
void init()
{
  add_action("do_ch1","ch1");
}

int do_ch1(string arg)
{
        object me=this_player();
        me->set("env/msg_mout",HIW"\n"
"[0;1m¢[1mz[0m¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{ \n"
"¢x   ¹p§J´µ                     ¢x\n" 
"¢x       ­¸¥h§Oªº¦a¤è           ¢x\n" 
"¢x            »¨  Ïm  ¤F        ¢x\n" 
"¢x      ¢¨¢i¢i¢©                ¢x\n"
"¢x      ¢i    ¢ª¢m              ¢x\n"
"¢x      ¢«¡¼¡_¡¼¢m              ¢x\n"
"¢|¢w¢w¢B¢­  ¤f¡ş¢w¢w¢w¢f¢w¢w¢w¢w¢}\n"
" ¡Ã¡Ã¡Ã¢ª¡Ã¡h¡Ã¢©¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã\n"
"         ¢j  ¢y\n"
"         ¢«¡Ã¢ª\n"); 
        me->set("env/msg_min",HIW"\n"
"[0;1m¢[1mz[0m¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{ \n"
"¢x   ¹p§J´µ                     ¢x\n" 
"¢x       ­¸¨Ó³o¸Ì               ¢x\n" 
"¢x            »¨  Ïm  ¤F        ¢x\n" 
"¢x      ¢¨¢i¢i¢©                ¢x\n"
"¢x      ¢i    ¢ª¢m              ¢x\n"
"¢x      ¢«¡¼¡_¡¼¢m              ¢x\n"
"¢|¢w¢w¢B¢­  ¤f¡ş¢w¢w¢w¢f¢w¢w¢w¢w¢}\n"
" ¡Ã¡Ã¡Ã¢ª¡Ã¡h¡Ã¢©¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã\n"
"         ¢j  ¢y\n"
"         ¢«¡Ã¢ª\n");
 
me->save();
return 1;
}
