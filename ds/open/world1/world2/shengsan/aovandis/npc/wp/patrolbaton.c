#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("ĵ��", ({"baton"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@����C�M�W����ۡu�ȯS�v��Ӧr�C\n");
		set("value", 1000);
	}
	init_staff(20);
	setup();
}

int query_autoload() { return 1; }
