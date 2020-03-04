// Room: /u/l/luky/room/pearl_40.c
inherit ROOM;
void create()
{
set("short", "[1;32m°|ªø«Ç[m");
set("long", @LONG
¶V¹L¤jÆUÄ~Äò©¹¤W¨«¨ì¤F°|ªø«Ç¡A¨SºVÁnªù´NÂô¤F¶i¨Ó¦ü¥G¤£«Ü
Â§»ª¡A¤£¹L¨£¨ì°|ªø¨º·O©Mªº¯º®eªí¥Ü¦o¨Ã¤£¦b·N¡AÆ[¬Ý©P³òÀô
¹Ò¡AÂ\µÛ±i®Ñ®à(Table)¡A¤@¥u®ÑÂd(Case)¡A®¼¾ë¹êªº¤u§@©Ð¡C

LONG
);
set("objects",([
__DIR__"npc/perfect":1,
]));
set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"pearl_37",
]));
set("item_desc",([
"table":"¥uÂ\\¤F´X±i¯È(Paper)¡A©M¤@¥»°|ªø¥¿¦b¬Ýªº®Ñ(book)¡AÅãµM¥´ÅÍ¨ì
°|ªø¬Ý®Ñ¤F..\n",
"case":"¥¿¦p³o­Ó¦a¤è¸Ó¦³ªº¡A¥þ¬O¦³Ãö¯«¾Çªº®Ñ¡A¨S§Oªº¡C\n",
"book":"¥¿·Q²Ó¬Ý®Ñ¤¤¦b¼g¤°»ò®É¡A°|ªø³º±N®Ñ»×¤F°_¨Ó..¬O¦³©ÒÁô¿f¶Ü¡H
°|ªøÁy¤Wªº¯º®e¤S¬Ý¤£¥X¦³Ô£¤ß¾÷..§O¦h¤ß¦n¤F..\n",
"paper":"¯È¤W±K±K³Â³Âªº¼gº¡¹³¤p³L°C¯ëªº¤å¦r(Word)¡A¥u«ë®ÑÅªªº¤Ö¬Ý¤£À´
¡A¬Ý¨Ó¬O°|ªøÃä¬Ý®ÑÃä°µµ§°O..¸Ó¾ß°Q¦Û¤v¤F..\n",
"word":"¸ò¥»¬Ý¤£À´£«!!°Ý°Ý°|ªø§a..\n",
]));
set("no_magic",1);
set("no_kill",1);
set("no_cast",1);
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
