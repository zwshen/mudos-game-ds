#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "教主專用間");
        set("long",@LONG
這是明教之中歷代教主專用的房間，由於明教採用雙首長制，所以
這裡也就成為兩大教主密談知地，四周擺滿了稀有的用品，虎皮製
的地毯再加上七彩水晶吊燈散發出柔和的感覺，桌子上擺滿了珍奇
異玩，角落的兩張大床上放著貂皮製成的寢具，床上的蚊帳還用金
絲織成，一切的富麗堂皇難以言喻。
LONG
        );
        set("light",1);

        set("exits",([
  "down": __DIR__"mingsaint",
]));
        set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
        setup();
}

