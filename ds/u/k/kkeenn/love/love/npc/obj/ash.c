inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("¦ÇÂu", ({"ash"}));
        set("unit","°ï");
        set("value", 0);
        set("no_sac", 1);
        set("long", "¤@°ï¶Â¶Âªº¦Ç¡C\n");
	set("heal", ([
		"hp" : 1,
		"ap" : 1,
		"mp" : 1,
	]));
	set("eat_msg", "$N¦Y¤U¤@°ï¦ÇÂu¡C\n");

        setup();
}
