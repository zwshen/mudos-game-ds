#include <room.h>
#include <path.h>
inherit ROOM;
inherit DOOR;
void create()
{
        set("short", "�^�����Τ�");
        set("long",@LONG
�b�o�̦��\�\�h�h���C�ȡA�e�Ӱ��[�L�W�^�����ҩ~�����ΡA�b�@
���p�ߡA�A�ݨ즳�@�ӨS�����w�ߪ��H�A�b�}�a�Τ����\�]�A�O�A���@
�I�İʷQ�n�~��L�A�o���Τl�O�D�n�Ѧˤl�Һc���A�b�γ����\�h�s��
��R���ϮסA�b�o�]���@�i���(chair)�A���G�O���H�𮧥Ϊ��C
LONG
        );
        set("exits", ([
  "out" : __DIR__"herohouse.c",
]));
        create_door("out","�}�¦˪�","enter",DOOR_CLOSED);
        set("objects", ([
    __DIR__"npc/ravager.c" : 1,
]));
        set("item_desc",([
  "chair" : "�o�O�@���ȡA���G�i�H��(sit)���ˤl�C\n",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
}

void init()
{
        add_action("do_sit","sit");
}

int do_sit(string arg)
{
        object me,go;
        me = this_player();
          go = load_object(SDO_PAST+"nonhero/h_d.c");
        if( arg!="chair" )
                return notify_fail("�A�n���b���H\n");
        if( me->start_busy() )
                return notify_fail("�A�{�b�b���A�S��k�h���Ȥl�C\n");
        message_vision("$N���W�F�Ȥl�A�b$N������G�o�X�F�@�I���n�C\n",me);
        me->start_busy(3);
        call_out("do_go",4,me,go);
        return 1;
}

int do_go(object me,object go)
{
        if( !go )return 0;
        if( !present(me->query("id"),this_object()) ) return 0;
        message_vision("$N�z�I���@�n�A�Ȥl��M��F�V�A���t�����U�^���C\n",me);
        me->move(go);
        me->command("look");
        return 1;
}