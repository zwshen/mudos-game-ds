#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�P"HIY"��"HIW"��"HIR"��"NOR);
 set("long",@LONG 

[0;1;37m�[1m�[1m�[1mX[0;1;5;35m�[1;5m�[0;1;37m�[1mD[0;1;5m�[1;5m�[0;1m�[1mX[1m [1m�[1mD[0;1;5;34m�[1;5m�[0;1;37m�[1mO[1m�[1mX[1m�[1m�[1m�[1mX[0;1;5;33m�[1;5m�[0;1;37m�[1mD[1m�[1mX[1m [1m�[1mD[1m�[1mO[1m�[1mC[1m�[1m�[1m�[1mX[0m
[0;1;5;32m�[1;5m�[0;1;37m [1m�[1mD[1m�[1mO[1m�[1mX[1m�[1m�[1m�[1mX[1;30m [0;1;5;35m�[1;5m�[0;1;37m�[1mD[1m�[1mD[1m�[1mO[1m�[1mX[1m�[1m�[1m�[1mX[1m�[1mD[0;1;5;37m�[1;5m�[0;1;37m�[1mX[0;1;5;31m�[1;5m�[0;1;37m�[1mX[1m�[1m�[1m�[1mX[0m
[0;1;37m�[1mX[1m�[1m�[1m [1;31m�[1m�[1m�[1m�[1m�[1mP[1m�[1m�[1m�[1mL[1m�[1m�[0;1;5m [1;5;36m�[1;5m�[0;1;37m�[1mX[1m [1m�[1mD[1m�[1mO[0;1;5;32m�[1;5m�[0;1;37m�[1mX[1m�[1m�[1m�[1mX[1m�[1mD[1m�[1mX[1m�[1mX[0m
[0;1;37m�[1m�[1m�[1mX[1m�[1mD[1m�[1mX[0;1;5;36m�[1;5m�[0;1;37m [1m�[1mD[1m�[1mO[1m�[1mX[1m�[1m�[1m�[1mX[1m�[1mD[1m�[1mX[1m�[1m�[1m�[1mX[1m�[1mD[0;1;5;34m�[1;5m�[1;5;33m�[1;5m�[0;1;37m�[1mX[1m [1m�[1mD[1m�[1mO[0m
[0;1;37m�[1mX[1m�[1mD[0;1;5m�[1;5m�[0;1m�[1mX[1m [1m�[1mD[0;1;5;36m�[1;5m�[0;1;30m�[1mO[1;31m�[1m�[1m�[1m][1m�[1mn[1m�[1ml[1m�[1m�[1m�[1mA[1;37m [1m�[1mX[1m�[1mD[1m�[1mX[1m�[1mX[1m�[1mD[0;1;5;31m�[1;5m�[0m
[0;1;37m�[1mD[1m�[1mO[1m�[1mX[1m�[1m�[0;1;5;32m�[1;5m�[0;1;37m�[1mX[1m�[1mD[1m�[1mX[1m�[1m�[1m�[1mX[1m�[1mD[0;1;5;35m�[1;5m�[0;1;37m�[1mX[1m [1m�[1mD[1m�[1mO[1m�[1mX[1m�[1m�[1m�[1mX[1m�[1mD[1m�[1mX[0m
[0;1;37m�[1mD[1m�[1mO[1m�[1mX[1m�[1m�[1m�[1mX[0;1;5;37m�[1;5m�[0;1;37m�[1mD[1m�[1mX[1m�[1mD[1m�[1m�[1m�[1mO[1m�[1mX[1m�[1mX[1;31m�[1m�[1m�[1m�[1m�[1m�[1m�[1mR[1m�[1mA[1;37m�[1m�[0;1;5;33m�[1;5m�[0;1;37m�[1mX[0m

LONG
    );
 
 set("exits",(["out":"/d/wiz/hall1",
               "past":"/open/world1/meetroom",
     ]));
 set("no_clean_up", 0);
 setup();
  call_other("/obj/board/uchimaha_b" , "???");
}           

