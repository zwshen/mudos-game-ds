inherit ITEM;

void create()
{
	set_name("±ï®ä¾ð",({"woo-ton tree","tree"}));
	set("long","±ï®ä¾ð¦b´ËªL¤§¤¤ºâ¬O«Ü´¶¹Mªº¾ð¤ì¡C\n");
	set_weight(9999);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","´Ê");
		set("no_get",1);
	}
	setup();
}