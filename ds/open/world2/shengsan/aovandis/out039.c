// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
��L�����p�ͪ��`�b�o���A�A�x�֪��p�Q�����ɷ|��e�̦b�~������
���F���æb�o�̭��C�A�ݨ�o�̦��������y���q�۾��_�̬y�X�ӡA�]�\�A
�i�H�|�|(taste)�䤤���礤�����C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out045",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
}

void init()
{
	add_action("do_taste","taste");
}

int do_taste(string arg)
{
	object me;
	me=this_player();
 
  if(!arg) return notify_fail("�A�Q�|����?\n");
  if(arg=="�y��"||arg=="��"||arg=="water")
  {
 	if(me->is_ghost()) return notify_fail("�[1m�ѤW�Ǩӱy�y���n��: �[33m�ڥu�����U���ͩR���H�C�[0m\n");
	message_vision("$N�s�U�y�ܤF�X�f�ѵM�u���C\n", me);
	if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
	{
 	 me->reincarnate();
	 tell_object(me,"�A�����骬�p�����^�_�F�C\n");
	 return 1;
	} else
	{
		return notify_fail("�Aı�o�Q���M�D�C\n");
	}
 }
 notify_fail("�A�Q�|����?\n");
 return 0;
}
