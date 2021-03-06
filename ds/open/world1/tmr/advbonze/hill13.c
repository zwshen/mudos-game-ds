// Room: /open/world1/tmr/advbonze/hill13.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上天梯");
	set("long", @LONG
你正走在凌雲峰名勝「上天梯」上，你可以看到延著往北而通往
山頂的一節一節天然石梯，你抬起了頭往山頂望了過去，看樣子只剩
下不到五十來階的石梯路，你隱隱然從峰頂濃厚的霧裡看到一絲絲金
色光線散發出來，你被這道光線照射的有點舒服。
LONG
	);
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill14",
  "south" : __DIR__"hill12.c",
]));

	setup();
	replace_program(ROOM);
}
