// 掃地小和尚 with Ascii Art By Tmr -2002/02/25-
#include <ansi.h>
inherit NPC;
void create()
{
         set_name("掃地小和尚", ({ "bonze" }) );
        set("level",4);
        set("race","人類");
        set("gender","男性");
          set("age",8);
          set("title","凌雲寺");
set("long",@LONG
                                                                                
    ╭───╮                                                                  
    │ [0;1m�[1mG[1m�[1mG[1m [0m│                                                                  
   ｑ [0;1;32m�[1m�[1m [1m [1m�[1m�[0m ｐ                                                                 
    ╰ [0;1;31m [1m�[1m�[1m [0m ╯│                                                                
[0;1m [1m [1m [1m [0m[0;1m�[1m�[1;33;43m�[1m�[1m�[1m�[1m�[1m�[0m◣│                                                                
[0;1m [1m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1mi[1m [1m [0m[0;1;33m/[1m�[1mq[1m\[1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [0m
[0;1m [1m [1m [1m [1m [1m [1m [1m�[1m�[1m�[1m�[1m [1m [1;33m�[1m�[1m�[1m�[1;37m [1m [1m [0m
LONG
);
        setup();
}
