#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "¤p²î¤W");
        set("long", @LONG
³o¬O¤@¿´¥Î¤ì¤ùÂH±µ¦Ó¦¨ªº¤p²î¡A¦b²îªº«e­±¡A¦³¨â±øÃ·¤l¡AÛ
¦V«e¤@±´¡A­ì¨Ó¸jµÛ¤@±ø®ü³b¡C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "®ü³b" : "¤@°¦¯Â¥Õ¦âªº®ü³b, ¼Ë¤l¤Q¤À¥i·R, ¦ü¥G¬O¥Î¨Ó©ì²î¥Îªº(slap)¡C\n",
]));
        set("exits", ([ /* sizeof() == 2 */
          "out" : __DIR__"startroom",
       ]));
        set("light",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("dolphin","slap");
}


int dolphin(string arg)
{
        int t;
        object me,room,*inv;
        me=this_player();
        if(arg != "®ü³b") return 0;
        if(!this_object()->query_temp("moving")) 
        {
                inv = all_inventory(this_object());
                message_vision( HIB "$N©¹®ü³bªº«á­I¥´¤F¤U¥h¡A®ü³bºCºCÂ\\°Ê§À¤Ú¡A½w½wªº§â²î©ì¥Xº®´ä.....\n\n" NOR ,me);
                me->start_busy(4);
                call_out("domessage",3,3);
                this_object()->set_temp("moving",1);
                this_object()->delete("exits");
                room = load_object(__DIR__"startroom");
                room->delete("exits/enter");
                room->set("long",@ROOM_LONG
³o¸Ì¬Oº®´äªº®ü©¤¡AÀôÂ¶µÛ¥|®ü¡A¤@±æµL»Ú¡A¥uÁ@¨£«n¤è¦³¤@¶ô¤p®q¡C
ROOM_LONG
);
                tell_room(room,"§A¬Ý¨ì¤p²î½w½wªºÂ÷¶}¤Fº®´ä....\n");
                return 1;
        }else
        {
                tell_object(me,"¤p²î¤w¸gÂ÷¶}¨ì¬Ý¤£¨ì»·³B¤F¡C\n");
                return 1;
        }

}

int domessage(int b)
{
  object *inv,room;
  int i;
  if(b==3) tell_room(this_object(),HIC "®ü³bºCºCªº´å¡A²î¤]ºCºCªº©¹«n¤è²¾°Ê¤F...\n\n" NOR);
   else if(b==2) tell_room(this_object(), HIC "«eºÝªº®ü¤ô¡A¦³¦p³Q¤M¹º¶}¡A§â²Ó²Óªº¤ô®ð¼Q¤F¤W²î . . .\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIG "®ü³bº¥º¥ªººC¤F¤U¨Ó¡A­ì¨Ó¬O¨ì©¤¤F¡A¥u¨£¤@¤ù­Z±Kªº´ËªL . . .\n\n" NOR );
  else  {
                inv = all_inventory(this_object());
                tell_room(this_object(),HIW "§A¤U¤F²î¨«¤W¨FÅy, ¨«¶i¤FÅs¦±¤£ª½ªº¸ô..\n\n" NOR );
                this_object()->delete_temp("moving");
                room = load_object(__DIR__"room1");
                tell_room(room,"§A¬Ý¨ì¤@°¦®ü³b©ìµÛ¤p²î´å¦^´ä¤F..\n");
                for(i=0;i<sizeof(inv);i++)
                {
                        if(living(inv[i])) inv[i]->move(__DIR__"room1");
                }
                tell_room(room,"®ü³bÂàÀY´N´å.....\n");
                this_object()->set("exits", ([
                        "out" : __DIR__"startroom",
                ]));
                room = load_object(__DIR__"nb4");
                tell_room(room,"§A¬Ý¨ì¤@°¦®ü³b©ìµÛ¤p²î´å¦^´ä¤F..\n");
                room->set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"/open/world1/wu_sha_town/seacoun42",
  "enter" : __DIR__"boat",
]));
                room->set("long",@ROOM_LONG2
³o¸Ì¬Oº®´äªº®ü©¤¡AÀôÂ¶µÛ¥|®ü¡A¤@±æµL»Ú¡A¥uÁ@¨£«n¤è¦³¤@¶ô¤p®q¡C¦b§A«nÃä°±µÛ¤@¿´¤p²î¡C
ROOM_LONG2
);
                return 1;
                
        }
        b--;
        call_out("domessage",3,b);
}

