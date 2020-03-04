// Room: /u/k/king/area/r61.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m°­¤ý·µ");
	set("long", @LONG
³o¸Ì´N¬O¯³¬Ó³®ªº³Ì«á¤@ºÝ¤F¡A¥|©P¤Ï¦Ó¤@¤Ï±`ºAªº¹çÀR¡A¦b¼s¤jªº
ªÅ¶¡¸Ì¥u©ñ¤F¤@¨ã´Ã§÷¡A´Ã§÷ªº¥|©P¤]³£¥Î¬õ¦âºø½uÄñ¦í¡A¤£ª¾¹D¦³¤°»ò
¥\¥Î¡C¤ÑªáªO¤W§Gº¡¤F»jµïºô¨Ï¤Ñ¯«µLªkÅ¥¨ì§Aªº¦^À³¡A§AÁÙ¬O¦Û¨D¦hºÖ
§a¡C
LONG
	);
	set("no_recall", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "ª÷´Ã" : "³o¬O¤@¨ã¶Àª÷»s¦¨ªº´Ã¤ì¡A§A¦ü¥G¥i¥H±È¶}(uncover)¥¦¡C
",
]));
	set("world", "undefine");
	set("light", 0);
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_uncover","uncover");
}
int do_uncover(string arg)
{
        object me;
        object zombie;
            object zombie2;
        me=this_player();
        if(query_temp("kkzombie")) return notify_fail("¤°»ò¡H\n");
        if(arg != "ª÷´Ã" )
        {
          notify_fail("§A­n±È¶}¤°»ò¡H\n");
          return 0;
        }
        else {
          message_vision(
          "$N±Nª÷´Ã¤p¤ßªº±È¶}¡A¤@°}¶Â®ð±q´Ã¤ì¥|©P¤£Â_ªº´é¥X¨Ó¡A¥u¨£¤@¨ã
¨­¬ïÀs³Tªº¤H½w½wª¦°_¡C\n\n"
         "¯³©l¬Ó¹ï¤Ñ¨g¼S¹D¡G¡u§Úªº¥@¬É¨ÓÁ{¤F¡v¡C\n"
         "¤@°}ª÷¥ú«á¡A¤@­¶®Ñ¥X²{¦b§A­±«e¥B¹D¡G¡u$N³o­Ó¥@¬É´N¥æµ¹§A¤F¡v¡A¸Ü²¦¡A¤@­¶®Ñ´N®ø¥¢¤F¡C\n"
         ,me);
        zombie=new(__DIR__"npc/chin3.c");
        zombie->move(__DIR__"r61");
        set("exits", ([
          "up" : __DIR__"god",
        ]));
        set_temp("kkzombie",1);
        set("item_desc", ([
        "ª÷´Ã" : "³o´Ã¤ì¦ü¥G¤w¸g³Q¤H¥´¶}¤F¡C\n",
        ]) );
set("long", @LONG
§A¬Ý¬Ý³o°Æª÷´Ã­ì¨Ó¬OÁáª÷ªº¡A§A®ð©Áªº©¹ª÷´Ã¤@½ð¡A¤£¤p¤ß§á¨ì¦Û¤vªº¸}¡A
ÁÙµh¤F¥b¤Ñ¡A³Ì«áÁÙ¬O¦Û¤vºNºN»ó¤lÂàÀY¨«¤F¡C
LONG
);
        return 1;
   }
}
