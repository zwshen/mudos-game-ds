#define NOW_ROOM "/open/world2/lichi_town_1/map_5_6.c"
#include <path.h>
#include <ansi.h>
inherit ROOM;

static int *crystal = ({ 1,1,1 }); // ³]©w¤ô´¹¦s¦b¶Ü (µµ¦â,¥Õ¦â,¬õ¦â) 0 ¬°¨S¦³ 1 ¬°¦s¦b¥i¨Ñ¤ô 2 ¬°¥u¦s¦b¦ýµLªk¨Ï¥Î
static string *crystal_kind = ({ "purple", "white", "red" }); // ³]©w¤ô´¹ªººØÃþ (get¥Î)
static string *crystal_color_kind = ({ "[0;35mµµ¦â[0m", "[1;37m¥Õ¦â[0m", "[1;31m¬õ¦â[0m" });
string *locate = ({ "map_1_4.c", "map_1_5.c", "map_2_5.c", "map_3_5.c", "map_4_5.c", "map_5_3.c", "map_5_4.c", "map_5_5.c", "map_6_3.c" }); // ªe¬y¬y¹D
string *crystal_file = ({ COMINGING_PAST + "area/obj/purple_crystal.c", COMINGING_PAST + "area/obj/white_crystal.c", COMINGING_PAST + "area/obj/red_crystal.c" }); // ¤ô´¹

string query_crystal();
void random_moving(string file);
void show_message(object me, object ob);
void control(int flag);

void create()
{
/*
³o¸Ì´N¬O·É¤ô¤ô¬}¤F, ¥Rº¡µÛ·Ã®ð, ´X¥GªÅ®ð¤¤©Ò¦sªº, ³£ºÉ¬O¤ô®ð,
³oÃä¦³­Ó©_²§ªº¬W¤l, ¬O¤@­Ó[0;35mµµ¦â[0mªº¤ô´¹, ¤ô´¹µo¥X¤F¤@°}°}ªº¥ú¨~,
±µµÛ«K´é¥X³\¦h¤ô¥X¨Ó, ¤]³\³o­Ó´N¬O¥þ·É¿¤¸Ì©Ò¨ÑÀ³ªº¦a¤U¤ôªº¨Ó·½
¦@¦³ 3 ºØ¤£¦PÃC¦âªº¤ô´¹, ¤À§O¬O[0;35mµµ¦â[0m¡B[1;37m¥Õ¦â[0m¡B[1;31m¬õ¦â[0mªº¤ô´¹(crystal)¡C
*/
	set("short", "[1;36m·É¤ô¤ô¬}[0m");
	set("long", @LONG

LONG	);
	set("exits", ([
  "out" : __DIR__"map_1_2.c",
]));
	for(int x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 1 )
		{
			set("item_desc/crystal", "¬W¤l¤W¦³µÛ´XºØ¤ô´¹¦³" + query_crystal() + "¡A°²¦p§A·Q±N¤§®³°_, ¥i¥H¸ÕµÛ¥Î(get)¡C\n");
			break;
		}
	setup();
}

string query_long(int raw)
{
	int q = 0;
	string out = @LONG

³o¸Ì´N¬O·É¤ô¤ô¬}¤F, ³o´N¬O¥þ·É¿¤¸Ì©Ò¨ÑÀ³ªº¤ô·½ªº·½ÀY, ¥Rº¡µÛ·Ã
®ð, ´X¥GªÅ®ð¤¤©Ò¦sªº, ³£ºÉ¬O¤ô®ð, ³oÃä¦³¤T­Ó¥Û¬W, ¥Û¬W¤W, ¦³µÛ
LONG;

	if( query_crystal() == "" )
		out += "¤@­Ó­Ó¦³®à¤l¯ë¤j¤pªº¬}¡A¤W­±³£¬OªÅªº¡AªÅ¿º¿ºªº¤@¤ù¡C\n\n";
	else out += query_crystal() + "\n\n";
	return out;
}

string query_crystal()
{
	int q;
	string out = "";
	if( crystal[0] == 1 )
		{ out += "[0;35mµµ¦â[0mªº¤ô´¹"; q = 1; }
	if( crystal[1] == 1 )
		{ out += ((q==1) ? "¡B" : "") + "[1;37m¥Õ¦â[0mªº¤ô´¹"; q = 2; }
	if( crystal[2] == 1 )
		{ out += ((q==2 || q==1) ? "¡B" : "") + "[1;31m¬õ¦â[0mªº¤ô´¹"; q=3; }
		// §PÂ_¬O§_ q == 1 ©Î 2 ¦A¥[¤W«á­±¸É¥R, ¥[ q=3 ¬O©È«e­±¨S¦³ query ¨ì.
	return out;
}

