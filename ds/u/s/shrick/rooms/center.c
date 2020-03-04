// Center.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIY"
 ùúùùùùùùùùùû û û      
 ¢x" HIG"¤¤¥¡¼s³õ" HIY"¢x 
 ùüùùùùùùùùùı
"NOR);
         set("long",@LONG
  ³o¸Ì¬OµSÃ¹§øªº¤¤¥¡¼s³õ¡A¤¤¶¡¾ğ¥ßµÛ¥j®É®ü¸é¤ı
¢w¡§­ôº¸¡EÃ¹³Ç¡¨ªº»É¹³(statue)¡A©¹¨Óªº®ü¸é²ö¤£
¹ï¥L·q¬È¤T¤À¡C³o¸ÌÁÙ©ñµÛ¤@­Ó§G§iÄæ(board)¡C
LONG
        );
        set("item_desc", ([
             "statue": "³o¬O¥j®É®ü¸é¤ı¢w¡§­ôº¸¡EÃ¹³Ç¡¨ªº»É¹³¡C\n",
              "board" : "³o¬Oboard£²¤£¹L¬İ¼Ë¤l¤£¯à¼gªFªFªºboard¡C\n",

          ]) );
        set("exits", ([/*sizeof=4*/
                "up":"/u/s/shrick/workroom.c" ,
                "east"    : __DIR__"memo1",
                "north"    : __DIR__"kain_n1",
                "south"    : __DIR__"crossd",
 ]) );

        set("outdoors","workroom.c");
}

