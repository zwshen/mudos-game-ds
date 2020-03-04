inherit ROOM;

void create()
{
        set("short", "¤jÆU");
        set("long", @LONG 
³o¸Ì¬O¥j¹Ó¬£¥D¤H¤§¤@ [36m¡u¤pÀs¤k¡v[0m ªº©Ð¶¡¡A¦b³o©Ð¶¡ªº¤¤¤W¤è¡A¦³¤@æ
±øªø¤Q¤Ø¤K¤oªº²Ê³ÂÃ·¡A¾Ú»¡¤pÀs¤kºÎÄ±  ¥ð®§¸ò½m¥\¡A³£¬O¦b³o±øªøªøªº
Ã·¤l¤W¡A»´¥\³y¸Ú¡A¤£¥i»´µø ¡C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"room4",
]));
        set("objects", ([ /* sizeof() == 1*/
  __DIR__"dragongirl" : 1,
]));      
        set("no_clean_up", 0);
        setup();

}

