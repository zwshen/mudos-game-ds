
inherit ROOM;

void create()
{
	set("short", "«eÆU");
	set("long", @LONG
¦³³\¦hªº¤Mºj¼C¤b±¾¦b§A«n­±ªºÀÉÀð¤§¤W¡A¨C§â§L¾¹¬Ý°_¨Ó³£¬Û·íªº
¾W§Q¥B¨ã±þ¶Ë¤O¡C¦Ó¦b§A¥_­±ªºÀð¤W±¾¤F¤@´T¤j±¾¹Ï(picture)¡C
LONG
	);

	set("item_desc", (["picture":@NOTE
[1;32m
³o´T±¾¹Ï¥X¦Û¦W®a¤§¤â¡A¤W­±ªº°¨¤Ç¦b¸U¤Vªº¯ó­ì°ª¦a¤W©b¹£¡A®ð¶Õ
«D¤Z¡Aµ§¸ôÃtÅx¡C
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room24",
	    "west" : __DIR__"room26",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/believer" : 3,
	    __DIR__"mob/studentp" : 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
