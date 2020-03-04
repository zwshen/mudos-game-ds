#include <path.h>
inherit ROOM;

void create()
{
	set("short", "»AªL");
	set("long", @LONG
¦b§Aªº¨­®Ç³£¬O«C»Aªº¦ËªL¡AÀHµÛ­·§jªL¤¤ªº¦Ë¸­¤£®É¦aµo¥X¨F¨Fªº
Án­µ¡C¬Û¶Ç»AªL¸Ì¬O»D¦W¤w¤[ªº[35m¡y§Å¬r±Ð¡z[m¡CµL·N¶¡§Aµo²{¦b»AªL®Ç¦³¤@
­ÓµP¤l(sign)¡C
LONG
	);

	set("item_desc", (["sign":@NOTE
[1;32m
		§Å¬r±Ð(voodoo)¸T¦a,«D½Ð¤Å¤J¡C
		¦pªG¤£¥´ºâ¶i¥h½Ð¥X¥h(out)¡C
		¤]³\§A¥i¥H enter voodoo ¶i¤J§Å¬r±Ð¡C

[m
NOTE
        ]) );

//	set("exits", ([ /* sizeof() == 1 */
//	    "enter" : "/u/s/shengsan/voodoo/room01",
//            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_out","out");
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="voodoo")
		return notify_fail("§A­n¶i¤J­þ¸Ì¡H\n");
	if(query_temp("user")>10)
		return notify_fail("§A¥H¬°³o¸Ì¬OÆ[¥ú³Ó¦aªü¡H\n");
	add_temp("user",1);
	me->move(__DIR__"room01");
	return 1;
}

int do_out(string arg)
{
	object me;
	me=this_player();
	if(query_temp("user")>0)
		add_temp("user",-1);
	me->move(SHENGSAN+"wisland/land24");
	return 1;
}
