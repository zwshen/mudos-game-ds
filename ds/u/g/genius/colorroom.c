#include <room.h>
#include <ansi.h>
#include <ansi2.h>
inherit ROOM;
void create()
{
set("short",HIG"五"HIY"顏"HIC"六"HIR"色"HIM"研"HIB"究"HIW"室"NOR);
set("long",    "\n這裡充滿了各式各樣的顏色\n\n"
               "這是"BLK"$BLK$色"NOR"　　　這是"NOR"$NOR$色\n"NOR
               "這是"RED"$RED$色"NOR"　　　這是"HIR"$HIR$色\n"NOR
               "這是"GRN"$GRN$色"NOR"　　　這是"HIG"$HIG$色\n"NOR
               "這是"YEL"$YEL$色"NOR"　　　這是"HIY"$HIY$色\n"NOR
               "這是"BLU"$BLU$色"NOR"　　　這是"HIB"$HIB$色\n"NOR
               "這是"MAG"$MAG$色"NOR"　　　這是"HIM"$HIM$色\n"NOR
               "這是"CYN"$CYN$色"NOR"　　　這是"HIC"$HIC$色\n"NOR
               "這是"WHT"$WHT$色"NOR"　　　這是"HIW"$HIW$色\n\n"NOR

               "這是"BBLK"$BBLK$色"NOR"　　　這是"HBWHT"$HBWHT$色\n"NOR
               "這是"BRED"$BRED$色"NOR"　　　這是"HBRED"$HBRED$色\n"NOR
               "這是"BGRN"$BGRN$色"NOR"　　　這是"HBGRN"$HBGRN$色\n"NOR
               "這是"BYEL"$BYEL$色"NOR"　　　這是"HBYEL"$HBYEL$色\n"NOR
               "這是"BBLU"$BBLU$色"NOR"　　　這是"HBBLU"$HBBLU$色\n"NOR
               "這是"BMAG"$BMAG$色"NOR"　　　這是"HBMAG"$HBMAG$色\n"NOR
               "這是"BCYN"$BCYN$色"NOR"　　　這是"HBCYN"$HBCYN$色\n"NOR
);


      set("exits", ([
      "west": "/u/g/genius/roomenter.c",
      ]));
      set("light",1);
}

