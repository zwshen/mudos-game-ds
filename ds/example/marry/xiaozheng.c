// Room: /d/ruzhou/xiaozheng.c 马
// llm 99/02

inherit ROOM;

void create()
{
	set("short", "马");
	set("long", @LONG
硂ń竒秈马ぃ琌い沛笵玭
烽┕獽ㄏ眔硂ń篊篊羉篴癬ㄓㄏ眔硂ńセ
ぶ矪常琌︽︹打
LONG
	);

	set("exits", ([
		"south" : __DIR__"yidao1",
		"north" : __DIR__"ruzhou",
                "west" : __DIR__"yingbin-lou1",
	]));

	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



