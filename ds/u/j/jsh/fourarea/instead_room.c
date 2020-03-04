#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "Åñ¤§©Ð");
        set("long", @LONG
test
LONG
        );

        set("item_desc",([
        "»ÉÃè":"¤@­±¥j¦Ñªº»ÉÃè¡A¤W­±ÁÙÂÐ»\µÛÁ¡Á¡ªº¶À¤g¡A¬Ý¨Ó¦~¥N¤[»·¡C\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "home" : "/u/m/moonhide/workroom",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_instead","instead");
}

int do_instead(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="tear to mirror") return notify_fail("§A­n·Ó¤°»ò?\n");
        if(!objectp(tear=present("ice of tear",me) ) )
                return notify_fail("§A­n®³¤°»ò·ÓÃè¤l ? \n");
        message_vision(HIC"$N±N¤â¤¤ªº¦B¤§²\«ü\¦V»ÉÃè¡A¤@°}ÂÅ¥ú®g¥X¡A¥´¦V»ÉÃè¡C\n",me);
     message_vision(HIY"ÂÅ¥ú°ª©ß¨ì¤Ñ»Ú¡A³ò¦¨¤@¥b¤ë«¬¡A³t¤U®M¦í$NÅ . .¡I¡I\n" NOR,me);
        me->start_busy(5);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"§A¯¸¦b¤ë¤§¯«·µ«e¡C\n");
        me->move(__DIR__"¥¼§¹.c");
     tell_room(environment(me),me->query("name")+"©¿µM¯¸¦b§Aªº­±«e¡C\n",me);
        return;
}

