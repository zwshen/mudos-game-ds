inherit ITEM;

void create()
{
	set_name("商陸",({"phytolacca acinosa roxb","roxb"}) );
	set_weight(80);
	set("long",@long
商陸為商陸科多年生草本，無毛，根肥厚，肉質，圓錐形，外皮呈淡
黃色，。其莖呈綠色或紫紅色。；其藥用根，秋冬採挖，味苦，性寒，有
毒。能治瀉水、利尿，消腫
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","株");
		set("value",60);
	}
	setup();
}