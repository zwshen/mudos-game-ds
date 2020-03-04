// Room: /u/a/aiwa/workroom.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIG+"¥@¥~®ç¶é"+NOR);
	set("long", @LONG
§A¨Ó¨ì¤F¤@­Ó¬Ý¦ü¤Ñ°óªº¦a¤è¡C¦³¤p¾ô¡B¦³¬y¤ô¡A¦³¤@¤ù¯ó¦a¡A
§ó¦³¤@®y¤p´ò¡A¦b´ò¤¤¦³¤@¶¡¤p«Î¡C¬O¤£¬O¥P¤H¦í¦b¸Ì­±©O¡H§A
¥i¥H¶i¥h(enter)¬Ý¬Ý¡I
LONG
	);
	set("objects", ([
            ]));

	set("light", 1);

	set("exits", ([ /* sizeof() == 7 */
		"enter"	: __DIR__"home",
		"wiz"	: "/d/wiz/hall1",
		"shengsan" : "/u/s/shengsan/workroom",
		"luky"	: "/u/l/luky/workroom",
            ]));

	set("valid_startroom",1);
	set("no_clean_up", 0);
       	setup();
        call_other("/obj/board/aiwa_b", "???");
}

void init()
{
	add_action("do_enter","enter");
}

void do_enter()
{
	object me;
	me = this_player();
	tell_object(me,"\n\n[1;37m§A¨«¹L´òÃäªº¤p¾ô¡A¨ì¹F¤p«Îªºªù¤f¡A¥¿¥´ºâºVªù\n");
	tell_object(me,"ªº®É­Ô¡A©¿µMÅT°_¤F¤@°}»È¹a¯ë²M¹ýªºÁn­µ¡ã[m\n\n");
	tell_object(me,"[1;35mÅwªï¥úÁ{¦ãµØ¤u§@«Ç[m\n\n\n");
}
