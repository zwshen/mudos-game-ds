#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "花燈大會");
	set("long", @long
這裡正是一年一度的中秋節的花燈大會場地，這裡人山人海，擠
迫得很。你的頭上滿是一堆堆五彩漂艷的花燈，有紅有綠有黃，款式
多而創新，應有盡有，為這裡營造了一個很好的氣氛。
領了獎的有: ferrero,drjr,andygi,hcc,been,monk,abaw,ericsson
long);
	set("exits", ([
		"east" : __DIR__"en2",
		"west" : __DIR__"room",
	]));
	set("objects", ([
//                "/obj/board/record" : 1,
	]));
	set("light", 1);
	set("no_recall", 1);

	setup();
}
