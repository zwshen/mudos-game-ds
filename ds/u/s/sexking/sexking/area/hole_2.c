#include <ansi.h>
inherit ROOM;
string look_string();
void create()
{
  set ("short", HIR"test"NOR);
  set ("long", @LONG
這裡就是傳說中的封印之窟了，只有真正的勇者們才有資
格挑戰封印之窟的考驗，曾經進入封印之窟挑戰的人有千百人，
但到了最後活著出來的卻只有六個人，這六位勇士的名聲就因
此永遠的得到江湖上的歌頌。
LONG
);
        set("light",1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
        "enter" : __DIR__"hole_2",
  ]));
        setup();
}
