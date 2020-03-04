#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "長老室");
        set("long", @long
這裡是族王與眾長老們定期舉行開會的會議室，你可以看到房間
的中央擺了一張圓桌。在這邊討論神族的所有大大小小的決議事項，
上至幫規修定，下至族人違紀懲罰。

long);
        set("exits", ([
  "south" : __DIR__"ladd-2",
]));
        set("objects", ([ 
  __DIR__"item/god_box.c" : 1,
]));
        set("light", 1);
        setup();
        set("stroom", 1);
        call_other("/obj/board/club_god_2.c", "???");
}
void init()
{
     if( CLUB_D->check_member("god",getuid(this_player())) < 3 && !wizardp(this_player()))
        {
                this_player()->move(__DIR__"ladd-2");
                message_vision(HIY" 天神對$N說: 這裡不是你該來的地方喔。\n"NOR, this_player());
        }
}

