// promote.c
#include <ansi.h>
inherit F_CLEAN_UP;
private string *wiz_levels = ({
	"(player)",
	"(superplayer)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});
int main(object me, string arg)
{
	object ob;
	string old_status, new_status,name;
	int my_level, ob_level, level;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("Αpromote <ㄏノ> <单>\n");

	if( wiz_level(new_status) < 0 ) return notify_fail("⊿Τ硂贺单\n");
	tell_object(me,"member_array(new_status, wiz_levels):"+member_array(new_status, wiz_levels)+"\n");
	if( (int) member_array(new_status, wiz_levels)<0 ) return notify_fail("⊿Τ硂贺单\n");
	if( !objectp(ob = present(arg, environment(me))) 
	||	!userp(ob) )
		return notify_fail("э跑ㄏノ舦\n");

        if( wiz_level(me)<6 && wiz_level(me) <= wiz_level(new_status)+1 )
// パ <  эΘ  <= 
		return notify_fail("⊿Τ硂贺舦\n");

	if( wiz_level(me)<6 && wiz_level(me) <= wiz_level(ob) )
		return notify_fail("⊿Τ硂贺舦\n");

	if( wiz_level(me)<6 && new_status == "(admin)" )
		return notify_fail("⊿Τ硂贺舦\n");

	name=ob->query("id");
	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, me, new_status)) )
		return notify_fail("эア毖\n");
	if(new_status=="(superplayer)")
	{
		mkdir("/superplayer/"+name[0..0]+"/"+name);
		ob->set("cwd","/superplayer/"+name[0..0]+"/"+name+"/");
	}
	else if((old_status=="(player)" || old_status=="(superplayer)") && new_status!="(player)")
	     {
	     	mkdir("/u/"+name[0..0]+"/"+name);
		ob->set("cwd","/u/"+name[0..0]+"/"+name+"/");
		message("system",HIC+"\n\n\t礛丁い窾笵▇   臚 °° 订 ° 订 °\n\n\t"
					+ob->name_id(1)+HIC+""+me->name()+HIC+"稰眔笵どぱ冠ほ办眖畍\n\n"
					+NOR,users());
	     }
	if(new_status=="(superplayer)" || new_status=="(player)") ob->disable_wizard();
	message_vision("$N盢$n舦眖 " + old_status + " э " + new_status + " \n", me, ob);
	seteuid(getuid());
	ob->setup();
	ob->save();
	return 1;
}

int help(object me)
{
write(@HELP
Α : promote <琘> (舦单)

ノㄓ矗ど舦单,

单6  (admin)
单5  (arch)
单4  (wizard)
单3  (apprentice)
单2  (immortal)
单1  (superplayer)
单0  (player)

 admin 矗ど舦ヴ单, τ arch 矗ど appr
HELP
    );
    return 1;
}
