inherit ITEM;
void create()
{
        set_name("首烏", ({ "head black", "black" }));
        set("long",@LONG
這是一株還算常見的草藥, 它最大的特徵, 就是它開的花和
新枝葉, 都是泛黑的, 因此此藥草算十分好認, 此藥草通常都是
被拿來做藥引的, 沒有辦法生食.
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("value", 25);
		set("attr",([
			"hp":5,
			"mp":0,
			"ap":15,
			"wound":1,
			"yang":0,
			"yin":1,
			"fol":1,
			"animal":0,
			"plant":0,
			"needfire":28,
			"mixedtime":0,
			"poundtime":0,
			"can_eat":0,
		]));
        }
        setup();
}
