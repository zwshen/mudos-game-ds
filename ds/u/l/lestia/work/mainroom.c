inherit ROOM;
#include <ansi.h>
#include <room.h>
void create()
{
        set("short", HIW""BLK"邪闇"HIW"之間"NOR);
        set("long",
"\n你站在一片虛無的大地之中，灰暗的天緩緩的流動著，\n"
"你眼觀四周，發現這裡除了沉寂之外還是沉寂，你沉默\n"
"不語，慢慢的將心中的雜念去除，只留下邪惡的念頭，\n"
"等待著最後之日的降臨。\n\n"
);
      set("light", 0);
        set("no_clean_up", 0);
 set("valid_startroom", 1); 
 set("exits", ([ 
"wiz":"/d/wiz/hall1",
"up":"/u/l/lestia/work/post.c",
"pray":"/u/l/lestia/work/pray.c",
"luky":"/u/l/luky/workroom.c",
 ])); 
        setup();
}
