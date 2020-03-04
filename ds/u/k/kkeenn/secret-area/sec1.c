#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "¦a¤U«°¤jªù");
        set("long", @LONG
¤@±ø±ø¥R¥¸ªº·¥¬°°ª¾z¤Oªº¹q¤l¬W¦b²´«e½Ý¥ßªº¡A¬Ý¨Ó¬O¤£¥i¯à±j¦æ
³q¹L¤F¡A¦b¹q¤l¬Wªº¤W¤è±¾µÛ¤@±i¹q¤l§G§i( note )¡A¦b¥¦ªº®ÇÃä¦³µÛ¤@
¶ô´Ý¯Êªº¥j¦ÑªºÅKªO¡A¤W­±³Q¤H¥Î°ªÀ£¤À¤l±Æ¥X[ ¦a¤UÄq§|ªþÄÝ«°¥« ]´X
­Ó¤j¦r....
LONG
        );
        set("item_desc",([
     "note": "[31m½Ð¤£­n»W·N¯}Ãa¥¦, §Ú­Ì¥u¬O©È¶À¨F¤J«I, ³X«È½Ð¦Û¦æ¶}ªù[0m

",
        ]));
        set("exits", ([ /* sizeof() == 4 */ 
 "north":__DIR__"sec2.c",
]) );
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("no_clean_up", 0);

        setup();
 create_door("north","¹qºÏªù","south",DOOR_OPENED,"nokey");
}


