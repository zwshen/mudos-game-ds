// �p�޽�			by shengsan
// �i�H�M�����d��
// ��: ���ȬO�����ͪ��i�H�M��, �N��O�S���ͩR���F��]�i�H, �Ҧp ���涳
//     �u�n�[�W set("ridable",1); �N�i�H�M��
inherit NPC;

void create()
{
	
	set_name("�p���",({"pig"}) );
	set("race", "���~");
	set("level",10);
	set("age",31);
	set("long", "�@���i�R���p��ޡC\n");
	set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"}));
	set("verbs", ({"bite"}));
	set("ridable",1);		// �]�w���i�M����
	setup();
}

int ride_before_action(object me)	// �M�����e�|����禡
{
	int s = me->query("str");
	if( s<10 || !s )
	{
		message_vision("�ѩ�$N���O�q�����A�L�k����"+this_object()->name()+"�A�]�ӳQ"+this_object()->name()+"�q�p�ޭI�W�L�F�U�ӡI\n",me);
		return 0;		// �^�� 0 �N�O�N�������M��
	}
	else 	message_vision("$N���X���@���"+this_object()->name()+"���ʴX�U�C\n",me);
		return 1;		// �^�� 1 �N�O�N���i�H�M��

}

int ride_after_action(object me)	// �M������|����禡
{
	message_vision("$N�M�W�F"+this_object()->name()+"�S�X�@�ƫܱo�N���ˤl�C\n",me);
	return 1;			// �����n�^�� 1
}


int ride_off_action(object me)		// ���}�y�M����|����禡
{
	message_vision("$N�p�����t, �����������s�C\n",this_object());
	return 1;			// �����n�^�� 1
}

int accept_object(object me,object obj)
{
	message_vision("$N�ĨĪ��w�F�U�ӡC\n",this_object());
	return 1;
}