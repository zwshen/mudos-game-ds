#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("ＣＫ鋼靴",({"ck steel shoes","shoes"}) );
	set("long",@LONG
這雙沉重的鋼靴是日本的ＣＫ重機為旗下傭兵團所設計的，但因為關
節處有瑕疵，已經全面回收了。
LONG
);
	set_weight(5950);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "雙");
	}
	set("value",2450);
	set("armor_prop/armor", 12);
	setup();
	set("volume", 4);
}

//int query_autoload() { return 1; }
