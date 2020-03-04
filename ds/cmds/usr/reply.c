// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("�A�n�^������S\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("��~�S���H�M�A���L�ܡC\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("�����T���w�e�X�M�i��n�y�Ԥ~��o��^���C\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("��~�M�A���ܪ��H�{�b�L�kť���A�M�Ϊ̤w�g���}�C���F�C\n");
        write( "�A�^��" + obj->name(1) + "�R" HIG + arg + "\n" NOR);
        tell_object(obj, sprintf("%s�^���A�R"HIG"%s\n"NOR,
                me->name(1)+"("+me->query("id")+")", arg ));



	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
���O�榡�Rreply <�T��>

�A�i�H�γo�ӫ��O�M��~�� tell �M�A���ܪ��ϥΪ̻��ܡC

see also : tell
HELP
	);
	return 1;
}