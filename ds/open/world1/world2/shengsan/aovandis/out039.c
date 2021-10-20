// ¶ø¤Z­}´µ­¥°Ï
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "¾ðªL");
	set("long", @LONG
¾ðªL¶¡ªº¤p¥Íª«±`¦b³oª±­A¡A¹x¥Öªº¤pªQ¹«¦³®É·|§â¨e­Ì¦b¥~­±°½¨Ó
ªºªF¦èÂÃ¦b³o¸Ì­±¡C§A¬Ý¨ì³o¸Ì¦³®þ®þªº¬y¤ô±q¥Û¾ÀÁ_¸Ì¬y¥X¨Ó¡A¤]³\§A
¥i¥HÀ|À|(taste)¨ä¤¤ªººç¤¤´þ¨ý¡C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out045",
            ]));

	set("outdoors","land");	// ¥­­ì
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
}

void init()
{
	add_action("do_taste","taste");
}

int do_taste(string arg)
{
	object me;
	me=this_player();
 
  if(!arg) return notify_fail("§A·QÀ|¤°»ò?\n");
  if(arg=="¬y¤ô"||arg=="¤ô"||arg=="water")
  {
 	if(me->is_ghost()) return notify_fail("¹[1m¤Ñ¤W¶Ç¨Ó±y±yªºÁn­µ: ¹[33m§Ú¥u¯àÀ°§U¦³¥Í©Rªº¤H¡C¹[0m\n");
	message_vision("$NÅs¤U¸y³Ü¤F´X¤f¤ÑµM¬u¤ô¡C\n", me);
	if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
	{
 	 me->reincarnate();
	 tell_object(me,"§Aªº¨­Åéª¬ªp§¹¥þ¦^´_¤F¡C\n");
	 return 1;
	} else
	{
		return notify_fail("§AÄ±±o¤Q¤À²M²D¡C\n");
	}
 }
 notify_fail("§A·QÀ|¤°»ò?\n");
 return 0;
}
