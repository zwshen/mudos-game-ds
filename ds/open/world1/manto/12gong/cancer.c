#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "第四宮：巨蟹座");
        set ("long", @LONG

               :XxuxuX:::
        :uWW$$$$$$$$$$$$$$$Wix:
     :U$$$$$#""~~      ~~""##$$$ix      宇宙之神愛上了狩獵女神後
   !W$$$$$$$$$Wi:             ~~#*$W::  終日和她追逐於森林之中
  !$$*"~    ~"T$$$:                ~#8: 當狩獵女神生下一女兒
  $$?          ~$$$          :          神之后相當憤怒
 !$$            X$$    XWW$$$$$$$Wu:    派九頭巨蟹去殺害母女兩人
 !$$:       :  ~8$$  !$$$?~     ~?*$W:  狩獵女神為了保護自己的女兒
  ?$$X        !W$$! !$$!           #$8  勇敢的和巨蟹摶斗因而受傷
   ~T*$$WWW$$$$*!~  !$$            !$$  神之后被她的母愛所感動
       ~~"~!~       !$$X  :        W$$  讓小女孩升空成了巨蟹星座 ......
 !W::                ?$$Wx:     :!W$$!
  ~#$WU::             ~#*$$$WWW$$$$#~
     "#$$$Wxx::          ::W$$$$$#~
        ~"#$$$$$$$$$$$$$$$$$$#"~

LONG);

        set("exits", ([
       "northup"    :       __DIR__"room09",
       "southeast"  :       __DIR__"room08",     
        ]));

        set("objects", 
        ([ //sizeof() == 1
               __DIR__"npc/cancer" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

