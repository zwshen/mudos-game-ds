inherit ROOM;
void create()
{
 set("short","ksj ªº©ñªª³õÇ");

 set("long",@LONG
    ¤@¤ù«Cºñªº¤j¯ó­ì¡A¾A¦X©ñ¾i°Êª«¡C
LONG
    );
 set("exits",([ 
 
    "north": __DIR__"room4", 
    "east": __DIR__"room8",
    ]));
 set("light",1);
 set("no_drop",1);
 set("no_get",1);
// set("light",1);
// set("light",1);
 setup();
}
