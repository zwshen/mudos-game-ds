#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("手札", ({ "letter", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                 set("long",@LONG
你看見上面寫著:
       致誠愛的阿瑟芬副官:
	弟兄們的士氣正在降低, 而我們埋伏在海政司的
	擔任西副師的阿爾尼斯兄弟已經被蠻子們發現了.
	如今最後時刻已經到來, 我願以所有我的軍火來
	擴大西方帝國的版圖, 請求立刻發兵.
				         忠誠的林傑克.
LONG
    );
                }
        setup();
}
