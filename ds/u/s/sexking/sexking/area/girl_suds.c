#include <ansi.h>
inherit ROOM;
void create()
{
        set("short"," "HIM"�k�Ϊ���"NOR" ");
        set("long",@LONG
�o�̬O�k�̱ͭM�Ϊ�����A �|�B���Ƶ۲M���A�٨S�w���A�p���믫
�w��_�F�@�j�b�ݼˤl�o�a����G�M�W�����...���ӥi�H�w���ܵ�
�A�a...�p�w�Ԥ����Q����j�D���̤F�C
LONG       
);
        set("exits", ([
  "south" : __DIR__"bath_2",
]));
set("objects",([
__DIR__"tub" :1,

]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_in","in");
}

int do_in(string arg)
{
        object me,where;
        me = this_player();
        if( me->query_temp("suds") <= 0 )
        {
                write("�S�I���Q����D��?���ೣ�S���I\n");
                return 1;
        }
      if( me->query_temp("armor") )
       {
       return notify_fail("���F�åͰ_��..�Ч�p���W���˳Ƴ���(rem)�U�b�i�h�w���a�I\n");
       return 1;
       }
       if( me->query_temp("weapon") )
       {
       return notify_fail("���F�åͰ_��..�Ч�p���W���Z������(uwi)�U�b�i�h�w���a�I\n");
       return 1;
       }
        if( me->is_busy() )
        return notify_fail("�p�٦b����...\n");
        if( me->is_fighting() )
        return notify_fail("�p�٦b�԰����A�S���ťh�w����\n");
        message_vision("$N�����w�ߪ��]�V�j�D���̶]�F�L�h�C\n",me);
        me->start_busy(2);
        me->move(__DIR__"girl_bath");

    return 1;
}