// Room: /u/a/aiwa/room/home.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIG+"¦ãµØ¤u§@«Ç"+NOR);
	set("long", @LONG
¯u¬O¥O¤HÅå³Y¡I¦b³o»ò¤@­Ó¤£°_²´ªº¤p«Î¸Ì¡A©~µM¦³¦p¦¹¥ý¶i ¡H
ªº³]³Æ¡A©Ò¦³©~®a¥Í¬¡¥Î«~À³¦³¾¨¦³¡I§A¬Ý¨ì¦³­Ó¤H¥¿§¤¦b¹q¸£
«e»Eºë·|¯«ªº¾Þ§@µÛ¹q¸£¡A ÁÙ¬O¤£­n¥h¥´ÂZ¥L¦n¤F¡I 
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
            ]));

	set("light", 1);

	set("exits", ([ /* sizeof() == 7 */
		"out" : "/u/a/aiwa/workroom",
            ]));

	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me=this_player();
	add_action("do_out","out");
	if(me->query("id")!="aiwa")
		tell_object(me,"\n"HIW+"¬Y¤H(Somebody)§i¶D§A: ¤£­n¥´ÂZ¥L¼gµ{¦¡³á!!\n");
}

void do_out()
{
	object me;

	me = this_player();
	tell_object(me,"\n\n[1;37mÁÂÁÂ¥úÁ{¦ãµØ¤u§@«Ç\n\n");
	tell_object(me,"¦³ªÅ¦A¨Ó§¤³á¡I[m\n\n\n");
}