// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���]�G��"NOR);
	set("long", @LONG
�����q����z�g�i�ӡA�ӫG�F��өж��C�q�o�̥i�H�ܲM�����ݨ���
�~�������A�p�G�ⵡî(drapes)�ԤW�A�A�|�o�{��î�N�n���O�@�T�e�@��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room104",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("no_fight",1);
	set("no_cast",1);
	set("no_exert",1);
	set("room_type","hotel");

	setup();
}

void init()
{
	add_action("do_draw","draw");
	add_action("do_sleep","sleep");
}

int do_draw(string arg)
{
        if( arg == "drapes" )
        {
                if( query_temp("drapes_close") )
                        return notify_fail("��î�w�g�ԤF�_�ӤF !\n");
                message_vision("$N�N��î�������ԤF�_��, �̭��ܱo����t�F..\n", this_player());
                tell_room(this_object(),"�A�ǳƵεΪA�A���έ�ı(sleep)�F�� ?\n", ({ }));
//              message_vision("�A���G�o�{��î���G�a���۬Y�ǹϮ�\n", this_object());
//              �ǳƵ��_�I�̥ΡC by cominging
                set_temp("long", @LONG
�ԤW����î����F�j�P�������A����ܦ��@�D�D�X�M�������A��g�F
�i�ӡA�ж������F�A�ũM�B�ΪA���Pı�C
LONG            );
                set_temp("drapes_close", 1);
                return 1;
        }
        else return 0;
}

int do_sleep(string arg)
{
	object me;
	me=this_player();
	if(me->query_temp("is_busy/sleeping"))
	{
		write("�A���b��ı�C\n");
		return 1;
	}
	if( me->query_temp("hotel_1") <= 0 )
	{
		write("�A�n���I�O�~��𮧡C\n");
		return 1;
	}
	message_vision( GRN"$N�|�F�|�����A���֦��G�Q�O���ε���W�F�A�Ԥ����ɤW�@����\n\n" NOR, me);
	tell_object(me,"�A�����@���A�H�Y�N�b���n�A�����ɤW�εۤF.....\n\n" NOR );
	tell_object(me, HIB"�C��C����C������C�C���C\n\n\n" NOR );
	me->set_temp("is_busy/sleeping","�A���b��ı�C");
	me->start_busy(10);
	call_out("sleep1",3,me);
	call_out("sleep2",8,me);
	call_out("wakeup",15,me);
	return 1;
}

void sleep1(object me)
{
	if(!me) return;
	tell_object(me,HIG"�A�����i�J�F�ڶm�A�ڨ��ۤv�}�y�b�F�z��\n"NOR);
	me->receive_heal("hp",me->query_con()*4);
	me->receive_heal("ap",me->query_con()*2);
	me->receive_heal("mp",me->query_int()*3);
	return;
}

void sleep2(object me)
{
	if(!me) return;
	if(random(2)) tell_object(me,HIG"�ڤ����A�J��F�@�s���T..�W���\n"NOR);
	else tell_object(me,HIG"�A����F�@����w�A���n�h�����G���\n"NOR);
	me->receive_heal("hp",me->query_con()*5);
	return;
}

void wakeup(object me)
{
	if(!me) return;
	if(random(2)) tell_object(me,"�Aı�o�A���H�֧��z�F..���o���_�ɡC\n");
	else tell_object(me,"�A��M�Q����p�Ī����n���n���F�C\n");
	message_vision(HIW"$N���F�@���i�y�A�|�F�|�������F�L�ӡC\n" NOR,me);
	me->delete_temp("is_busy/sleeping");
	me->receive_heal("hp",me->query_con()*7);
	me->receive_heal("mp",me->query_int()*3);
	me->receive_heal("ap",me->query_con()*3);
	me->add_temp("hotel_1",-1);
	return;
}
