inherit ROOM;

void create()
{
        set("short", "¤jÆU");
        set("long", @LONG 
³o¸Ì¬O¥j¹Ó¬£¥D¤H¤§¤@ [33m¡u·¨¹L¡v[0mªº©Ð¶¡¡A©Ð¶¡¤ºªºÂ\³]«D±`ªºÂ²³æ
¡AÁöµM»¡Â²³æ¡A¦ý¹ê»Ú¤W¤@©w¤£Â²³æ¡A »¡¤£©w¦³¨Ç¯S§OªºªF¦è©Î¾÷Ãö¡A
¥_¤è¬O¤jÆU¡A¤@²´´N¥i¥H¬Ý¨ì©³¡A¦bµLºÉªº²`³B¡A ¦³ºØ»¡¤£¥X¨Óªº·PÄ± 
¡C
               §AÄ±±o³o¸Ì¤ñ¤@¯ëªº©Ð¶¡ÁÙ­n§N¤@¨Ç
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"room4",
]));
        set("objects", ([ /* sizeof() == 1*/
  __DIR__"goo" : 1,
]));      
        set("no_clean_up", 0);
        setup();

}

