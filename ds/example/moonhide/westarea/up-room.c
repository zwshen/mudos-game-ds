#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "¤ì¬W«e");
        set("long", @LONG
³o¸Ì¬O¤@¤ù¼e¼sªº¯ó­ì , ¤£®ÉÁÙ¦³¤û¥sÁn , ¤]¦³²M¯Üªº³¾»ï
Án , ¹³¬O¤H¶¡¤Ñ°ó¦üªº , ¦ý¬O . .  ©Ò¦³ªº°Êª«³£¤£´±¾aªñ¯ó­ì
¥¿¤¤¶¡ªº¨º®Ú[0;7;33m¤[7mì[7m¬[7mW[0m , ºÃ¦³©Ç²§ . . .¡C
LONG
        );

        set("item_desc",([
    "¤ì¬W":"¤@±ø§e¤»¤Q«×¶É±×ªº¤ìÀY¬W¤l¡A¤W­±ÁÙ¦³¤@¹ï¤p¤pªº¤Ä¤l¡A¦ü¥G¦³¤°»ò§@¥Î¡C\n",
        "¤Ä¤l":"¤@¹ï¤p¤pªº¤Ä¤l¡A¤W­±ÁÙ¦³¿iÀ¿¹Lªº²ª¸ñ¡C\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "north" : "/open/world1/wilfred/meadow/room3",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_hold","hold");
}

int do_hold(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="ring on ¤Ä¤l") return 0;
        if(!objectp(ring=present("willow ring",me) ) )
                return notify_fail("§A¨S¦³ªF¥i¥H¸j¦í¤Ä¤l°Ú ? \n");
        message_vision(HIW"$N±N¬h§Ù¥Î¤O¤@§è¡A±N¨ä¨c¨cªº®M¦í¨âÃäªº¤Ä¤l¡A¨ÃÃ­Ã­ªº§ìºò¡C\n",me);
     message_vision(HIW "¬h§Ù¹³¬OµÛ¤FÅ]¤@¼Ë¡A±N$N¼u¤WµL½a»·ªº¤ÑªÅ . .¡I¡I\n" NOR,me);
        me->start_busy(2);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"§A¤j¥s¤@ÁnªººL¦b¶³¼h¤W­±¡C\n");
        me->move(__DIR__"room");
     tell_room(environment(me),me->query("name")+"ºL¦b³n³nªº¶³¼h¤W­±¡C\n",me);
        return;
}

