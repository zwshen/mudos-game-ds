#include <ansi.h>
inherit CLUB_BANK;

void create()
{
	set("short","崇武房");
	set("long", @long
一間設施完善的練武房，整個房間呈現五邊形，地板正中央是一個太極圖
周圍牆上掛滿了各式武器，及練武器材，其中正前方的木櫃中放有各家的
武功祕笈，房間中擺置精工打造，巧心設計的機關銅人。
long);
	set("exits", ([
		"west" : __DIR__"room15",
	]));
	setup();
}
