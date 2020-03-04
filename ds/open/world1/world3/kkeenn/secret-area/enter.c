inherit ROOM;

void create()
{
        set("short", "¦a¤U«°¤J¤f");
        set("long", @LONG
³o¸Ì¤@¤ù±IÀR¯î²D¡A©Ò¿×ªº[ ¥¼¨Ó¯î­ì ]À³¸Ó«üªº´N¬O³o¸Ì¤F§a¡I¥u
¨£¥|¶g¿@¿@ªº¥ÕÃú¥R¥¸¦b§Aªº¨­®Ç¡A¤@°}°}¤F§N­·»PÄY­«¦Ã¬VªºªÅ®ð±aµÛ
ºuºuªº¶À¨F§j¨Ó¡AªþªñªºÄq¥Û°ï¦b³oºØÀô¹Ò¤U§óÅãªº©ú«G»P¬Ã¶Q¡A¦b¸}®Ç
Ãä¦³¤@­Óº£¶Âªº¬}¸]¡A¤£ª¾¹D³q©¹­þ¸Ì[0;1m¡[1mC[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 "down":__DIR__"sec1.c",
 "north":"/open/world3/tmr/basic/digging_road7.c",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("outdoors","future");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


