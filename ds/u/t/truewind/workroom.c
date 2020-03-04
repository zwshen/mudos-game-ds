// Room: /u/t/truewind/workroom.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "[1;37m«ä¹L±V[0m");
	set("long", @LONG
¦¹³B¬OµØ¤s¤W¤@³B²×¦~ÄÆ³·ªºÂ_±V¡A¨ú¦W«ä¹L±V¤D¦]¤H¸ñ¨u¦Ü¡A
´H§N»÷ÀR¡A±M¥Î¨Ó¨Ñ¤H¤Ï¬Ù«ä¹L¤§¥Î¡C¦ÓÄ²¥Ø©Ò¤ÎºÉ¬O¥Õ½J½Jªº´º¶H
¡A©P³ò³Q¤s¾ÀÀô©ê¡A¥u¦³¤@±ø¤p¸ô¥i³q¡C°¸¦Ó·|¦³³¥¥Í°Êª«¸g¹L¡C¦b
ªþªñ¦³¤@³B¤p¤s¬}(cave)¡C
LONG
	);
	set("objects", ([ 
	__DIR__"npc/fox":1 ,
	__DIR__"npc/Tsiping":1 ,
]));
	set("item_desc", ([
        "cave" : "¤@­Ó¤s¬}¡A¥i¥H¸ÕµÛ¶i¤J(enter)¬Ý¬Ý¡C\n",   
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"cave",
  "south" : __DIR__"workroom1",
  "west" : "/u/t/truewind/newarea/1/ra",
  
]));
	call_other("/obj/board/truewind_b.c", "???");
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 1);	    
	setup();
}
int room_effect(object me)
{
        switch(random(6))
        {
                
         case 3:        message_vision("¡ã©I¡ã©I¡ã!!¡@$N³Q¤@°}°}ªº´H­·¨íªºª½¥´Å¸¡C\n",me);
                        me->receive_damage("hp",random(10)+1);
                        return 1;
         case 2:
         case 1:        tell_object(me,"´X¤ù"HIW" ¡¯ ¡¯³·ªá ¡¯ ¡¯"NOR"ÄÆ¸¨¤U¨Ó¡ã¡C\n");
                        return 1;
         case 0:
         default:       return 1;
        }
}
