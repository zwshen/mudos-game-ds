#include <ansi.h>
inherit ROOM;
void printmessage(int time,object room);
void create()
{
        set("short", "森林出口近處");
        set("long", @LONG
這裡就要到了出口了，你頭頂上的樹木也漸漸的變少了，也沒有嘈
雜的昆蟲，鳥類的叫聲了，耳根子似乎清淨了不少，也比較安靜了，北
邊就是森林的出口了，東邊則是回到森林之中繼續逛。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fgo9.c",
  "east" : __DIR__"fgo7.c",
]));
        set("objects",([
  __DIR__"npc/obj/wtree.c" : random(4),
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}

void printmessage(int time,object room)
{
  object me;
  me = this_player();
  if(time) tell_room("/open/world1/cominging/area/fgo8",HIY"地面上突然裂了一個縫出來!\n"NOR);
  else tell_room("/open/world1/cominging/area/fgo8",HIC"地面上的縫突然不見了!\n"NOR);
  return;
}
