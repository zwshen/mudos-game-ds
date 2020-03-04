// Room: /d/wiz/jobroom.c

inherit ROOM;

void create()
{
	set("short", "¤u§@¶i«×Â²³ø«Ç");
	set("long", @LONG
³o¸Ì¬O§Å®v­Ì³ø§i¦Û¤v¤u§@¶i«×ªºÂ²³ø«Ç¡M¦P®É¤]¬O¤j§Å®v§ì¤½®t
ªº®Ú¾Ú¡M¦pªG§A¦³¤u§@°µ¡M³Ì¦n±`±`¨ì³o¸Ì§ó·s§Aªº¤u§@¶i«×¡M¦pªG¤Ó
¤[¨S¦³¬Ý¨ì§Aªº¤u§@¶i«×³ø§i¡M¤j§Å®v­Ì·|¥H¬°¥H¨S¨Æ°µ¦Ó«ü¬£¤u§@µ¹
¡M­n¬O§A¤´µM¤£²z¡M¤]¦³¥i¯à·|³Q°²³]¦¨¤w¸g©ñ±ó§Å®vªº¤u§@¦Ó­°¦^ª±
®a¨­¤À¡C§Aª`·N¨ì¥kÃäªºÀð¤W·s¶K¤F¤@±i[1;37m¯È±ø(Note)[0m¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/wiz/hall1",
]));
	set("no_clean_up", 0);
set("item_desc",([
  "note":@NOTE

============¤u§@¶i«×¬ö¿ýªOªº¨Ï¥Î¤èªk¦p¤U===============

 ·s¼W­p¹º: project   <¼ÐÃD>
 ³ø§i¶i«×: report    <­pµe½s¸¹> <¶i«×³ø§i¼ÐÃD>
 ¾\Åª­p¹º: read      <­pµe½s¸¹>[.<³ø§i½s¸¹>]|new|next
 §R°£­p¹º: terminate <¯d¨¥½s¸¹> 

=======================================================
  
PS.¦]¬°³o­Ó¯d¨¥ªOªº¨Ï¥Î¤è¦¡¦³ÂI¤£¤Ó¤@¼Ë, ©Ò¥H§Ú¶K±i¯È±ø
µù©ú¤@¤U¨Ï¥Î¤èªk.
			-Às½¼(Luky)·q¤W.1999.7.24.-
NOTE
,]));

	setup();
	call_other("/obj/board/wizard_j", "???");
	replace_program(ROOM);
}
