inherit ITEM;
void create()
{
        set_name("虎骨", ({ "tiger bone", "bone" }));
        set("long",@LONG
這個東西雖然叫虎骨, 但它的來源卻不一定是老虎, 只要是生性
猛暴的大型肉食動物, 都從牠可以取得這種藥材. 虎骨有些是取背脊
的, 有些也有取頭骨, 其他部份的骨就比較少見. 這種藥材算是動物
性的, 而且藥性頗烈. 虎骨大部份須要經過處理才會有一定的藥效.
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("value", 40);
		set("attr",([
			"hp":20,
			"mp":-10,
			"ap":30,
			"wound":0,
			"yang":1,
			"yin":0,
			"fol":0,
			"animal":1,
			"plant":0,
			"needfire":55,
			"needfol":1,
			"mixedtime":0,
			"poundtime":-1,
			"can_eat":0,
		]));
        }
        setup();
}
