#include "path.h"
inherit ROOM;

void create()
{
        set("short", "宇宙空間");
        set("long", @LONG
這是一個十分奇妙的空間，四周有如無窮無盡的擴大，及永無止
盡的黑暗，在你的周圍，有著許多，有如球狀的發光體，你的眼前，
是一顆巨大，且帶著寶藍色光芒的圓球，而在圓球的不遠處，又有一
顆更為巨大的火球，到底，如此神秘的空間，到底是那呢？
LONG
        );

        set("exits", ([
  "east" : "kni2",
 "west" : "kni3",
        ]) );
        set("light",1);
        setup();
}
