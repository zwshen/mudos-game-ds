// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

void create()
{
	set("short","�̫�ֶ�");
	set("long",@LONG	
�o�̴N�O�ǻ����� VOID -- �j���M�Ův���̫�ֶ�. �A�ݨ�|�P�@��
�կ�����, ���@�|�q��L���_�X�@�����Z, �����A�@���u�i�f�i�֡v(tm), 
�M�᯸�b�@�ǫܨ��c�a����. �S�L�F�@�|, �@���_�������F�L��, �@�x���
�F�������Z�ñq�A��W�m�����~�i��, �j���T�n��N�q�A���e�����F.
�A�n�n�Y, �o�ئa���٬O���n�ݤӤ[���n.
LONG
	);

	set("exits", ([
		"start" : "/open/world2/anfernee/start/login",
	]));

	set("light",1);

	setup();
	replace_program(ROOM);
}
