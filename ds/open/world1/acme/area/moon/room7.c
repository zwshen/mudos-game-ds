inherit ROOM;

void create()
{
	set("short","靈月之間");
	set("long", @LONG
一步入此處，你馬上被這裡莊嚴的氣息所感染而不自覺的收斂起
自己嘻笑的面容。你向四周望了一圈，發現四周圍靠著牆擺放了許多
的雕像。原來此處就是月族為了紀念開創本族的先人以及歷代的族長
，而特別尋來巧匠雕出了這許多栩栩如生的人像。據說這間靈月之間
還藏有一個鮮為人知的秘密，只有月族的領導者們才有機會知道。

LONG
	);
	set("exits",([
  "south" : __DIR__"room6.c",
]));
   set("no_recall",1);
	set("objects",([
//__DIR__"item/moon_statue" :1,
__DIR__"item/moon_statue2" :1,
//add by manto 2006.06.09
]));
//	set("item_desc",([
//  "雕像":@STATUE
//
//STATUE
//,
//]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
//	call_other( "/obj/board/dragon_club_b", "???" );
}

