// shop§ï¦Ûherb.c
// Luky 1999.1.9­×§ï
inherit ROOM;
void create()
{
set("short","[1;35m·Rº¸¸Ë³Æ¥æ´«¤¤¤ß[m");
set("long",@LONG
§A¨«¶i³o¸ÌµoÄ±¨Ó¨ì¤@¶¡±Mªù¶R½æ¸Ë³Æªº°Ó©±¡A§A¬Ý¨ì
¥|¶g±¾º¡¤F¦U¦¡¦U¼Ëªº¬ÞµP©Mªø¼Cµ¥¸Ë³Æ¡A®ÇÃäªº¬Á¼þÂd«h
©ñ¤F¨Ç²¯¥Ò©MªA¸Ë¡AÀð¤W¶K¤F±iª`·N¨Æ¶µ(Sign)¡C
LONG
);
 set("light",1);
 set("storeroom",__DIR__"temp/shop");//¦¹¸ô®|³Ì¦n¥´¬Û¹ïªº³á
 set("exits",([
 "south" : __DIR__"pearl_16",
 ]));
 set("item_desc",([
 "sign":"¼È°±Àç·~¤¤¡C\n"
]));
setup();
}
