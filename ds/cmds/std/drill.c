// go.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

void drill_in(object me,object ground)
{
	message_vision("$N往地下鑽去。\n",me);
	me->move(ground);
	tell_room(ground,me->name()+"從地面上鑽了下來。",({me}));
	return ;
}

int main(object me, string arg)
{
	object env,ground;
	string env_file,ground_file;
	env = environment(me);
	env_file=base_name(env);
	if( userp(me) && !wizardp(me) ) return 0;
	write(env_file +"\n");
	
	if(env->query("no_drill")) return notify_fail("這裡無法遁地。\n");
	if(sscanf(env_file,"%*s.ug") != 0) return notify_fail("你已經在地底了。\n");
	ground_file = env_file + ".ug";
	if(ground=find_object(ground_file+".c")) drill_in(me,ground);
	else if(ground=load_object(ground_file)) drill_in(me,ground);
	else return notify_fail("這裡無法遁地。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : drill
 
讓你鑽入地下。
 
HELP
    );
    return 1;
}
