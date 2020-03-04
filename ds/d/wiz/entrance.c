// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;
nosave string *victims = ({});
void create()
{
	set("short", "§Å®v·|«È«Ç");
	set("long",@LONG
³o¸Ì¬O§Å®v©Mª±®a²á¤Ñªº¦a¤è¡M¦pªG§A¦³¤°»ò·N¨£­nÅý§Å®v­Ìª¾¹D¡M¦b³o¸Ì
¯d¨¥¬O³Ì§Öªº³~®|¡M¤£¹L¦pªG¬O¹ï©ó¹CÀ¸¤¤ªº°ÝÃD¡M½Ð±z¥ý½T©w§Ú­Ì´£¨Ñªº»¡©ú
¤å¥ó¸Ì¨S¦³»¡©ú¡M¦A´£¥XºÃ°Ý¡M§Å®vªº¥D­nÂ¾³d¨Ã¤£¬O±Ðª±®a¦p¦óª±¡C
    [1;33m¬°¤F§ùµ´¾÷¾¹¤H¡M±z¥i¥H¦b³o¸ÌÀËÁ|(accuse)¬Y­Óª±®a[0m¡M¸Ó¦Wª±®a·|³Q§ì¥h
°µ¤@¨Ç¤p¤pªº´úÅç¡M½Ð¤Å§Q¥Î¨ÓÄÌÂZ§O¤H¡C
LONG
);
	set("exits", ([
		"west" : "/d/wiz/hall1",
        "east" : "/open/world2/anfernee/start/bug",
]) );
	set("no_fight", 1);
set("no_recall",1);
	set("no_magic", 1);
   set("light",1);

	setup();
	call_other( "/obj/board/query_b", "???" );
}

int valid_leave(object me, string dir)
{
	if( dir=="west" && !wizardp(me) )
		return notify_fail("¨º¸Ì¥u¦³§Å®v¤~¯à¶i¥h¡C\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_accuse", "accuse");
	add_action("do_look", "look");
}

int do_accuse(string arg)
{
	object ob,env;
         string env_file;

/*      return notify_fail("©êºp, ¥Ø«eª±®a¥ÆÀÝ¨Ï¥Î accuse ¤ÓÄY­«, ¤©¦¹°±¥Î. by linjack\n");
        if( (int)this_player()->query("level") < 25 )
                return notify_fail("§Aµ¥¯Å¤Ó§C¤F¡M¨S¦³ÀËÁ|§O¤HªºÅv¤O¡C\n");*/
          if( !wizardp(this_player()) )
                return notify_fail("©êºp, ¥Ø«eª±®a¥ÆÀÝ¨Ï¥Î accuse ¤ÓÄY­«, ¤©¦¹°±¥Î. by linjack\n");

	if( !arg ) return notify_fail("§A­nÀËÁ|½Ö¡S\n");
	if( ob = find_player(arg) )
	{
		if( ob==this_player() )
			return notify_fail("§A­nÀËÁ|¦Û¤v¡S\n");
		if( ob->is_ghost() )
			return notify_fail( ob->name(1) + "¤w¸g¦º¤F¡M©ñ¥L¤@°¨§a¡C\n");
		if( ob->query_temp("killer") )
			return notify_fail( ob->name(1) + "¥¿¦b°k©R¼È®É¤£¯àÀËÁ|¡C\n");
		if( member_array(geteuid(ob),victims) != -1)
			return notify_fail( ob->name(1) + "³Ìªñ¤w¸g³QÀËÁ|¹L¤F¼È®É¤£¯àÀËÁ|¡C\n");
        if(ob->is_inactive()) return notify_fail( ob->name(1) + "¥Ø«e¥¿³B©ó¶¢¸m¼Ò¦¡¤¤¡C\n");
		if(!env=environment(ob))
			return notify_fail("§A­nÀËÁ|½Ö¡S\n");
		env_file=base_name(env);
		if(env_file=="/d/wiz/courthouse")
			return notify_fail(ob->name(1) + "¤w¸g¦b±µ¨ü´úÅç¤F¡C\n");
		if( wizardp(ob) )
			return notify_fail("§A¤£¯àÀËÁ|§Å®v¡C\n");
                tell_object(ob, HIW + this_player()->name(1) + " (" + this_player()->query("id") + ") ÀËÁ|§A¬O­Ó¾÷¾¹¤H¡M½Ð§A±µ¨ü¤@­Ó¤p¤pªº´úÅç¡C\n" NOR);
        // ob->set("accuse_position",env_file);
    switch(ob->money_type())
    {
/*
      case 1 : ob->set("accuse_position","/open/world1/tmr/area/hotel");
               break;
      case 2 : ob->set("accuse_position","/open/world2/lichi_town_2/map_5_26");
               break;
      case 3 : ob->set("accuse_position","/open/world3/tmr/basic/hotel");
               break;
*/
      default : ob->set("accuse_position","/open/world2/anfernee/start/hall");
                break;
    }
		victims += ({geteuid(ob)});
		ob->save();
		ROBOT_CHECK->test_me(ob);
		if(!wizardp(this_player()))
		{
			write("Ok. ¤w¸g±N§AÀËÁ|ªº¹ï¶H°e¥h°µ´úÅç¡C\n");
			write("¬°¤FÁ×§K¦³¤H¥Î¾÷¾¹¤H¶ÃÀËÁ|ÄÌÂZ§O¤H¡M½Ð§A¤]±µ¨ü¬Û¦Pªº´úÅç¡C\n");
            // this_player()->set("accuse_position",base_name(this_object()));
     this_player()->set("accuse_position","/open/world2/anfernee/start/hall");
			this_player()->save();
			ROBOT_CHECK->test_me(this_player());
		}
		log_file("robot_accuse",
			sprintf("%s accused %s on %s.\n", this_player()->query("id"), ob->query("id"), ctime(time())));
		return 1;
	}
	return notify_fail("¥Ø«e½u¤W¨Ã¨S¦³³o¦ìª±®a¡C\n");
}

void reset()
{
  add("reborn",1);
  if(query("reborn") < 4) return;
  delete("reborn");
	::reset();
	victims = ({});
}

int do_look(string arg)
{
	if( arg == "west" )
{
	return 1;
}
}
// add by alickyuen@ds
