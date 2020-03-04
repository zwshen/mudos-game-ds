#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIC"¥ì®¦ªº¤u§@«Ç¤J¤f"NOR);

 set("long",@LONG
³o¸Ì¬O¥ì®¦¤u§@«Çªº¤J¤f, §A«e­±½Ý¥ßµÛ¤@®°ÅKªù, ÅKªù¤W¤w¸gÂÐ¤W
¤F«p«pªº¤@¼hÁ÷, ®ÇÃäªº¬[¤l¤W±¾µÛ´X¥ó«O·xªº¥Ö¸Ê, ¤W­±¤]³£»\µÛ¤@¼h
Á¡Á÷, ¦ü¥G¬O¨Ñ¤J¤ºªº¤H«O·x¥Îªº, §A¤@²Ó¬Ý, ¬[¤l®Ç±¾µÛ¤@­ÓµP¤l, ¤W
[D¼g¡y¤º³¡·Å«×§C©óÄá¤ó¹s«×, ½Ð¬ï¥Ö¸Ê¤J¤º, ¥H§K­á¶Ë. ¡z§A¤£¸T¹ï³o¶¡
¤u§@«Çªº¾Ö¦³ªÌ·P¨ì¬Û·íªº¦n©_...
LONG
    );
 set("exits",([ "wiz":"/d/wiz/hall1",
                "area":"/u/i/ian/area/birdpill",
                "enter":"/u/i/ian/workroom2",
                "ptstart":"/open/world1/tmr/area/hotel",
    ]));
        set("no_fight", 1);
        set("light",1);
 set("objects",([
 "u/i/ian/weapon/furredrobe":5,
                 ]));
 set("no_clean_up", 1);
 setup();
 replace_program(ROOM);
 

}

