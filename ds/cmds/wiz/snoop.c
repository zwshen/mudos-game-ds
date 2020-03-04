// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;
void create()
{
	seteuid(getuid());
}
int main(object me, string arg)
{
	object ob;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("�A�{�b���b��ť" + ob->query("name") + "�Ҧ��쪺�T���C\n");
		return 1;
	} else if( arg=="none" ) {
		if( objectp(ob = query_snooping(me))
		&&	wiz_level(ob) >= wiz_level(me) )
			tell_object(ob, HIW + me->name(1) + "�����ť�A�Ҧ��쪺�T���C\n" NOR);
		snoop(me);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("�S���o�ӤH�C\n");

	if( wizhood(me) != "(admin)"
	&&	wiz_level(me) <= wiz_level(ob) )
		return notify_fail("�A�S����ť" + ob->name(1) + "�Ҧ�ť�T�����v�Q�C\n");

	if( me==ob ) return notify_fail("�Х� snoop none �Ѱ���ť�C\n");
		
	snoop(me, ob);
	if(ob->query_temp("gb_player")) me->set_temp("snoop_type","gb");
	else me->set_temp("snoop_type","big5");
	write("�A�{�b�}�l��ť" + ob->name(1) + "�Ҧ��쪺�T���C\n");
	
	if( wizhood(me) != "(admin)" )
	{
		if( userp(ob)) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
		if( wizardp(ob) )
		tell_object(ob, HIW + me->name(1) + "�}�l��ť�A�Ҧ��쪺�T���C\n" + NOR);
	}
	return 1;
}

int help()
{
	write(@TEXT
���O�榡�Rsnoop <�Y�H>|none

��ť��L�ϥΪ̩Ҧ�ť���T���Msnoop none �h������ť�C
TEXT
	);
	return 1;
}