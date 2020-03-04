#include <room.h>
#include <ansi.h>
inherit ROOM;

void do_change(string str);

void create()
{
	set("short",HIC"¸«¤ë·R¤§«Î"NOR);
	set("long",@LONG
³o¸Ì¬OÅ]ªkªù¥@¬É¤¤ªº°ª¯Å¦í¦v°Ï
¤£¬O´¶³q¤H¦íªº°_ªº³á
·R¤§«Î°â»ù:
¤@¶¡©Ð		50¸U coin
buyhome  <ÁÊ¶R·R¤§«Î>
myhome   <¦^¨ì·R¤§«Î>
setlong  <­×§ï®along>Ê>
setshort <­×§ï®ashort>Ê>
LONG
);
	set("exits",([
	"down":"/open/clc/start/enter",
	]));
	set("objects",([
	]));
	set("light",1);
	setup();
}

void init()
{
	add_action("do_home","myhome");
	add_action("do_buy","buyhome");
	add_action("do_setlong","setlong");
	add_action("do_setshort","setshort");
}

int do_buy()
{
	object env,me;
	string file,str;
	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(me->query("coin")<500000)
                return notify_fail("§A¨­¤W¨S¦³¨º»ò¦h¿ú¡C\n");
	if(file_size(file)!=-1)
                return notify_fail("§A¤w¸g¦³¤@¶¡«Î¤l¤F¡C\n");
	str = @ROOM_CODE
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit "/std/saveeq";

void create()
{
ROOM_CODE
	;

	str +=sprintf("set(\"short\",HIG\""+me->query("name")+"ªº·R¤§«Î\"NOR);");
	str +=@ROOM_CODE2
        set("long",@LONG
³o¶¡©Ð¶¡¯àÀx¦s¨­¤Wªº¹D¨ã©Î¬O¸Ë³Æ
¥Ø«e¯àsave 10¥ó¹D¨ã......Åwªï¤j®a§äbug
¤èªk:
putin  ¦WºÙ
getout ½s¸¹
list
LONG);
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}

ROOM_CODE2
	;
	write("«Ø³y "HIR + me->query("name") + NOR" ªº·R¤§«Î....");
	if( write_file(file, str) )
	{
		write("¦¨¥\\\n");
		me->add("coin",-500000);
	}	
	me->set("item/item1","");
	me->set("item/item2","");
	me->set("item/item3","");
	me->set("item/item4","");
	me->set("item/item5","");
	me->set("item/item6","");
	me->set("item/item7","");
	me->set("item/item8","");
	me->set("item/item9","");
	me->set("item/item10","");

return 1;
}

int do_home()
{
	object env,me;
	string file,str;
	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("§A¨S¦³¶R©Ð¤l«ç»ò¦^®a°Ú¡C\n");
	me->move(file);
	write("\n¸g¹L¤@¤Ñªº©bªi, ²×©ó¦^¨ì·Å·xªº¤pºÛ¤F\n");
	
return 1;
}


int do_setlong()
{
	object env,me;
	string file,str;

	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("§A¨S¦³©Ð¤l¡C\n");

        me->edit( (: call_other, __FILE__, "do_change" :) );

	return 1;
}

void do_change(string str)
{
	object me,room,env;
	string file,nf;
	me=this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	nf = @ROOM_CODE

#include <room.h>
#include <ansi.h>
inherit "/std/saveeq";
inherit ROOM;

void create()
{
ROOM_CODE
	;
	nf += sprintf("\tset(\"short\", %O);\n", new(file)->query("short") );
	nf += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", str );
	nf += @ROOM_CODE2
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}
ROOM_CODE2
	;
	rm(file);
	write("­×§ï ·R¤§«Î....");
	if( write_file(file, nf) ) {
		write("Ok......\n");
		if(!find_object(file))
			return ;
		destruct(find_object(file));
		return ;
	} else
		return notify_fail("§A¨S¦³­×§ï©Ð¤lªºÅv§Q, ³qª¾eeman³B²z¡C\n");

	return ;
}

int do_setshort(string str)
{
	object room,env,me;
	string file,nf;

	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("§A¨S¦³©Ð¤l¡C\n");

	if(!str || str=="")
                return notify_fail("setshort <±Ô­z>¡C\n");

	nf = @ROOM_CODE

#include <room.h>
#include <ansi.h>
inherit "/std/saveeq";
inherit ROOM;

void create()
{
ROOM_CODE
	;
	nf += sprintf("\tset(\"short\", %O);\n", str );
	nf += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", new(file)->query("long") );
	nf += @ROOM_CODE2
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}
ROOM_CODE2
	;
	rm(file);
	write("­×§ï ·R¤§«Î....");
	if( write_file(file, nf) ) {
		write("Ok......\n");
		if(!find_object(file))
			return 1;
		destruct(find_object(file));
		return 1;
	} else
		return notify_fail("§A¨S¦³­×§ï©Ð¤lªºÅv§Q, ³qª¾eeman³B²z¡C\n");

	return 1;
}
