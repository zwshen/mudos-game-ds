#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"¤p³â¥z¤u§@«Ç"NOR);

	set("long", @LONG
³o¬O¤p³â¥zªº¤u§@«Ç¡A§A¥i¬Ý¨£©P³ò³£¶Kº¡¤F¡u²`¥Ð®¥¤l¡vªºPoster¡C
©M¤@±i¤@±iªº¼g¯u·Ó¤ù¡C¦V¥ª¬Ý¥i¥H¬Ý¨£¤@­ÓVCDÂd©M®ÑÂd¡A¥þ³¡³£¬O
¡u²`¥Ð®¥¤l¡v©Òºt¹Lªº¼@¶°©M¼g¯u¡A¦³¡y¤W«Ò¡A½Ðµ¹§Ú¦h¤@ÂI®É¶¡¡I¡z
LONG

	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"green.c",
  "naboo" : __DIR__"area/naboo/middle.c",	
  "enter" : __DIR__"area/inn",
  "star" : __DIR__"starwars",
 "war" : __DIR__"a10.c",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"kelly.c" : 1,
   __DIR__"kyoko.c" : 1,
__DIR__"area/naboo/npc/bar.c" :10,
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);


	setup();
	call_other("/obj/board/mulder_b.c", "???");
}
void init()
{
	call_out("leave_message",3,this_player());
	call_out("entercheck",2,this_player());
}

void entercheck(object ob)
{
 if(userp(ob))
 {
  if(wiz_level(ob) < wiz_level("(immortal)"))
  {
   message_vision(HIR"²`¥Ð®¥¤l»¡¡G"+ob->name()+" §A«ç·|¶]¨Ó³o¡A§A·QÂI§r(-_-)¡I\n"NOR, ob);
   ob-> die();
  } else {
   message_vision(HIY"\n²`¥Ð®¥¤l»¡: §A¦n¡I¡I "+ob->name()+"¤j¤j¡I¤µ¤é«ç³o»ò¦­§r¡I¡I\n"NOR, ob);
  }
 }
 return;
}

void leave_message(object me)
{
	object mulder,ob2;
	if( mulder=find_player("mulder"))
	{
		if(me->query("id")!="mulder")
		{
			ob2=present("mulder",this_object());
			if( ob2 ) return;
			add("guest",me->query("id")+" - ");
			tell_object(mulder ,"[1;37m¦³³X«È¨ÓÅo!("+me->query("name")+")[m\n");
			tell_object(me,"²`¥Ð®¥¤l(Kyoko)§i¶D§A:§A¦n§r¡I¡I¤p³â¥zµf¨ÓÅo¡I\n");
		}
		else
		{
			if(query("guest"))
			{
				tell_object(me,"[1;37m¤µ¤Ñªº³X«È¦³:"+query("guest")+"[m\n");
				delete("guest");
			}
			else
			{
				tell_object(me,"[1;37m¤µ¤ÑÁÙ¨S¦³³X«È¨Ó¹L[m\n");
			}
		}
	}
	else
	{
		add("guest",me->query("id")+" - ");
		tell_object(me,"[1;37m²`¥Ð®¥¤l(Kyoko)§i¶D§A: MulderÁÙ¨S¤W½u®@¡A§AÀH·N³}³}§a¡I[m\n");
	}
 

}