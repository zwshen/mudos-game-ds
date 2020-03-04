inherit ROOM;

void create()
{
	set("short", "»AªL¥Û¶¥");
	set("long", @LONG
¦b§Aªº¨­®Ç³£¬O«C»Aªº¦ËªL¡AÀHµÛ­·§jªL¤¤ªº¦Ë¸­¤£®É¦aµo¥X¨F¨Fªº
Án­µ¡C§A¸}¤Uªº¥Û¶¥¬O¥Î´¶³qªº¥ÛÀY¬ä¦¨ªº¡A¨Ã¨S¦³¤°»ò©Ç²§¤§³B¡CµL·N
¶¡§Aµo²{¦b¥Û¶¥®Ç¦³¤@­ÓµP¤l(sign)¡C
LONG
	);

	set("item_desc", (["sign":@NOTE
[1;32m
		§Å¬r±Ð¸T¦a,«D½Ð¤Å¤J¡C
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 2 */
            "up" : __DIR__"room02",
	    "out": __DIR__"room00",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/believer" : 1,
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
