
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�k�v��",({"clothes"}) );
	set("long","�o�O�@��}�G���v�ˡC\n");
	set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
		set("value",870);
        }
        setup();
}

int query_autoload() { return 1; }
