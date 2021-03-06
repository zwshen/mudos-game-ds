// Room: /open/world1/tmr/advbonze/hill15.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上天梯");
	set("long", @LONG
你正走在凌雲峰名勝「上天梯」上，你可以看到延著往北而通往
山頂的一節一節天然石梯，你抬起了頭往山頂望了過去，看樣子只剩
下不到二十來階的石梯路，你隱隱然從峰頂濃厚的霧裡看到清楚的金
色光線散發出來，你被這道光線照射的飄飄然，非常的舒服，似乎也
忘記了走山梯路的疲勞。
LONG
	);
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill16",
  "southdown" : __DIR__"hill14",
]));

	setup();
	replace_program(ROOM);
}
