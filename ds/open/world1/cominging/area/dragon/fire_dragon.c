#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"狂龍幫"HIM"－"HIY"火龍堂"NOR);
	set("long", @LONG
    這�堿O狂龍四堂之一 －【火龍堂】
正所謂「樹大有枯枝 」，本幫亦不例外。
有些幫眾為了一己私利，拿取幫中的裝備(EQ)去買，而本堂的責任。
就是要將犯規之幫眾加以刑罰，以保持本幫聲譽。
你看到堂中放有許多刑具，看得你毛骨悚然。
而牆上掛著許多鞭子..你心裡想....莫非...這是.........    
LONG
	);
	set("exits",([
  "northwest" : __DIR__"dragon.c",
]));
	set("item_desc",([
  "鞭子" : "一些帶有血色的鞭子, 想是殺過不少人的！\n",
]));
	set("light",1);
set("no_goto",1);
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	setup();
     call_other("/obj/board/dragon_quest_b.c", "???");
}
