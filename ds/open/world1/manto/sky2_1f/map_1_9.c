// Room: /open/world1/manto/sky2_1f/map_1_9.c

#include <dbase.h>
#include <ansi2.h>

inherit CLUB_BANK;

void create()
{
        set("short", HIW"『天地大錢莊』"NOR);
        set("long", @long
這裡就是天地會內裡的天地大錢莊，用來放幫會經費之用。
long
+HIR""
+"　　[deposit]　－－－－－－－　[存款－適用所在時空貨幣]\n"
+"　　[transfer] 　－－－－－－　[轉帳－適用任何時空貨幣]\n"
+"　　[withdraw] 　－－－－－－　[提款－適用所在時空貨幣]\n"
+"　　[clear]　－－－－－－－－　[清除存取記錄]\n"
+"　　[list] 　－－－－－－－－　[查看幫會資產排行]\n\n"NOR
);
        set("club_id", "sky");
        set("club_level", 7);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"map_3_9",
]));

	setup();
        set("stroom", 1);
        set("long", query("long") 
                + BANK_D->get_bank_amount(query("club_id")) 
                + BANK_D->get_log(query("club_id"), "deposit")
                + BANK_D->get_log(query("club_id"), "withdraw")
        );
}
