// ¶ר₪Z­}´µ
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¶ר₪Z­}´µ¥¿«°×ש"NOR);
	set("long", @LONG
³o¸ּ¬O¶ר₪Z­}´µ×÷¥¿«°×ש¡A«°×ש₪־«°ְנ³£°×±o₪£₪׃¹³¸Ü¡A¬Ý°_¨׃₪w¸g
¨S¦³¥פ¦ף×Z¾¹¯א¹ן³o¸ּ³y¦¨¯}ֳa₪F¡A¨«¹D₪־¨ג®ַ₪Wֶ^µÛ¦U÷״¬¯ִR×÷¯[¼‏¡A
©ׂ±ֶ¥X×÷¹ִֻֿ¼ֻ¦¡ֵ‎₪H­ך¦i©ׂ«ה¡C¦b«°×ש®ַ§A¬Ý¨ל₪F₪@¶פ«ףµP(plaque)¡C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room008",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gateguard" : 2,
	]));

	set("light", 1);

	set("item_desc", ([
		"plaque":@NOTE
«ףµP₪W¼gµÛ:
		[1;32;44mשÝשששששששששששששששששששששששששששששששששששששששß[m
		[1;32;44mשר      ¶ר      ₪Z      ­}      ´µ      שר[m
		[1;32;44mשדשששששששששששששששששששששששששששששששששששששששו[m

NOTE
     ]) );

	setup();
	replace_program(ROOM);
}
