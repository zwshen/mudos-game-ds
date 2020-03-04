#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("[0;35mµµ¤ô´¹[0m", ({ "purple crystal", "crystal" }));
	set("long", @LONG
³o¬O¤@¶ô¤Q¤À¯S®íªº¤ô´¹¡A¬O©ñ¸m¦b·É¤ô¤ô¬}¤¤ªº¡A¬O±q«e½L¥j¶}¤ÑÅP
¦a¤§«á¡A¥Lªº¤@Áû¤ú¾¦©Ò¦¨ªº¡A¶Ç»¡¦]¬°¬O¦b½L¥jªº¼L¤Ú¤¤¡A¦b²`¤s¤¤
ªº¤@³B¬}¤º¡A¦pªG±N¦¹¥Û©ñ¤W(lay on stone)¡A±N·|³y¥X³\¦hªº¤ô¡C
LONG	);
	set_weight(9999);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "­Ó");
		set("value", 1);
		set("no_sell", 1);
		set("no_sac", 1);
	}
	setup();
}