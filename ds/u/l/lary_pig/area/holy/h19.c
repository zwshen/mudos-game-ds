#include "path.h"
inherit ROOM;

void create()
{
        set("short", "射手宮");
        set("long", @LONG
黃道十二宮的第九宮 ─ 射手宮，射手星座，其圖形所組成的，
是一位手持弓箭，英勇的人馬族勇士，相傳，人馬族，各個都是使用
弓箭的高手，據傳文，其箭術出神入化，人類根本難以與之並駕齊驅
，但事實與否，誰也不知道。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h20",
 "westdown" : HOLY+"h18",
        ]) );
        set("light",1);
        setup();
}
