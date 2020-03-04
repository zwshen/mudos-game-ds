// Room: /u/a/alickyuen/area/inn3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;36mST¡DSOFT¢I¦a¤U¤G¼Ó[2;37;0m");
	set("long", @LONG
³oùØ¬O³o¶¡®ÈÀ]ªº¦a¤U¤G¼Ó¡A¤G®Ç³£¬O¤@±Æ±Æªº©Ð¶¡¡A¬O¥Î¨Ó¯²µ¹«È
¤H¦íªº¡C¦p§A¦³°ÝÃDªº¸Ü¡A¥i¥H¸ß°Ý³o¸ÌªºÃÑ­û¡C
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"inn4",
  "up" : __DIR__"inn2",
]));
set("objects", ([
__DIR__"npc/keeper2" : 1,
]));
set("no_kill",1);
set("no_cast",1);
set("no_exert",1);
set("no_fight",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
        add_action("typepush","push");
}
int valid_leave(object me, string dir)
{
        if( dir!="north" )return ::valid_leave(me, dir);

        if( dir=="north" && me->query_temp("pushpass") <=0 || !me->query_temp("pushpass") )
                return notify_fail(HIW"_____________\n"NOR
                           HIW"¡U½Ð¿é¤J±K½X¡U\n"NOR
                           HIW"_____________\n"NOR
                                  HIW"¡U¢¸¡U¢·¡U¢¶¡U\n"NOR
                                  HIW"¡U¢µ¡U¢´¡U¢³¡U\n"NOR
                                  HIW"¡U¢²¡U¢±¡U¢°¡U\n"NOR
                                  HIW"¡U¢Ó¢Ü¢â¢Ó¢à¡U\n"NOR
                                  HIW"¡U__________¡U\n"NOR
);

        return ::valid_leave(me, dir);
}
int typepush(string arg)
{
object me;
me=this_player();
if(!me->query_temp("bookroom") ) return notify_fail("§A¨S¦³­q©Ð¶¡¡C\n");

if (arg!="5" ) return notify_fail("±K½X¿ù»~¡I¡I\n");
{
tell_object(me,"±K½X¥¿½T¡C\n");
me->delete_temp("bookroom");
me->set_temp("pushpass",1);
}
return 1;
}