inherit ROOM;

void create()
{
        set("short", "¹DÀ]¤jªù");
        set("long", @LONG
§A¨«¦b¤@±ø¤H·Ïµ}¤Öªº¤jµó¤W¡A¥¿«e¤è´N¬O»·ªñ¹£¦Wªº¡u·s¤â¤j¹DÀ]¡v¡A
¥þ¼Ó°ª4¼h¡AÁôÁô¬ù¬ù³£¥i¥HÅ¥¨ì«Ü¦hÂøÁn¡A¥|©P³£¬O ¬\ÃÃ ¦Ñ¾ð ©ü¾~¡A¡
³o­Ó¹DÀ]­Ê¤s¾a¤ô¡A­·´º¨qÄR¡AÃø©Ç·|»·ªñ¹£¦W¡C 
¦ü¥G¦³©ÇÃ~ªºÁn­µ¦b¸ò§A¬DÆ]¡CLONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"/open/world1/cominging/purple_sun/psin3",
  "north" : __DIR__"room2",
  ]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"beast" : 2,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