void init()
{
	add_action("do_get", "get");
	add_action("do_lay", "lay");
	add_action("do_cast", "cast");
}

int do_get(string arg)
{
	object me = this_player();
	string temp;
	int flag;

	if( !arg || sscanf(arg, "%s crystal", temp) != 1 )
	{
		write("¦pªG§A·Q­n®³¨ú³o¸Ìªº¤ô´¹, ½Ð¥Î get <ÃC¦â> crystal¡C\n");
		return 0;
	}

	flag = member_array(temp, crystal_kind);
	if( flag == -1 || crystal[flag] == 0 )
		return notify_fail("³o¸Ì¨S¦³"+to_chinese(temp)+"³oºØÃC¦âªº¤ô´¹¡I("+flag+")\n");

	if( me->is_busy() )
		return notify_fail("§A¤W¤@­Ó°Ê§@ÁÙ¨S¦³§¹¦¨¡T\n");

	if( !me->query_temp("invis") )
	{
		message_vision("$N¸ÕµÛ±N" + crystal_color_kind[flag] + "ªº¤ô´¹®³°_¡K\n", me);
		message_vision("  ¤£®Æ, ¦]¬°³o¨Ç¤ô´¹¹L©óÃe¤j, ¬ðµM$N¤@­Ó¤£¤p¤ß, ±q$Nªº¤â¤¤·Æ¸¨, ±¼¨ì¤ô¸Ì, ³Q¤ôµ¹¨R¨«¤F¡K\n", me);
	}
	else
	{
		write("§A¸ÕµÛ±N" + crystal_color_kind[flag] + "ªº¤ô´¹®³°_¡K\n");
		write("  ¤£®Æ, ¦]¬°³o¨Ç¤ô´¹¹L©óÃe¤j, ¬ðµM$N¤@­Ó¤£¤p¤ß, ±q$Nªº¤â¤¤·Æ¸¨, ±¼¨ì¤ô¸Ì, ³Q¤ôµ¹¨R¨«¤F¡K\n");
		message_vision(HIC"¬ðµM¶¡, " + crystal_color_kind[flag] + "ªº¤ô´¹±¼¤J¤F¤ô¸Ì¡K¡I\n"NOR, me);
	}

	call_out("random_moving", 10, flag);
	crystal[flag] = 0; // ¨Ï¤ô´¹¤£¦s¦b = 0;
	control(1);
	return 1;
}

int do_lay(string arg)
{
	object me = this_player(), ob;
	string temp;
	int x, flag;

	if( !arg || sscanf(arg, "%s on stone", temp) != 1 ) return notify_fail("§A·Q­n©ñ¤°»òªF¦è¡H(lay <¤ô´¹> on stone\n");
	if( !(ob=present(temp, me)) || living(ob) ) ob = present(temp, environment(me));
	if( !ob || living(ob) ) return notify_fail("³o¸Ì¨S¦³³o¼ËªF¦è¡C\n");

	for(x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 1 ) flag = 1;

	if( flag == 1 ) return notify_fail("¦³¤@ªÑ¤O¶q§í¨îµÛ§A©ñ³oªF¦è¤W¥h¡A¥i¯à¬O¤W­±ÁÙ¦³¨S°ÊªºªF¦è¡I\n");
	if( ob->id("crystal") )
	{
		switch(ob->query("id"))
		{
			case "purple crystal":
				crystal[0] = 2;
				break;
			case "white crystal":
				crystal[1] = 2;
				break;
			case "red crystal":
				crystal[2] = 2;
				break;
		}
		show_message(me, ob);
		destruct(ob);
	}
	else return notify_fail("§AµoÄ±±N" + ob->name(1) + "©ñ¤W¥h¨S¦³¤°»ò¨Æµo¥Í¡A©ó¬O¤S®³¤F¤U¨Ó...\n");
	return 1;
}

