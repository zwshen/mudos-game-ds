#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIG"村長家"NOR);
        set("long", @LONG
這裡是愛門村村長的家，一進門就可以感覺與尋常的農舍不同。愛門村
的村長是一名飽經世事的年老戰士，雖然體力早已大不如前，但身上仍然保
持著一股英豪之氣。前方的牆壁上掛了一副破舊的盔甲，是村長年輕時候仗
義行俠留下來的寶貝。
LONG
        );
        set("exits", ([
      "west":__DIR__"al4",
]));
        set("objects", ([
        __DIR__"npc/mayor" :1,
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
