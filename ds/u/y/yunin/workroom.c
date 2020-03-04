#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{  

        set("short",HIC"ªí©f"HIR"³Â±NÀ]"NOR);
        set("long", @LONG

[0;1;35m¤[1m£[1mº[1mÞ[1m§[1mA[1m¦[1mh[1m§[1mA[1m¼[1mF[1m®[1m`[0m
[0;1;35m¤[1m£[1mº[1mÞ[1m§[1mA[1m¦[1mh[1mµ[1mP[1mÄ[1mÖ[1m¦[1mh[1m¤[1m[[0m
[0;1;35m¤[1m£[1mº[1mÞ[1m§[1mA[1mª[1mø[1mª[1mº[1m«[1mç[1m¼[1mË[0m
[0;1;35m¤[1m£[1mº[1mÞ[1m§[1mA[1mª[1mø[1mª[1mº[1m¦[1mh[1m°[1mª[0m
[0;1;35m¤[1m£[1mº[1mÞ[1m§[1mA[1mª[1mø[1mª[1mº[1m¦[1mh[1m¸[1mG[0m
[0;1;35m¤[1m£[1mº[1mÞ[1m§[1mA[1mª[1mø[1mª[1mº[1m¦[1mh[1m­[1mD[0m
[0;1;35m¤[1m£[1mº[1mÞ[1m§[1mA[1mª[1mø[1mª[1mº[1m¦[1mh[1m½[1mG[0m
                [0;1;36mÅ[1mw[1m [1mª[1mï[1m [1m§[1mA[1m [1m¨[1mÓ[1m [1m½[1mð[1m [1mÀ[1m][1m¡[1mã[1m¡[1mã[0m
              [0;1m [1m [1m®[1mÇ[1mÃ[1mä[1m¦[1m³[1m­[1mÓ[1m([1;37mb[1mo[1ma[1mr[1md[1m)[1;37m½[1mÐ[1m¥[1mJ[1m²[1mÓ[1m¬[1mÝ[1m¬[1mÝ[1m³[1má[1m¡[1mã[1m¡[1mã[0m
LONG

        );
 set("exits", ([ /* sizeof() == 5 */
  "wiz" : "/d/wiz/hall1",
  "moonhide" : "/u/m/moonhide/workroom",
  "sdo" : "/u/s/sdo/workroom",
  "shadow" : "/u/s/shadow/workroom", 
  "shop" : __DIR__"shop",]));
set("light",1);
set("no_fight", 1);
set("no_cast", 1);
set("no_exert", 1);
set("no_magic", 1);
set("no_steal", 1);
set("objects", ([ /* sizeof() == 1 */
"/u/y/yunin/girl" : 1,
]));
set("item_desc",([
"board":@BOARD

[0;1;33m¤[1m@[1m¯[1më[1m°[1mò[1m¥[1m»[1mª[1mº[1m¾[1mÞ[1m§[1m@[1m¡[1mG[1m [1m¨[1mC[1mº[1mØ[1mµ[1mP[1m³[1m£[1m¦[1m³[1m¨[1mä[1m¥[1mN[1m½[1mX[1m¡[1m@[1m¨[1mÒ[1m¡[1mG[1m¤[1m@[1m¸[1mU[1m¡[1mÐ[1m¡[1mÖ[1m1[1mw[1m [1m¤[1mC[1m¯[1mÁ[1m¡[1mÐ[1m¡[1mÖ[1m7[1ms[0m

[0;1;33m¥[1m[[1m¤[1mJ[1mµ[1mP[1m§[1m½[1m¡[1mG[1ma[1md[1md[1mi[1mn[1m [1m [1m [1m [1m [1m [1m [1m [1m [1mº[1mN[1mµ[1mP[1m¡[1mG[1mm[1mo[1m [1m©[1mÎ[1m¬[1mO[1m [1m0[0m
[0;1;33m³[1m][1m©[1mw[1m½[1mä[1mª[1m`[1m:[1m [1mb[1me[1mt[1m [1m<[1m¼[1mÆ[1m¶[1mq[1m>[1m [1m [1m [1m [1m¥[1má[1mµ[1mP[1m¡[1mG[1md[1mu[1mm[1mp[1m [1mx[1mx[1m [1m©[1mÎ[1m¬[1mO[1m [1md[1md[1m [1mx[1mx[0m
[0;1;33m¶[1m}[1m©[1ml[1mµ[1mP[1m§[1m½[1m¡[1mG[1ms[1mt[1ma[1mr[1mt[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m¦[1mY[1m¡[1mG[1me[1ma[1mt[1m [1mx[1mx[1m [1mx[1mx[0m
[0;1;33m«[1m¶[1m}[1mµ[1mP[1m§[1m½[1m¡[1mG[1mr[1me[1ms[1mt[1ma[1mr[1mt[1m [1m [1m [1m [1m [1m [1m [1m¸[1mI[1m¡[1mG[1mp[1mo[1mn[0m
[0;1;33m¬[1mÝ[1mª[1m±[1m®[1ma[1m1[1mª[1mº[1mµ[1mP[1m¡[1mG[1m.[1m1[1m [1m [1m [1m [1m [1m [1m [1m [1m [1mº[1mb[1m¡[1mG[1mg[1mo[1mn[1m [1m([1m·[1mt[1mº[1mb[1m¥[1mÎ[1m [1mg[1mo[1mn[1m [1mx[1mx[1m)[0m
[0;1;33m¬[1mÝ[1mª[1m±[1m®[1ma[1m2[1mª[1mº[1mµ[1mP[1m¡[1mG[1m.[1m2[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m­[1mJ[1m¡[1mG[1mh[1mu[0m
[0;1;33m¬[1mÝ[1mª[1m±[1m®[1ma[1m3[1mª[1mº[1mµ[1mP[1m¡[1mG[1m.[1m3[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m¦[1mÛ[1m°[1mÊ[1m³[1m][1m©[1mw[1m:[1m [1ms[1me[1mt[1mm[1mj[1m [1m([1m¸[1mÔ[1m²[1mÓ[1m«[1mü[1m¥[1mO[1m½[1mÐ[1m¥[1m´[1m [1mh[1me[1ml[1mp[1m [1ms[1me[1mt[1mm[1mj[1m)[0m
[0;1;33m¬[1mÝ[1mª[1m±[1m®[1ma[1m4[1mª[1mº[1mµ[1mP[1m¡[1mG[1m.[1m4[1m [0m
[0;1;33m¬[1mÝ[1m¦[1mÛ[1m¤[1mv[1mª[1mº[1mµ[1mP[1m¡[1mG[1m.[1m [1m([1m©[1mÎ[1m¬[1mO[1mÆ[1m[[1m¾[1mÔ[1mª[1mÌ[1m¬[1mÝ[1m¥[1mØ[1m«[1me[1m¾[1mÔ[1mª[1mp[1m)[0m
[0;1;33mµ[1m¹[1m§[1mO[1m¤[1mH[1m¬[1mÝ[1m¦[1mÛ[1m¤[1mv[1mª[1mº[1mµ[1mP[1m:[1m [1ms[1mh[1mo[1mw[1mm[1mj[1m [1m<[1mi[1md[1m>[0m

[0;1;33m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m([1m¥[1mH[1m¤[1mW[1mª[1mº[1m [1mx[1mx[1m [1m¬[1m°[1mµ[1mP[1mª[1mº[1m¥[1mN[1m½[1mX[1m [1m [1m¨[1mÒ[1m¡[1mG[1me[1ma[1mt[1m [1m2[1mw[1m [1m3[1mw[1m)[0m
[0;1;33m³[1mÂ[1m±[1mN[1mª[1mº[1m°[1mò[1m¥[1m»[1m¹[1mC[1mÀ[1m¸[1m³[1mW[1m«[1mh[1m½[1mÐ[1m°[1mÑ[1m¦[1mÒ[1m [1mh[1me[1ml[1mp[1m [1mm[1mj[0m

BOARD,
]));

 set("no_clean_up", 0);

        setup();

        }