int do_cast(string arg)
{
	object me = this_player();
	int x, flag;

	if( me->is_ghost()) return notify_fail(" §A²{¦bÁÙ¬O°­»î§a\n");
	if( me->is_busy() || me->is_block() )
		return notify_fail("( §A¤W¤@­Ó°Ê§@ÁÙ¨S¦³§¹¦¨¡M¤£¯à©À©G¤å¡C)\n");
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("§A²{¦b¥¿¦b¦£¨SªÅ¬Iªk¡C\n");
	if( environment(me)->query("no_magic") || environment(me)->query("no_cast") )
		return notify_fail("³o¸Ì¤£­ã©À©G¤å¡C\n");
	if( !arg || arg != "god-fire on the crystals" ) return 0;

	if( !me->query_spell("god-fire") )
		return notify_fail("§AÁÙ¨S¾Ç¹L¦¹©G¤å¡C(god-fire)\n");

	for(x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 0 || crystal[x] == 1 ) flag = 1;

	if( (int)me->query("mp") < 25 ) 
		return notify_fail("§Aªºªk¤O¤£°÷¡C\n");

	if( flag == 1 ) return notify_fail("¿ù»~¡I¥i¯à¬O¦]¬°¥Û¬W¤WÁÙ¦³ªÅ¦ì¨S©ñ©ÎªÌ¬O­ì¥»ªº¤ô´¹¥¼¨ú¤U¡I\n");

	me->start_busy(2); //¬Iªk°Ê§@®É¶¡
	me->receive_damage("mp", 20); //¬Iªk¦©MP

	message_vision("$NÂù¤â¦X¤Q¡A³ä³ä¦Û»y¹D¡G"HIW"¡u"HIG"¤Ñ¦a¦X¼w¡A¤é¤ë¦X©ú¡A¥|®É¦X§Ç¡A°­¯«¦X¤õ¥H·À¼Ä¡C"HIW"¡v\n"NOR,me);

	message_vision(RED"\n\n ¥u¨£¤@¹D¹D"HIR"¤õ²y"NOR RED"­¸¦V¤ô´¹¦Ó¥h¡K¡K¡@µ²ªG¤ô´¹¶}©l¿Ä¤Æ¡A¤ô·½¤S«ì´_¤F...\n"NOR, me);

	for(x=0;x<sizeof(crystal);x++)
		crystal[x] = 1;

	control(2);
	return 1;
}

void show_message(object me, object ob)
{
	int i, t = 0;
	string msg, msg1;

	if( !me || !ob ) return;
	if( crystal[0] == 0 )
		{ msg1 += crystal_color_kind[0]; t=1; }
	if( crystal[1] == 0 )
		{ msg1 += ((t==1) ? "¡B" : "") + crystal_color_kind[1]; t=2; }
	if( crystal[2] == 0 )
		{ msg1 += ((t==1 || t==2) ? "¡B" : "") + crystal_color_kind[2]; t=3; }
	if( msg1 ) msg = "¡AÁÙ®t" + msg1 + "´X­Ó¤ô´¹";
	if( t == 0 ) msg = "¡A¥u®t¬I¥X"HIR"¯«ªZ¯u¤õ"NOR"¨Ó¿Ä¤ô´¹(cast god-fire on the crystals)";
	message_vision("$N±N$n©ñ¦b¥Û¬W¤W" + msg + "¡C\n", me, ob);
	return;
}

void control(int flag)
{
	object now_room = load_object(NOW_ROOM);
	int x, j = 0, uj = 0;
	for(x=0;x<sizeof(crystal);x++)
	{
		if( crystal[x] == 0 ) j++;
		if( crystal[x] == 1 ) uj++;
	}
	if( j == 3 && flag == 1)
	{
		message("world:world1:vision", HIY"¬ðµM¡A¤ô·½º¥º¥´î¤Ö¡A´ËªL¤¤ªº¤@¹D¤ô·½¬ðµMÂ_¤F¡K¡I\n"NOR, users());
		// ±µ¤U¨Óªº¬O²{¥NªºÅÜ¤Æ
		tell_room(now_room, HIY"¬ðµM¤@°}§á¦±¡A§AÄ±±o¤@°}¤Ñ±Û¦aÂà¡A¦ý¬O¦^¹L¯«¤§«á¨Ã¨S¦³µo²{¤°»ò¡A¬O¤£¬OÀY¸£©ü¤F¡H\n"NOR, ({ }));
		now_room->set_water(0);
		return;
	}
	if( uj = 3 && flag == 2)
	{
		message("world:world1:vision", HIY"¤sÀYªº¤ô·½¤Sº¥º¥ªº«ì´_¤F¡K\n"NOR, users());
		// now's change
		tell_room(now_room, HIR"¬ðµM¤@°}§á¦±¡A§AÄ±±o¤@°}¤Ñ±Û¦aÂà¡A¦ý¬O¦^¹L¯«¤§«á¨Ã¨S¦³µo²{¤°»ò¡A¬O¤£¬OÀY¸£©ü¤F¡H\n"NOR, ({ }));
		now_room->set_water(1);
		return;
	}
}

void random_moving(int flag)
{
	object crystal_move = new(crystal_file[flag]), room;
	if( !crystal_move )
	{
		CHANNEL_D->do_channel(this_object(), "sys", "error: /open/world1/cominging/area/wh_1.c error ¶Ç¤J­È");
		return;
	}
	room = load_object(locate[random(sizeof(locate))]);
	crystal_move->move(room);
	tell_room(room, HIG"±q¤W´å¬ðµM¤@­ÓªF¦è¬y¤F¹L¨Ó¡K\n"NOR, ({ }));
	return;
}

int *query_x()
{
	return crystal;
}
