inherit ROOM;

void create()
{
	set("short", "迷霧森林入口");
	set("long", @LONG
你發現這裡已經沒有路可以走，要再往前走就要進入森林的內部
。你仔細的往森林內看去，看到樹影閃爍，一瞬間還以為樹木對著你
包圍過來。這裡插著一面告示牌。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"burg8",
                "enter" : __DIR__"wforest1",
	]));
	set("item_desc",([
        "告示牌":"┌──────────┐\n"
        	 "│ § 迷 霧 森 林  § │\n"
        	 "└┬┬──────┬┬┘\n"
        	 "  ││            ││  \n",
        ]));

	setup();
	replace_program(ROOM);
}
