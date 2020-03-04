//recall.c
#include <ansi.h>
#include <login.h>
#define  START_D "/open/world2/anfernee/start/login"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
int lv,i,world;
int delay;
    string *busy_type,bank;
mapping is_busy=([ ]);
mixed no_recall;
lv=me->query("level");

if(!wizardp(me))
{
	if(me->is_ghost()) return notify_fail("�A�èS������C\n");
	
		if(mapp(is_busy=me->query_temp("is_busy")))
		{
			busy_type=keys(is_busy);
			for(i=0;i<sizeof(is_busy);i++)
			{
				if(stringp(is_busy[busy_type[i]])) return notify_fail(is_busy[busy_type[i]]+"\n");
				if(!is_busy[busy_type[i]]) return notify_fail("�A�ȮɵL�k���ʡC\n");
			}
		}
	
	if(me->is_fighting())
		return notify_fail("�A�b�԰����A�S�ũI�s�����C\n");
	if(me->is_busy())
		return notify_fail("�A���W�@�Ӱʧ@�٨S�����A�S�ũI�s�����C\n");
	if(no_recall=environment(me)->query("no_recall"))
	{
		if(stringp(no_recall)) return notify_fail(no_recall+"\n");
		return notify_fail("���a���G�S�����󰭯����O�s�b�C\n");
	}
	if(me->query_temp("no_recall"))
		return notify_fail("�����ä��z�|�A���D�ϡC\n");
	if(me->query_temp("killer"))
		return notify_fail("�A���F�H�A�����ä��z�|�A���D�ϡC\n");
	if(!environment(me)->query("outdoors") && lv > 4) //���O�ǥ~
	{
		world=me->money_type();
		switch(world) {
			case 1:
				bank="past";
				break;
			case 2: 
				bank="now";
				break;
			case 3: 
				bank="future";
				break;
			case 0: 
				bank="now";
				break;
			default:
				bank="past";
				break;
		}
		if(me->query("bank/"+bank)<lv*10) return notify_fail(@ERROR
�A���b�ᤤ�����n���������^�m���~��b�Ǥ����X�Ͽ����I�i���Τ��N�C
ERROR
);
		else me->add("bank/"+bank,-lv*10);
		//return notify_fail("�����n���b��~���m�B�ѯ��~���ť���A���D�ϡC\n");
	}
 }
 if(!bank) message_vision("  $N���W�����A�q�q���V�ѯ�ë�i�A��D���U�C\n\n",me);
 	else message_vision("  $N�f���q��: �·t���������ڡ���ɴ�����U�ڲ��Ρ�\n\n",me);
 me->remove_all_enemy();
        delay = 1 + random(5);
        me->start_busy(delay);
        call_out("do_move",delay ,me,arg);
 return 1;
}

void do_move(object me,string arg)
{
 int world;
 string moveto,buffer1,temp;
 object env;
 if(!me) return;
 if(wizardp(me) && arg == "back")
 {
 	moveto=me->query("last_location");
 	if(!stringp(moveto))
 	{
 		tell_object(me,"  �A�S�����ʰO���C\n");
 		return;
	}
	message_vision("  �ѤW��M���X�@���j���$N�쨫�F!\n",me);
	me->move(moveto);
	return;
 }
 
 moveto=me->query("startroom");
 world=me->money_type();
 if(world==1)
 {
        if(stringp(moveto) && arg!="start") 
        {
        	if(sscanf(moveto,"/open/world1/%s",buffer1)!=1)
		moveto=START_ROOM_PAST;
        }
        else moveto=START_ROOM_PAST;
 }
 else
 if(world==2)
 {
 	env=environment(me);
        temp=base_name(env);
        if( sscanf(temp,"/open/world2/anfernee/start/%s",buffer1)==1
            	|| sscanf(temp,"/open/world2/luky/test/%s",buffer1)==1
        ) moveto=START_ROOM;
        else
        if(stringp(moveto) && arg!="start") 
        {
        	if(sscanf(moveto,"/open/world2/%s",buffer1)!=1)
        	moveto=START_ROOM_NOW;
        } else moveto=START_ROOM_NOW;
 
 }
 else
 if(world==3)
 {
        if(stringp(moveto) && arg!="start") 
        {
        	if(sscanf(moveto,"/open/world3/%s",buffer1)!=1) moveto=START_ROOM_FUTURE;
        } else moveto=START_ROOM_FUTURE;
 }
 else moveto=START_ROOM;
   message_vision(HBK"  �u��$P"HBK"�����麥���Ƭ��@�η���, �����b�Ů𤤡��\n"NOR,me);
 me->move(moveto);
 message_vision(HBK"  �@�}�����ƹL, $N�����v�������������T\n"NOR,me);
}


int help(object me)
{
	write(@HELP
���O�榡�R recall (start) || (back) 

�o�ӫ��O�i�H���A(�p)���t�^��O���I�C

[ �`�N: ���b��~���m�B�i�����I�s�ѯ����U  ���t�Ǥ��N�����H�� ]
[       ���N���X�Ͽ����U�A�I�i���Τ��N�C(�N�۰ʥѱb�ᤤ����) ]

����: recall start �^�줺�w���X�o�I.
      recall back  �^��goto�e����m. (�Ův�M��)

HELP
    );
    return 1;
}