
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���Ũ�m",({"lattice shirth","shirth"}) );
	set("long","�o�O�@�󦳵۪���l�ϼ˪�Ũ�m�C\n");
	set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
		set("value",230);
        }
        setup();
}

int query_autoload() { return 1; }
