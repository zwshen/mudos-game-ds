// Room: /u/l/luky/room/house.c
#include <ansi.h>
inherit HOUSE;
void create()
{
   set_name(HIG"Às½¼§O¹Ö"NOR, ({ "luky's house","house" }));
   set_short(HIG"Às½¼§O¹Ö"NOR,HIG"Às½¼§O¹Ö«ÈÆU"NOR);
   set_long(@OUTLONG
³o¬O¤@´ÉÀs½¼ªº§O¹Ö, ­n¶i¥hªº¸Ü´N enter house §a¡C

OUTLONG
,@INLONG

               ((((((((((\
                ((_  _  )))))
                ))e) e ((((((|
               (((<     ))))))
                  \o    .-'-.
                /  `--.( _    '-.
  ¦Ñ¤½ ~ ²Ö¤F¶Ü ~~    ::\  - _   '-.          _.-'''''-.
                      ::: ''-._-    '-.    .-'          `.
    §ÚÀ°§A©ñ¬~¾þ¤ô~~  :::.  ': '-._    :-:'              :
                      ::::    : : ::.   :.               :
                      ::::     ' : ::.   ::..          .:
                      :: o     : : ::::.  :::)        .:
                      : ::`-.-'`'-'-'-'-;  )/        .:         .-._
                     :  .:              /  ;        .: _       /_   '-.__
                    :  .:              (''o\       .:'' '''-.-';; '-.    )
                      .:                \ |`      /.-''-._  _.;.-..-'```
                   ' .:                  \:      /        '`._/_   '-.__
            __.---' .:                   :                     ; '-._    )
           '====d..:/                     :___,;,,,,,,,,,,,,,,,;;....-'''`

INLONG
); // ªø±Ô­z
/*
set("exits",([  //¥X¤f
"out":__DIR__"workroom",
]));
*/
set("light",1);
set("no_clean_up",1);
setup();

}
