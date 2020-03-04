// id.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string area;
	object env;
	env=environment(me);
	area = area_domain(base_name(env));
	write("┮跋办烩办琌:"+area+"\n");
	return 1;
}
int help(object me)
{
write(@HELP
Α : queryarea
 
琩高ヘ玡┮烩办.

HELP
    );
    return 1;
}
 
